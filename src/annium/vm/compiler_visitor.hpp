//  Sonia.one framework(c) by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "annium_vm.hpp"
#include "push_value_visitor.hpp"

#include "sonia/small_vector.hpp"
#include "sonia/utility/scope_exit.hpp"

#include "annium/semantic.hpp"
#include "annium/entities/functions/external_function_entity.hpp"

namespace annium::vm {

class compiler_visitor_base : public static_visitor<void>
{
protected:
    environment& environment_;
    internal_function_entity const* fn_context_;
    asm_builder_t::function_builder& fnbuilder_;
    mutable size_t fpheight_ = 0; // current frame pointer height (number of variables in current function)

    using breaks_t = small_vector<asm_builder_t::instruction_entry*, 4>;
    mutable small_vector<std::pair<asm_builder_t::label const*, breaks_t*>, 4> loop_stack_; // [{loop start, [loop brakes]}]

public:
    compiler_visitor_base(environment& e, asm_builder_t::function_builder & b, internal_function_entity const& ife)
        : environment_{ e }
        , fn_context_{ &ife }
        , fnbuilder_{ b }
    {}

    compiler_visitor_base(environment& e, asm_builder_t::function_builder & b)
        : environment_{ e }
        , fn_context_{ nullptr }
        , fnbuilder_{ b }
    {}

    inline void operator()(empty_t const&) const
    { /* noop, do nothing */ }

    void operator()(semantic::push_value const& pv) const
    {
        visit(push_value_visitor{ environment_, fnbuilder_ }, pv.value);
        ++fpheight_;
    }

    inline void operator()(semantic::push_special_value const& c) const
    {
        switch (c.kind) {
        case semantic::push_special_value::kind_type::stack_size:
            fnbuilder_.append_push_stsz();
            break;
        default:
            BOOST_ASSERT(!"unknown special value type");
        }
        ++fpheight_;
    }

    void operator()(semantic::push_local_variable const& pv) const
    {
        BOOST_ASSERT(fn_context_);
        intptr_t index = fn_context_->resolve_variable_index(pv.varid);
        fnbuilder_.append_fpush(index);
        ++fpheight_;
    }

    void operator()(semantic::push_by_offset const& pv) const
    {
        switch (pv.base) {
        case semantic::push_by_base::frame_bottom:
            fnbuilder_.append_fpush(pv.offset);
            break;
        case semantic::push_by_base::stack_top:
            fnbuilder_.append_pushr(pv.offset);
            break;
        default:
            BOOST_ASSERT(!"unknown push_by_offset base type");
        }
        ++fpheight_;
    }

    void operator()(semantic::dup_stack_top const&) const
    {
        fnbuilder_.append_dup();
        ++fpheight_;
    }

    void operator()(semantic::set_by_offset const& sv) const
    {
        fnbuilder_.append_setr(sv.offset);
        // for consuming set we will decrease fpheight_ by 1, but if it's not consuming at the moment
    }

    inline void operator()(semantic::truncate_values const& c) const
    {
        if (c.keep_back) {
            BOOST_ASSERT(c.keep_back == 1); // not implemented yet for arbitrary values
            fnbuilder_.append_collapse(c.count);
        } else {
            fnbuilder_.append_pop(c.count);
        }
        fpheight_ -= c.count;
    }

    void operator()(semantic::set_local_variable const& lv) const
    {
        BOOST_ASSERT(fn_context_);
        intptr_t index = fn_context_->resolve_variable_index(lv.varid);
        fnbuilder_.append_fset(index);
        // for consuming set we will decrease fpheight_ by 1, but if it's not consuming at the moment
    }

    void operator()(semantic::set_variable const& sv) const
    {
        string_view varname = *environment_.slregistry().resolve(sv.var.name);
        smart_blob strbr{ string_blob_result(varname) };
        strbr.allocate();
        fnbuilder_.append_push_pooled_const(std::move(strbr));
        fnbuilder_.append_ecall((size_t)virtual_stack_machine::builtin_fn::extern_variable_set);
        // for consuming set we will decrease fpheight_ by 1, but if it's not consuming at the moment
    }

