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

    using breaks_t = small_vector<asm_builder_t::instruction_entry*, 4>;
    mutable small_vector<std::pair<asm_builder_t::instruction_entry*, breaks_t*>, 4> loop_stack_; // [{loop start, [loop brakes]}]

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
    }

    void operator()(semantic::push_local_variable const& pv) const
    {
        BOOST_ASSERT(fn_context_);
        intptr_t index = fn_context_->resolve_variable_index(pv.varid);
        fnbuilder_.append_fpush(index);
    }

    void operator()(semantic::push_by_offset const& pv) const
    {
        fnbuilder_.append_pushr(pv.offset);
    }

    void operator()(semantic::set_by_offset const& sv) const
    {
        fnbuilder_.append_setr(sv.offset);
    }

    inline void operator()(semantic::truncate_values const& c) const
    {
        if (c.keep_back) {
            BOOST_ASSERT(c.keep_back == 1); // not implemented yet for arbitrary values
            fnbuilder_.append_collapse(c.count);
        } else {
            fnbuilder_.append_pop(c.count);
        }
    }

    void operator()(semantic::set_local_variable const& lv) const
    {
        BOOST_ASSERT(fn_context_);
        intptr_t index = fn_context_->resolve_variable_index(lv.varid);
        fnbuilder_.append_fset(index);
    }

    void operator()(semantic::set_variable const& sv) const
    {
        string_view varname = *environment_.slregistry().resolve(sv.var.name);
        smart_blob strbr{ string_blob_result(varname) };
        strbr.allocate();
        fnbuilder_.append_push_pooled_const(std::move(strbr));
        fnbuilder_.append_ecall((size_t)virtual_stack_machine::builtin_fn::extern_variable_set);
    }

    void operator()(semantic::push_variable const& pv) const
    {
        string_view varname = *environment_.slregistry().resolve(pv.var.name);
        smart_blob strbr{ string_blob_result(varname) };
        strbr.allocate();
        fnbuilder_.append_push_pooled_const(std::move(strbr));
        fnbuilder_.append_ecall((size_t)virtual_stack_machine::builtin_fn::extern_variable_get);
    }

    inline void operator()(semantic::stack_frame_begin const&) const
    {
        fnbuilder_.append_pushfp();
    }

    inline void operator()(semantic::stack_frame_end const&) const
    {
        fnbuilder_.append_popfp();
    }

    inline void operator()(semantic::indexs const& idxs) const
    {
        fnbuilder_.append_indexs(idxs.shift);
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
            scope_begin_pos->operation = asm_builder_t::op_t::jmp;
            scope_begin_pos->operand = loop_begin_pos;
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
        if (!c.false_branch) {
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
                true_branch_end_pt->operation = asm_builder_t::op_t::jmp;
                true_branch_end_pt->operand = branch_end_pt;
            }
        }
    }

    inline void operator()(semantic::switch_t const& c) const
    {
        if (c.branches.empty()) {
            fnbuilder_.append_pop(); // pop branch index value
            return;
        }
        small_vector<asm_builder_t::instruction_entry*, 16> branch_exit_points;

        // each branch should take into account that there is a branch index value on the stack top
        
        // first branch does not need cmp, so we handle it separately
        auto branches = std::span{ c.branches };
        auto first_branch = branches.front(); branches = branches.subspan(1);

        fnbuilder_.append_op(asm_builder_t::op_t::jne);
        auto branch_pt = fnbuilder_.current_entry();
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
            if (branch_index != 1) fnbuilder_.append_pop(); // pop previous branch compare result
            
            fnbuilder_.append_push_pooled_const(ui64_blob_result(branch_index));
            fnbuilder_.append_op(asm_builder_t::op_t::cmp);
            fnbuilder_.append_op(asm_builder_t::op_t::jne);
            auto branch_pt = fnbuilder_.current_entry();
            fnbuilder_.append_pop(); // pop condition value
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
            bep->operation = asm_builder_t::op_t::jmp;
            bep->operand = exit_pt;
        }



        //THROW_NOT_IMPLEMENTED_ERROR("compiler_visitor switch_t");
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
        rst.result.for_each([this](semantic::expression const& e) {
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
        while (!rpositions_.empty() && rpositions_.back() == fin_pos) { // inline fn returns right at the code end
            fnbuilder_.remove(rpositions_.back()); // fin_pos label is moved here
            rpositions_.pop_back();
            fin_pos = fnbuilder_.current_entry(); // just update actual value
        }
        if (rpositions_.empty()) {
            fnbuilder_.remove_label(fin_pos);
        } else {
            for (auto rpos : rpositions_) {
                rpos->operation = asm_builder_t::op_t::jmp;
                rpos->operand = fin_pos;
            }
        }
        size_t param_count = fn_context_->parameter_count(); // including captured_variables
        BOOST_ASSERT(fn_context_->result.entity_id());
        if (fn_context_->result.entity_id() != environment_.get(builtin_eid::void_)) {
            fnbuilder_.append_fset(-static_cast<intptr_t>(param_count));
            fnbuilder_.append_truncatefp(-static_cast<intptr_t>(param_count) + 1);
        } else {
            fnbuilder_.append_truncatefp(-static_cast<intptr_t>(param_count));
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
    mutable optional<asm_builder_t::instruction_entry*> local_return_position;

    using generic_base_t::generic_base_t;

    using generic_base_t::operator();

    inline void operator()(semantic::return_statement const& rst) const
    {
        rst.result.for_each([this](semantic::expression const& e) {
            //GLOBAL_LOG_INFO() << environment_.print(e);
            visit(*this, e);
        });
        if (local_return_position) {
            fnbuilder_.append_jmp(*local_return_position);
            return;
        } else if (fn_context_) {
            local_return_position = fnbuilder_.make_label();
            size_t param_count = fn_context_->arg_count() + fn_context_->captured_var_count();
            //size_t param_count = fn_context_->parameter_count(); // including captured_variables
            BOOST_ASSERT(fn_context_->result.entity_id());
            if (fn_context_->result.entity_id() != environment_.get(builtin_eid::void_)) {
                fnbuilder_.append_fset(-static_cast<intptr_t>(param_count));
                fnbuilder_.append_truncatefp(-static_cast<intptr_t>(param_count) + 1);
            } else if (param_count) {
                fnbuilder_.append_truncatefp(-static_cast<intptr_t>(param_count));
            }
            //if (param_count) {
                fnbuilder_.append_popfp();
            //}
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
                fnbuilder_.append_pushfp();
                fe->body.for_each([this, &ivis](semantic::expression const& e) {
                    //GLOBAL_LOG_INFO() << environment_.print(e);
                    visit(ivis, e);
                });
                ivis.finalize();
                fnbuilder_.append_popfp();
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
#if 0
    /*
    if (auto optecall = bvm_.get_ecall(invf.function_entity_name); optecall) {
        bvm_.append_ecall(*optecall);
    }
    if (invf.function_entity_name == environment_.builtin(annium::builtin_type::arrayify)) {
        bvm_.append_builtin(annium::builtin_type::arrayify);
    } else if (invf.function_entity_name == environment_.builtin(annium::builtin_type::print_string)) {
        bvm_.append_builtin(annium::builtin_type::print_string);
    } else if (invf.function_entity_name == environment_.builtin(annium::builtin_type::tostring)) {
        bvm_.append_builtin(annium::builtin_type::tostring);
    }
    else 
    */
    if (auto eptr = environment_.eregistry().find(invf.varname); eptr) {
        // to do: visitor
        if (auto pefe = dynamic_pointer_cast<external_function_entity>(eptr); pefe) {
            bvm().append_ecall(pefe->fn_index);
        }
        //else if (auto pte = dynamic_pointer_cast<type_entity>(eptr); pte) {
        //    bvm().append_ecall(virtual_stack_machine::builtin_fn::extern_object_constructor);
        //}
        else if (auto fe = dynamic_pointer_cast<function_entity>(eptr); fe) {
            if (fe->is_inline()) {
                for (auto const& e : fe->body) {
                    apply_visitor(*this, e);
                }
            } else {
                bvm().append_push_static_const(i64_blob_result((fe->signature().parameters_count() + 1) * (fe->is_void() ? -1 : 1)));
                bvm().append_fpush(fe->index());
                bvm().append_callp();
            }
            //bvm_.append_builtin(annium::builtin_type::call_function_object);
            /*
            // assigned captured variables (if exist)
            for (auto const& pair : fe->captured_variables) {
                // refiry
                bvm_.append_freferify(std::get<0>(pair)->index());
                bvm_.append_fpush(std::get<0>(pair)->index());
            }
            //
            if (!fe->is_defined()) {
                size_t pos = bvm_.push_on_stack(smart_blob{}); // just reserve
                fe->set_variable_index(pos);
            }
            if (fe->is_inline()) {
                for (auto const& e : fe->body) {
                    apply_visitor(*this, e);
                }
            } else if (fe->is_variable_index()) {
                bvm_.append_push(fe->get_address());
                bvm_.appned_callp();
            } else {
                bvm_.append_call(fe->get_address());
            }
            */
            //THROW_NOT_IMPLEMENTED_ERROR("unimplemented function call name: '%1%'"_fmt % environment_.print(invf.entity));
        } else {
            THROW_NOT_IMPLEMENTED_ERROR("unknown entity found, unresolved function call name: '%1%'"_fmt % environment_.print(invf.varname));
        }
    } else {
        throw exception("unresolved name: '%1%'"_fmt % environment_.print(invf.varname));
    }
#endif
}

}
