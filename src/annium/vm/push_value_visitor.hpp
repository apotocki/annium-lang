//  Sonia.one framework(c) by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/variant.hpp"

#include "annium_vm.hpp"
#include "../semantic.hpp"

namespace annium::vm {

#if 0
class materialize_value_visitor : public static_visitor<void>, public entity_visitor
{
    environment& environment_;
    mutable blob_result result;

public:
    inline explicit materialize_value_visitor(environment& e) noexcept
        : environment_{ e }
    {}

    inline void operator()(null_t const&) const { result = nil_blob_result(); }

    inline void operator()(bool bval) const { result = bool_blob_result(bval); }

    inline void operator()(small_string const& sval) const
    {
        smart_blob strbr{ string_blob_result(sval) };
        strbr.allocate();
        result = strbr.detach();
    }

    inline void operator()(uint64_t value) const { result = ui64_blob_result(value); }

    inline void operator()(mp::integer const& ival) const { result = bigint_blob_result(ival); }

    inline void operator()(mp::decimal const& dval) const { result = decimal_blob_result(dval); }

    inline blob_result operator()(entity_identifier const& eid) const
    {
        entity const& e = environment_.eregistry_get(eid);
        if (e.id != environment_.get(builtin_eid::void_)) {
            e.visit(*this);
            return result;
        } else {
            return nil_blob_result();
        }
    }

    void operator()(string_literal_entity const& sle) const override
    {
        this->operator()(sle.value());
    }

    void operator()(bool_literal_entity const& ble) const override
    {
        this->operator()(ble.value());
    }

    void operator()(integer_literal_entity const& ile) const override
    {
        this->operator()(ile.value());
    }

    void operator()(decimal_literal_entity const& dle) const override
    {
        this->operator()(dle.value());
    }

    void operator()(identifier_entity const& ie) const override
    {
        this->operator()(ie.value());
    }

    void operator()(qname_identifier_entity const& ie) const override
    {
        this->operator()(ie.value());
    }
};
#endif

class push_value_visitor : public static_visitor<void>, public entity_visitor
{
    environment& environment_;
    asm_builder_t::function_builder& fnbuilder_;

public:
    explicit push_value_visitor(environment& e, asm_builder_t::function_builder& b)
        : environment_{ e }, fnbuilder_{ b }
    {}

#if 0
    void operator()(annium::function_value const& dval) const
    {
        THROW_NOT_IMPLEMENTED_ERROR("push_value_visitor function_value");
#if 0
        if (auto eptr = environment_.eregistry().find(dval.mangled_name); eptr) {
            if (auto fe = dynamic_pointer_cast<annium::function_entity>(eptr); fe) {
                if (!fe->is_defined()) {
                    size_t pos = bvm().append_static(smart_blob{}); // just reserve
                    fe->set_static_variable_index(pos);
                }
                if (fe->is_static_variable_index()) {
                    bvm().append_pushs(fe->get_address());
                    bvm().append_push_static_const(bool_blob_result(true));
                } else {
                    bvm().append_push_static_const(ui64_blob_result(fe->get_address()));
                    bvm().append_push_static_const(bool_blob_result(false));
                }
                
                if (!fe->captured_variables.empty()) {
                    for (auto const& pair : fe->captured_variables) {
                        bvm().append_fpushi(std::get<0>(pair)->index());
                        bvm().append_ecall(virtual_stack_machine::builtin_fn::referify);
                        bvm().append_fpush(std::get<0>(pair)->index());
                    }
                    if (fe->captured_variables.size() > 1) {
                        //size_t idx = bvm().push_on_stack(ui64_blob_result(fe->captured_variables.size()));
                        bvm().append_push_static_const(ui64_blob_result(fe->captured_variables.size()));
                        bvm().append_ecall(virtual_stack_machine::builtin_fn::arrayify);

                        //bvm().push_on_stack_and_push(ui64_blob_result(fe->captured_variables.size()));
                        //bvm().append_builtin(annium::builtin_type::arrayify);
                    }
                } else {
                    bvm().append_push_static_const(nil_blob_result());
                }
                
                auto nmstr = environment_.print(dval.mangled_name);
                smart_blob strbr{ string_blob_result(nmstr) };
                strbr.allocate();
                bvm().append_push_static_const(std::move(strbr));
                bvm().append_push_static_const(i64_blob_result((fe->signature().parameters_count() + 1) * (fe->is_void() ? -1 : 1)));
                bvm().append_ecall(virtual_stack_machine::builtin_fn::function_constructor);
                
                //return bvm_.push_on_stack(smart_blob{ object_blob_result<function_invoker>(fe.get()) });
            } else {
                THROW_NOT_IMPLEMENTED_ERROR("unknown entity found, unresolved function call name: '%1%'"_fmt % environment_.print(dval.mangled_name));
            }
        } else {
            throw exception("unresolved name: '%1%'"_fmt % environment_.print(dval.mangled_name));
        }
#endif
    }
#endif