    void operator()(semantic::push_variable const& pv) const
    {
        string_view varname = *environment_.slregistry().resolve(pv.var.name);
        smart_blob strbr{ string_blob_result(varname) };
        strbr.allocate();
        fnbuilder_.append_push_pooled_const(std::move(strbr));
        fnbuilder_.append_ecall((size_t)virtual_stack_machine::builtin_fn::extern_variable_get);
        ++fpheight_;
    }

    //inline void operator()(semantic::stack_frame_begin const&) const
    //{
    //    fnbuilder_.append_pushfp();
    //}

    //inline void operator()(semantic::stack_frame_end const&) const
    //{
    //    fnbuilder_.append_popfp();
    //}

    inline void operator()(semantic::indexs const& idxs) const
    {
        fnbuilder_.append_indexs(idxs.shift);
        // indexs is replacing => do not change fpheight_ here
    }

    void operator()(semantic::invoke_context_function const&) const;
    void operator()(semantic::invoke_function const&) const;

    void operator()(semantic::expression_span esp) const
    {
        while (esp) {
            apply(esp.front());
            esp.pop_front();
        }
    }

    void operator()(semantic::expression_list_t const& evec) const
    {
        for (auto const& e : evec) {
            //GLOBAL_LOG_INFO() << environment_.print(e);
            apply(e);
        }
    }

    void operator()(semantic::loop_scope_t const& s) const
    {
        if (s.continue_branch) {
            fnbuilder_.append_noop();
        }
        auto scope_begin_pos = fnbuilder_.make_label();

        if (s.continue_branch) {
            //fnbuilder_.append_noop();
            //auto jmpentry = fnbuilder_.current_entry();
            s.continue_branch.for_each([this](semantic::expression const& e) {
                apply(e);
            });
            
            auto loop_begin_pos = fnbuilder_.make_label();
            scope_begin_pos->ie->operation = asm_builder_t::op_t::jmp;
            scope_begin_pos->ie->operand = loop_begin_pos;
        }
        
        breaks_t breaks;
        loop_stack_.emplace_back(scope_begin_pos, std::addressof(breaks));
        SCOPE_EXIT([this] { loop_stack_.pop_back(); });

        s.branch.for_each([this](semantic::expression const& e) {
            apply(e);
        });
        auto scope_end_pos = fnbuilder_.make_label();

        // optimization: remove redundant breaks
        /*
        auto bit = breaks.rbegin(), ebit = breaks.rend();
        while (bit != ebit) {
            asm_builder_t::instruction_entry* pbi = *bit;
            if (pbi == scope_end_pos) {
                fnbuilder_.remove(pbi);
                scope_end_pos = fnbuilder_.current_entry(); // just update actual value
                breaks.erase(std::next(bit).base());
                bit = breaks.rbegin();
                ebit = breaks.rend();
            } else {
                ++bit;
            }
        }
        */

        for (asm_builder_t::instruction_entry* pbi : breaks) {
            pbi->operation = asm_builder_t::op_t::jmp;
            pbi->operand = scope_end_pos;
        }
    }

    void operator()(semantic::loop_continuer const&) const
    {
        if (loop_stack_.empty()) {
            throw exception("there is no enclosing loop for the cotinue statement");
        }
        fnbuilder_.append_jmp(loop_stack_.back().first);
    }

    void operator()(semantic::loop_breaker const&) const
    {
        if (loop_stack_.empty()) {
            throw exception("there is no enclosing loop for the break statement");
        }
        fnbuilder_.append_noop();
        loop_stack_.back().second->emplace_back(fnbuilder_.current_entry());
    }

