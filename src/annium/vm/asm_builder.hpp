//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#pragma once

#include "sonia/utility/automatic_polymorphic.hpp"

namespace annium::vmasm {

class function_identity : public sonia::polymorphic_clonable_and_movable
{
public:
    virtual bool equal(function_identity const& rhs) const noexcept = 0;
    virtual size_t hash() const noexcept = 0;

    inline friend bool operator==(function_identity const& l, function_identity const& r) noexcept { return l.equal(r); }
    inline friend size_t hash_value(function_identity const& v) noexcept { return v.hash(); }
};

template <typename IDT>
class fn_identity : public function_identity
{
    IDT id_;

public:
    inline explicit fn_identity(IDT id) noexcept : id_{ std::move(id) } {}

    SONIA_POLYMORPHIC_CLONABLE_MOVABLE_IMPL(fn_identity)

    bool equal(function_identity const& rhs) const noexcept override
    {
        if (auto *pfnid = dynamic_cast<fn_identity const*>(&rhs); pfnid) {
            return id_ == pfnid->id_;
        }
        return false;
    }

    size_t hash() const noexcept override { return hash_value(id_); }
    //inline IDT id() const noexcept { return id_; }
};

class generic_asm_builder
{
public:
    virtual ~generic_asm_builder() = default;

    //virtual function_descriptor& resolve_function(function_identity const&) = 0;
    
    //virtual void begin_function(function_identity const& fid) = 0;
    //virtual void end_function() = 0;
    //virtual void emit_instruction(std::string_view instr) = 0;
};

}