    void operator()(entity_identifier const& eid) const
    {
        entity const& e = environment_.eregistry_get(eid);
        if (e.id != environment_.get(builtin_eid::void_)) {
            e.visit(*this);
        } else {
            fnbuilder_.append_push_pooled_const(smart_blob{});
        }
    }

    void operator()(entity_ptr const& eptr) const
    {
        eptr->visit(*this);
    }

    void operator()(entity const& ent) const override
    {
        entity_signature const* psig = ent.signature();
        //if (psig && psig->name == environment_.get(builtin_qnid::metaobject) && psig->result) {
        //    entity const& tpent = environment_.eregistry_get(psig->result->entity_id());
        //    entity_signature const* ptpsig = tpent.signature();
        //    if (ptpsig) {
        //        push_metaobject(*psig, *ptpsig);
        //        return;
        //    }
        //}
        fnbuilder_.append_push_pooled_const(smart_blob{});
    }

    //void push_metaobject(entity_signature const& e, entity_signature const& et) const
    //{
    //    if (et.name == environment_.get(builtin_qnid::array)) {
    //        for (auto const& fd : e.fields()) {
    //            this->operator()(fd.entity_id());
    //        }
    //        fnbuilder_.append_push_pooled_const(smart_blob{ ui64_blob_result(e.fields().size()) });

    //        external_function_entity const& efent = dynamic_cast<external_function_entity const&>(environment_.eregistry_get(environment_.get(builtin_eid::arrayify)));
    //        fnbuilder_.append_ecall(efent.extfnid());
    //    } else if (et.name == environment_.get(builtin_qnid::union_)) {
    //        this->operator()(e.find_field(0)->entity_id());
    //    } else {
    //        fnbuilder_.append_push_pooled_const(smart_blob{});
    //    }
    //}

    template <typename T>
    void operator()(T const& e) const
    {
        (void)e; // silence unused warning
        THROW_NOT_IMPLEMENTED_ERROR();
    }

    void operator()(smart_blob const& bl) const
    {
        fnbuilder_.append_push_pooled_const(smart_blob{ bl });
    }

    void operator()(generic_literal_entity const& sle) const override
    {
        fnbuilder_.append_push_pooled_const(smart_blob{ sle.value() });
    }

    void operator()(identifier_entity const& ie) const override
    {
        this->operator()(ie.value());
    }

    void operator()(functional_identifier_entity const& ie) const override
    {
        this->operator()(ie.value());
    }

    void operator()(qname_entity const& qne) const override
    {
        this->operator()(qne.value());
    }

    void operator()(empty_entity const& /*ee*/) const override
    {
#if 0
        entity const& type_ent = get_entity(environment_, ee.get_type());
        if (auto psig = type_ent.signature(); psig && psig->name == environment_.get(builtin_qnid::tuple)) {
            // materialize tuple
            small_vector<blob_result, 16> flds;
            SCOPE_EXCEPTIONAL_EXIT([&flds]() {
                for (auto& f : flds) blob_result_unpin(&f);
            });
            for (auto const& fd : psig->fields()) {
                BOOST_ASSERT(fd.is_const());
                flds.emplace_back(materialize_value_visitor{ environment_ }(fd.entity_id()));
            }
            smart_blob r{ array_blob_result(span{ flds.data(), flds.size() }) };
            r.allocate();
            fnbuilder_.append_push_pooled_const(std::move(r));
        }
#endif
        fnbuilder_.append_push_pooled_const(smart_blob{}); // === nil
    }

    //void operator()(functional_entity const&) const override
    //{
    //    THROW_NOT_IMPLEMENTED_ERROR();
    //}

    void operator()(external_function_entity const&) const override
    {
        THROW_NOT_IMPLEMENTED_ERROR();
    }

    void operator()(internal_function_entity const&) const override
    {
        THROW_NOT_IMPLEMENTED_ERROR();
    }

    void operator()(extern_variable_entity const& ve) const override
    {
        string_view varname = environment_.as_string(environment_.fregistry_resolve(ve.name).name().back());
        smart_blob strbr{ string_blob_result(varname) };
        strbr.allocate();
        fnbuilder_.append_push_pooled_const(std::move(strbr));
        fnbuilder_.append_ecall((size_t)virtual_stack_machine::builtin_fn::extern_variable_get);
#if 0
        string_view varname = environment_.as_string(environment_.qnregistry().resolve(pv.entity->name()).back());
        smart_blob strbr{ string_blob_result(varname) };
        strbr.allocate();
        bvm().append_push_static_const(std::move(strbr));
        bvm().append_ecall(virtual_stack_machine::builtin_fn::extern_variable_get);
#endif
    }
};

}