    inline void operator()(semantic::conditional_t const& c) const
    {
        if (!c.false_branch && !c.true_branch) {
            fnbuilder_.append_pop();
            return;
        }
        fnbuilder_.append_noop();
        auto branch_pt = fnbuilder_.current_entry();
        fpheight_ -= 1; // condition value is consumed here
        if (!c.false_branch) { // only true branch
            //c.true_branch.for_each([this](semantic::expression const& e) {
            //    GLOBAL_LOG_INFO() << "true branch: " << environment_.print(e);
            //});
            c.true_branch.for_each([this](semantic::expression const& e) {
                apply(e);
            });
            auto branch_end_pt = fnbuilder_.make_label();
            branch_pt->operation = asm_builder_t::op_t::je;
            branch_pt->operand = branch_end_pt;
        } else if (!c.true_branch) {
            c.false_branch.for_each([this](semantic::expression const& e) {
                apply(e);
            });
            auto branch_end_pt = fnbuilder_.make_label();
            branch_pt->operation = asm_builder_t::op_t::jne;
            branch_pt->operand = branch_end_pt;
        } else {
            c.true_branch.for_each([this](semantic::expression const& e) {
                apply(e);
            });
            
            if (!c.true_branch_finished) {
                fnbuilder_.append_noop();
            }
            auto true_branch_end_pt = fnbuilder_.make_label();
            c.false_branch.for_each([this](semantic::expression const& e) {
                apply(e);
            });
            
            auto branch_end_pt = fnbuilder_.make_label();
            branch_pt->operation = asm_builder_t::op_t::je;
            branch_pt->operand = true_branch_end_pt;
            if (!c.true_branch_finished) {
                true_branch_end_pt->ie->operation = asm_builder_t::op_t::jmp;
                true_branch_end_pt->ie->operand = branch_end_pt;
            }
        }
    }

    inline void operator()(semantic::switch_t const& c) const
    {
        if (c.branches.empty()) {
            fnbuilder_.append_pop(); // pop branch index value
            return;
        }
        small_vector<asm_builder_t::label const*, 16> branch_exit_points;

        // each branch should take into account that there is a branch index value on the stack top
        
        // first branch does not need cmp, so we handle it separately
        auto branches = std::span{ c.branches };
        auto first_branch = branches.front(); branches = branches.subspan(1);

        fnbuilder_.append_dup(); // duplicate branch index value because first branch does not need cmp
        fnbuilder_.append_op(asm_builder_t::op_t::jne);
        auto branch_pt = fnbuilder_.current_entry();
        //fnbuilder_.append_pop(); // pop branch index value
        first_branch.for_each([this](semantic::expression const& e) {
            apply(e);
        });
        if (!branches.empty()) {
            fnbuilder_.append_noop(); // exit jump will be here
        }
        branch_exit_points.push_back(fnbuilder_.make_label()); // first_branch_end_pt
        branch_pt->operand = branch_exit_points.back();

        size_t branch_index = 1;
        for (auto const& br : branches) {
            //if (branch_index != 1) fnbuilder_.append_pop(); // pop previous branch compare result
            
            fnbuilder_.append_push_pooled_const(ui64_blob_result(branch_index)); // state after: fpheight + 1
            fnbuilder_.append_op(asm_builder_t::op_t::cmp); // state after: fpheight + 1
            fnbuilder_.append_op(asm_builder_t::op_t::jne); // state after: fpheight
            auto branch_pt = fnbuilder_.current_entry();
            //fnbuilder_.append_pop(); // pop condition value
            br.for_each([this](semantic::expression const& e) {
                apply(e);
            });
            if (&br != &branches.back()) {
                fnbuilder_.append_noop(); // exit jump will be here
            }
            branch_exit_points.push_back(fnbuilder_.make_label());
            branch_pt->operand = branch_exit_points.back();
            ++branch_index;
        }
        // set jumps to exit points for all branch_exit_points except the last one
        auto exit_pt = branch_exit_points.back();
        branch_exit_points.pop_back();
        for (auto bep : branch_exit_points) {
            bep->ie->operation = asm_builder_t::op_t::jmp;
            bep->ie->operand = exit_pt;
        }
    }

    virtual void apply(semantic::expression const&) const = 0;
};

template <typename DerivedT>
class compiler_visitor_generic : public compiler_visitor_base
{
    
public:
    using generic_base_t = compiler_visitor_generic;
    using compiler_visitor_base::compiler_visitor_base;

    using compiler_visitor_base::operator();

    void apply(semantic::expression const& e) const override
    {
        //GLOBAL_LOG_INFO() << "--- " << environment_.print(e);
        visit(derived(), e);
    }

protected:
    inline DerivedT const& derived() const noexcept { return static_cast<DerivedT const&>(*this); }
};

class inline_compiler_visitor : public compiler_visitor_generic<inline_compiler_visitor>
{
    mutable small_vector<asm_builder_t::instruction_entry*, 4> rpositions_;

public:
    using generic_base_t::generic_base_t;
    
    using generic_base_t::operator();

    inline void operator()(semantic::return_statement const& rst) const
    {
        //rst.cast_expressions.for_each([this](semantic::expression const& e) {
        //    //GLOBAL_LOG_INFO() << environment_.print(e);
        //    visit(*this, e);
        //});
        rst.scope_deconstruction.for_each([this](semantic::expression const& e) {
            //GLOBAL_LOG_INFO() << environment_.print(e);
            visit(*this, e);
        });
        // todo: trancate temporaries
        fnbuilder_.append_noop();
        rpositions_.push_back(fnbuilder_.current_entry());
    }

    void finalize()
    {
        auto fin_pos = fnbuilder_.make_label();
        while (!rpositions_.empty() && rpositions_.back() == fin_pos->ie) { // inline fn returns right at the code end
            fnbuilder_.remove(rpositions_.back()); // fin_pos label is moved here
            rpositions_.pop_back();
            // fin_pos is updated by fnbuilder_.remove call
        }

        for (auto rpos : rpositions_) {
            rpos->operation = asm_builder_t::op_t::jmp;
            rpos->operand = fin_pos;
        }
    }

    template <typename T>
    void operator()(T const& e) const
    {
        (void)e; // suppress unused warning
        THROW_NOT_IMPLEMENTED_ERROR();
    }
};

class compiler_visitor : public compiler_visitor_generic<compiler_visitor>
{
public:
    compiler_visitor(environment& e, asm_builder_t::function_builder& b, internal_function_entity const& ife)
        : generic_base_t{ e, b, ife }
    {
        if (fn_context_->need_framepointer()) {
            // for accessing function arguments and local variables by zero-based index
            fnbuilder_.append_pushfp();
        }
    }

    using generic_base_t::generic_base_t;

    using generic_base_t::operator();

    inline void operator()(semantic::return_statement const& rst) const
    {
        //GLOBAL_LOG_INFO() << environment_.print(rst.result);
        //rst.cast_expressions.for_each([this](semantic::expression const& e) {
        //    //GLOBAL_LOG_INFO() << environment_.print(e);
        //    visit(*this, e);
        //});
        rst.scope_deconstruction.for_each([this](semantic::expression const& e) {
            //GLOBAL_LOG_INFO() << environment_.print(e);
            visit(*this, e);
        });
        if (fn_context_->need_framepointer()) {
            fnbuilder_.append_popfp();
        }

        fnbuilder_.append_ret();
    }


#if 0
    inline void operator()(semantic::conditional_t const& c) const
    {
        THROW_NOT_IMPLEMENTED_ERROR("compiler_visitor conditional_t");

        size_t branch_pt = environment_.bvm().get_ip();
        if (c.false_branch.empty() && c.true_branch.empty()) return;
        if (c.false_branch.empty()) {
            for (auto const& e : c.true_branch) {
                apply_visitor(*this, e);
            }
            size_t branch_end_pt = environment_.bvm().get_ip();
            environment_.bvm().append_jfx(branch_end_pt - branch_pt);
            environment_.bvm().swap_code_blocks(branch_pt, branch_end_pt);
        } else if (c.true_branch.empty()) {
            for (auto const& e : c.false_branch) {
                apply_visitor(*this, e);
            }
            size_t branch_end_pt = environment_.bvm().get_ip();
            environment_.bvm().append_jtx(branch_end_pt - branch_pt);
            environment_.bvm().swap_code_blocks(branch_pt, branch_end_pt);
        } else {
            for (auto const& e : c.true_branch) {
                apply_visitor(*this, e);
            }
            size_t true_branch_end_pt = environment_.bvm().get_ip();
            for (auto const& e : c.false_branch) {
                apply_visitor(*this, e);
            }
            size_t false_branch_end_pt = environment_.bvm().get_ip();
            environment_.bvm().append_jmpx(false_branch_end_pt - true_branch_end_pt);
            size_t jmpxsz = environment_.bvm().get_ip() - false_branch_end_pt;
            environment_.bvm().swap_code_blocks(true_branch_end_pt, false_branch_end_pt);

            environment_.bvm().append_jfx(true_branch_end_pt + jmpxsz - branch_pt);
            environment_.bvm().swap_code_blocks(branch_pt, true_branch_end_pt + jmpxsz);
        }

    }
#endif


    inline void operator()(semantic::not_empty_condition_t const& /*n*/) const
    {
        THROW_NOT_IMPLEMENTED_ERROR("compiler_visitor return_statement");
#if 0
        size_t branch_pt = environment_.bvm().get_ip();
        environment_.bvm().append_pop(1); // remove boolean value false = is_nil
        for (auto const& e : n.branch) {
            apply_visitor(*this, e);
        }
        size_t not_nil_branch_end_pt = environment_.bvm().get_ip();

        environment_.bvm().append_pop(1); // remove boolean value true = is_nil
        environment_.bvm().append_jmpx(not_nil_branch_end_pt - branch_pt);
        size_t nil_branch_end_pt = environment_.bvm().get_ip();
        environment_.bvm().swap_code_blocks(branch_pt, not_nil_branch_end_pt);
        
        bvm().append_ecall(virtual_stack_machine::builtin_fn::is_nil);
        environment_.bvm().append_jfx(nil_branch_end_pt - not_nil_branch_end_pt);
        environment_.bvm().swap_code_blocks(branch_pt, nil_branch_end_pt);

        //bvm().append_ecall(virtual_stack_machine::builtin_fn::is_nil);
        //environment_.bvm().append_jtx(branch_end_pt - branch_pt);
        //environment_.bvm().swap_code_blocks(branch_pt, branch_end_pt);
#endif
    }

    template <typename T>
    void operator()(T const& e) const
    {
        (void)e; // suppress unused warning
        THROW_NOT_IMPLEMENTED_ERROR();
    }
};

void compiler_visitor_base::operator()(semantic::invoke_context_function const&) const
{
    fnbuilder_.append_indexc();
    fnbuilder_.append_callp();
}

void compiler_visitor_base::operator()(semantic::invoke_function const& invf) const
{
    entity const& e = environment_.eregistry_get(invf.fn);
    if (auto fe = dynamic_cast<internal_function_entity const*>(&e); fe) {
        BOOST_ASSERT(!fe->is_provision()); // provision functions cannot be called
        BOOST_ASSERT(fe->is_built()); // should be built already
        if (!fe->is_empty()) {
            if (fe->is_inline()) {
                // to do: circular dependency check?
                //GLOBAL_LOG_INFO() << "entering inline function: " << environment_.print(invf.fn);
                BOOST_ASSERT(fe->is_built());
                inline_compiler_visitor ivis{ environment_, fnbuilder_, *fe };
                
                if (fe->need_framepointer()) {
                    fnbuilder_.append_pushfp();
                }
                fe->body.for_each([this, &ivis](semantic::expression const& e) {
                    //GLOBAL_LOG_INFO() << environment_.print(e);
                    visit(ivis, e);
                });
                ivis.finalize();
                if (fe->need_framepointer()) {
                    fnbuilder_.append_popfp();
                }
                //GLOBAL_LOG_INFO() << "leaving inline function: " << environment_.print(invf.fn);
            } else {
                vmasm::fn_identity fnident{ fe->id };
                fnbuilder_.append_call(fnident);
            }
        } // else just noop, empty function
    } else if (auto efe = dynamic_cast<external_function_entity const*>(&e); efe) {
        fnbuilder_.append_ecall(efe->extfnid());
    } else {
        THROW_NOT_IMPLEMENTED_ERROR("compiler_visitor invoke_function");
    }
}

}
