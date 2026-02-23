//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "annium/environment.hpp"
#include "annium/library/library.hpp"

#include "annium/parser.hpp"
#include "annium/ast/fn_compiler_context.hpp"
#include "annium/ast/declaration_visitor.hpp"
#include "annium/ast/base_expression_visitor.hpp"

#include "annium/entities/ellipsis/ellipsis_pattern.hpp"
#include "annium/entities/functions/external_function_entity.hpp"
#include "annium/entities/functions/internal_function_entity.hpp"

#include "annium/functional/external_fn_pattern.hpp"
#include "annium/functional/general/error_pattern.hpp"
#include "annium/functional/general/assert_pattern.hpp"
#include "annium/functional/general/void_implicit_cast_pattern.hpp"
#include "annium/functional/general/any_implicit_cast_pattern.hpp"
#include "annium/functional/general/runtime_cast_pattern.hpp"
#include "annium/functional/general/deref_pattern.hpp"
#include "annium/functional/general/equal_pattern.hpp"
#include "annium/functional/general/typeof_pattern.hpp"
#include "annium/functional/general/to_string_pattern.hpp"
#include "annium/functional/general/logical_not_pattern.hpp"
#include "annium/functional/general/is_const_pattern.hpp"
#include "annium/functional/general/create_identifier_pattern.hpp"

#include "annium/entities/literals/literal_entity.hpp"
#include "annium/entities/literals/numeric_implicit_cast_pattern.hpp"
#include "annium/entities/literals/numeric_literal_implicit_cast_pattern.hpp"
#include "annium/entities/literals/numeric_literal_equal_pattern.hpp"
#include "annium/entities/literals/numeric_literal_unary_minus_pattern.hpp"

#include "annium/entities/literals/string/string_implicit_cast_pattern.hpp"
#include "annium/entities/literals/string/string_concat_pattern.hpp"
#include "annium/entities/literals/string/string_empty_pattern.hpp"

#include "annium/entities/callables/to_callable_implicit_cast_pattern.hpp"

#include "annium/entities/union/union_bit_or_pattern.hpp"
#include "annium/entities/union/union_apply_pattern.hpp"
#include "annium/entities/union/to_union_implicit_cast_pattern.hpp"

#include "annium/entities/tuple/tuple_pattern.hpp"
#include "annium/entities/tuple/tuple_make_pattern.hpp"
#include "annium/entities/tuple/tuple_size_pattern.hpp"
#include "annium/entities/tuple/tuple_get_pattern.hpp"
#include "annium/entities/tuple/tuple_typename_get_pattern.hpp"
#include "annium/entities/tuple/tuple_set_pattern.hpp"
#include "annium/entities/tuple/tuple_empty_pattern.hpp"
#include "annium/entities/tuple/tuple_head_pattern.hpp"
#include "annium/entities/tuple/tuple_tail_pattern.hpp"
#include "annium/entities/tuple/tuple_implicit_cast_pattern.hpp"
#include "annium/entities/tuple/tuple_equal_pattern.hpp"
#include "annium/entities/tuple/tuple_project_get_pattern.hpp"
#include "annium/entities/tuple/tuple_project_size_pattern.hpp"

#include "annium/entities/struct/struct_new_pattern.hpp"
#include "annium/entities/struct/struct_get_pattern.hpp"
//#include "entities/struct/struct_implicit_cast_pattern.hpp"
#include "annium/entities/struct/struct_init_pattern.hpp"
#include "annium/entities/struct/struct_set_pattern.hpp"
#include "annium/entities/struct/is_struct_pattern.hpp"
#include "annium/entities/struct/tuple_of_pattern.hpp"

#include "annium/entities/enum/enum_implicit_cast_pattern.hpp"
#include "annium/entities/enum/enum_implicit_runtime_cast_pattern.hpp"
#include "annium/entities/enum/enum_get_pattern.hpp"
#include "annium/entities/enum/enum_equal_pattern.hpp"
#include "annium/entities/enum/enum_to_string_pattern.hpp"
#include "annium/entities/enum/enum_to_integer_pattern.hpp"

#include "annium/entities/array/array_implicit_cast_pattern.hpp"
#include "annium/entities/array/array_from_iterator_make_pattern.hpp"

#include "annium/entities/fixed_array/fixed_array_make_pattern.hpp"
#include "annium/entities/fixed_array/fixed_array_head_pattern.hpp"
#include "annium/entities/fixed_array/fixed_array_tail_pattern.hpp"
#include "annium/entities/fixed_array/fixed_array_get_pattern.hpp"
#include "annium/entities/fixed_array/fixed_array_elements_implicit_cast_pattern.hpp"

#include "annium/semantic/expression_printer.hpp"
#include "annium/auxiliary.hpp"

#include "annium/ast/arena.hpp"

#include "annium/vm/vmasm_builder.hpp"
namespace annium { using asm_builder_t = vmasm::builder<vm::context>; }
#include "annium/vm/compiler_visitor.hpp"

#ifdef SONIA_LANG_DEBUG
#   define LANG_DEBUG_THIS this
#else
#   define LANG_DEBUG_THIS
#endif

namespace annium {

class file_resource : public ast_resource
{
    fs::path path_;

public:
    inline file_resource(fs::path p) noexcept
        : ast_resource{ std::string{} }
        , path_{ std::move(p) }
    {
        std::vector<char> src;
        std::ifstream file{ path_.string().c_str(), std::ios::binary };
        std::copy(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>{}, std::back_inserter(src));
        src_ = std::move(src);
    }

    std::ostream& print_description(std::ostream& s) const override
    {
        auto u8str = path_.generic_u8string();
        return s << string_view{ reinterpret_cast<char const*>(u8str.data()), u8str.size() };
    }

    inline fs::path const& path() const noexcept { return path_; }

    //void prepare_lines() const override
    //{
    //    if (get_source().empty()) {
    //        // Read file content if not already done
    //        try {
    //            std::vector<char> src;
    //            std::ifstream file{ path_.string().c_str(), std::ios::binary };
    //            std::copy(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>{}, std::back_inserter(src));
    //            src_ = std::move(src);
    //        } catch (std::exception const& e) {
    //            src_ = ("<failed to read file '%1%': %2%?"_fmt % path_ % e.what()).str();
    //            return;
    //        }
    //    }
    //    ast_resource::prepare_lines();
    //}

    size_t hash() const noexcept override
    {
        return std::hash<fs::path>{}(path_);
    }

    bool equal(code_resource const& rhs) const noexcept override
    {
        if (auto fr = dynamic_cast<file_resource const*>(&rhs)) {
            return path_ == fr->path_;
        }
        return false;
    }
};

class string_resource : public ast_resource
{
public:
    using ast_resource::ast_resource;

    std::ostream& print_description(std::ostream& s) const override
    {
        return s << "<internal resource>"sv;
    }
};

bool environment::resource_equal::operator() (string_view const& l, shared_ptr<ast_resource> const& r) const noexcept
{
    if (auto const* prc = dynamic_cast<string_resource const*>(r.get()); prc) {
        return l == prc->get_source();
    }
    return false;
}

bool environment::resource_equal::operator() (fs::path const& l, shared_ptr<ast_resource> const& r) const noexcept
{
    if (auto const* prc = dynamic_cast<file_resource const*>(r.get()); prc) {
        return l == prc->path();
    }
    return false;
}

functional& environment::resolve_functional(qname_view qn)
{
    assert(qn.is_absolute());
    return fregistry_resolve(qn);
}

identifier environment::new_identifier()
{
    return identifier_builder_();
}

identifier environment::make_identifier(string_view sv)
{
    return slregistry_.resolve(sv);
}

qname_identifier environment::new_qname_identifier()
{
    return fregistry_resolve(qname{ new_identifier() }).id();
}

qname_identifier environment::make_qname_identifier(string_view sv)
{
    qname qn{ slregistry_.resolve(sv) };
    return fregistry_resolve(qn).id();
}

//void environment::push_entity(shared_ptr<entity> e)
//{
//    entity_identifier eid = entity_identifier_builder_();
//    e->set_id(eid);
//    eregistry_insert(std::move(e));
//}

//size_t environment::allocate_constant_index()
//{
//    return bvm().add_const(smart_blob{});
//}

std::string environment::describe_efn(size_t fn_index) const
{
    using sonia::get;
    auto pair = bvm_->efns().at(fn_index);
    if (get<1>(pair).empty()) {
        return ("#%1% at 0x%2$x"_fmt % fn_index % (uintptr_t)get<0>(pair)).str();
    } else {
        return ("#%1% '%2%'"_fmt % fn_index % std::string(get<1>(pair))).str();
    }
}

std::pair<functional*, fn_pure> environment::parse_extern_fn(string_view signature, arena & a)
{
    parser_context parser{ *this };
    auto decls = parser.parse_string(("extern fn ::%1%;"_fmt % signature).str());
    if (!decls.has_value()) [[unlikely]] {
        throw exception(decls.error());
    }

    fn_pure fndecl = std::get<fn_pure>(decls->front().value);

    // If the result is not defined, we cannot resolve it (e.g., from the function body) � assume it is void.
    if (!fndecl.result.index()) {
        fndecl.result = a.make<syntax_expression>(fndecl.location, this->get(builtin_eid::void_));
    }

    return { &resolve_functional(fndecl.name), std::move(fndecl) };
}

//template <std::derived_from<functional::pattern> PT>
//void environment::set_const_extern(string_view signature)
//{
//    auto [pf, fndecl] = parse_extern_fn(signature);
//    fn_compiler_context ctx{ *this, qname{} };
//    auto ptrn = make_shared<PT>(*pf);
//    if (auto err = ptrn->init(ctx, fndecl); err) {
//        throw exception(print(*err));
//    }
//    pf->push(ptrn);
//}

//template <std::derived_from<external_fn_pattern> PT>
//void environment::set_extern(string_view signature, void(*pfn)(vm::context&))
//{
//    auto [pf, fndecl] = parse_extern_fn(signature);
//    internal_function_entity default_fentity{ qname{}, entity_signature{}, {} };
//    fn_compiler_context ctx{ *this, default_fentity };
//    auto ptrn = make_shared<PT>(fn_identifier_counter_);
//    if (auto err = ptrn->init(ctx, fndecl); err) {
//        throw exception(print(*err));
//    }
//    pf->push(ptrn);
//
//    // to do: mangled name
//    std::ostringstream ss;
//    print_to(ss, pf->name());
//    ptrn->print(*this, ss);
//    bvm_->set_efn(fn_identifier_counter_++, pfn, small_string{ ss.str() });
//}

template <std::derived_from<external_fn_pattern> PT>
entity_identifier environment::set_builtin_extern(string_view signature, void(*pfn)(vm::context&))
{
    arena a;
    auto [pf, fndecl] = parse_extern_fn(signature, a);
    auto ptrn = make_shared<PT>();
    internal_function_entity default_fentity{ *this, qname{}, entity_signature{}, resource_location{}, field_descriptor{} };
    if (auto err = ptrn->init(default_fentity.context(), fndecl); err) {
        throw exception(print(*err));
    }
    auto pent = make_shared<external_function_entity>(fn_identifier_counter_);
    //    *this, qname{ pf->name() }, entity_signature{}, fn_identifier_counter_);

    eregistry_insert(pent);
    ptrn->set_result_entity(pent);
    pf->push(ptrn);
    bvm_->set_efn(fn_identifier_counter_++, pfn, small_string{ signature });
    return pent->id;
#if 0
    entity_signature sig{ pf->id() };
    fn_compiler_context ctx{ *this, qname{} };
    size_t paramnum = 0;
    for (auto const& param : fndecl.parameters) {
        auto [external_name, internal_name, varname] = apply_visitor(param_name_retriever{}, param.name);

        auto res = apply_visitor(base_expression_visitor{ ctx, ctx.expression_store() }, *param.constraints.expression);
        if (!res) throw exception(print(*res.error()));
        auto se = res->first;
        if (!se.is_const_result) {
            if (external_name) {
                throw exception("extern function parameter '%1%' must be const"_fmt % print(external_name->value));
            } else {
                throw exception("extern function parameter $%1% must be const"_fmt % paramnum);
            }
        }
        
        if (external_name) {
            sig.emplace_back(external_name->value, se.value(), param.modifier == parameter_constraint_modifier_t::const_value_type);
        } else {
            ++paramnum;
            sig.emplace_back(se.value(), param.modifier == parameter_constraint_modifier_t::const_value_type);
        }

    }

    if (fndecl.result) {
        auto res = apply_visitor(base_expression_visitor{ ctx, ctx.expression_store() }, *fndecl.result);
        if (!res) throw exception(print(*res.error()));
        auto se = res->first;
        if (!se.is_const_result) {
            throw exception("extern function result must be const"_fmt);
        }
        sig.result.emplace(se.value(), false);
    } else {
        sig.result.emplace(get(builtin_eid::void_), false);
    }
    auto pent = make_shared<external_function_entity>(*this, qname{pf->name()}, std::move(sig), fn_identifier_counter_);
    eregistry_insert(pent);
    bvm_->set_efn(fn_identifier_counter_++, pfn, small_string{ signature });
    return pent->id;
#endif
}

#if 0
entity_identifier environment::set_builtin_extern(string_view name, void(*pfn)(vm::context&))
{
    qname qn{ make_identifier(name) };
    qname_identifier qid = fregistry_resolve(qn).id();
    entity_signature sig{ qid };
    sig.result = field_descriptor{ get(builtin_eid::any), false };
    auto pent = make_shared<external_function_entity>(*this, std::move(qn), std::move(sig), fn_identifier_counter_);
    eregistry_insert(pent);
    bvm_->set_efn(fn_identifier_counter_++, pfn, small_string{ name });
    return pent->id;
}
#endif

//variable_entity& environment::new_variable(qname_view var_qname, resource_location const& loc, entity_identifier t, variable_entity::kind k)
//{
//    functional& fnl = fregistry_resolve(var_qname);
//    entity_identifier eid = fnl.default_entity();
//    if (fnl.default_entity(ctx)) {
//        throw exception(print(identifier_redefinition_error{ annotated_qname_identifier{fnl.id(), loc}, eregistry_get(eid).location() }));
//    }
//    auto ve = sonia::make_shared<variable_entity>(std::move(t), fnl.id(), k);
//    ve->set_location(loc);
//    
//    eregistry_insert(ve);
//    fnl.set_default_entity(ve->id());
//
//    return *ve;
//}



environment::~environment()
{
#ifdef ANNIUM_ARENA_TRACE
    for (auto& a : arenas_) {
        GLOBAL_LOG_INFO() << "Arena with %1% bytes in use"_fmt % a->get_allocated_size();
    }
#endif
    eregistry_.clear();
}

void environment::setup_type(builtin_qnid bqnid, builtin_eid beid)
{
    qname_identifier qnid = get(bqnid);
    functional& some_type_fnl = fregistry_resolve(qnid);
    auto some_type_entity = make_shared<basic_signatured_entity>(entity_signature{ qnid, get(builtin_eid::typename_) });
    eregistry_insert(some_type_entity);
    some_type_fnl.set_default_entity(annotated_entity_identifier{ some_type_entity->id, {} });
    builtin_eids_[(size_t)beid] = some_type_entity->id;
}

void environment::set_efn(size_t idx, qname_identifier fnq)
{
    if (vm_builtins_.size() <= idx) {
        vm_builtins_.resize(idx + 1);
    }
    vm_builtins_[idx] = std::move(fnq);
}

std::unique_ptr<arena> environment::acquire_arena() 
{
    lock_guard lg{ arenas_mutex_ };
    if (!arenas_.empty()) {
        auto a = std::move(arenas_.back());
        arenas_.pop_back();
        return a;
    }
    return std::make_unique<arena>();
}

void environment::release_arena(std::unique_ptr<arena> a)
{
    lock_guard lg{ arenas_mutex_ };
    arenas_.emplace_back(std::move(a));
}

ast_resource const& environment::get_resource(resource_identifier const& rid) const
{
    lock_guard lg{ resources_mutex_ };
    auto res = flat_resources_.at(rid.value - 1);
    if (!res) {
        throw exception("resource %1% is not found"_fmt % rid);
    }
    return *res;
}

ast_resource const& environment::get_resource(string_view code)
{
    lock_guard lg{ resources_mutex_ };
    auto it = resources_.find(code);
    if (it == resources_.end()) {
        flat_resources_.emplace_back(make_shared<string_resource>(std::string{ code }));
        it = resources_.insert(it, flat_resources_.back());
        (*it)->id = resource_identifier{ flat_resources_.size() };
    }
    return **it;
}

ast_resource const& environment::get_resource(fs::path const& rpath, fs::path const* context)
{
    optional<fs::path> normalized_path;
    fs::path const* key_path;
    if (rpath.is_absolute()) {
        if (!fs::exists(rpath) || fs::is_directory(rpath)) {
            throw exception("can't resolve path: %1%"_fmt % rpath);
        }
        key_path = &rpath;
    } else {
        normalized_path = context ? context->parent_path() / rpath : rpath;
        for (auto it = additional_paths_.begin();;) {
            if (fs::exists(*normalized_path) && fs::is_regular_file(*normalized_path)) {
                key_path = &(*normalized_path);
                break;
            }
            if (it == additional_paths_.end()) {
                throw exception("can't resolve path: %1%"_fmt % rpath);
            }
            normalized_path = (*it++) / rpath;
        }
    }
    lock_guard lg{ resources_mutex_ };
    auto it = resources_.find(*key_path);
    if (it == resources_.end()) {
        flat_resources_.emplace_back(make_shared<file_resource>(normalized_path ? std::move(*normalized_path) : fs::path{ *key_path }));
        it = resources_.insert(it, flat_resources_.back());
        (*it)->id = resource_identifier{ flat_resources_.size() };
    }
    return **it;
}

void environment::store(semantic::managed_expression_list&& el)
{
    expressions_.splice_back(el);
}

template <typename OutputIteratorT, typename UndefinedFT>
OutputIteratorT environment::identifier_printer(identifier const& id, string_view prefix, OutputIteratorT oi, UndefinedFT const& uf) const
{
    if (auto const* pstr = slregistry_.resolve(id); pstr) {
        oi = std::copy(pstr->begin(), pstr->end(), std::copy(prefix.begin(), prefix.end(), std::move(oi)));
    } else if (auto sp = piregistry_.resolve(id); sp) {
        if (!sp->empty()) {
            //oi = std::copy(prefix.begin(), prefix.end(), std::move(oi));
            *oi++ = '<';
            for (auto const& qn : *sp) {
                if (&qn != &sp->front()) *oi++ = ',';
                oi = name_printer(functional_registry_.resolve(qn).name(), std::move(oi), uf);
            }
            *oi++ = '>';
        }
    } else {
        uf(id, prefix, oi);
    }
    return std::move(oi);
}

template <typename OutputIteratorT, typename UndefinedFT>
OutputIteratorT environment::name_printer(qname_view const& qn, OutputIteratorT oi, UndefinedFT const& uf) const
{
    if (!qn.empty()) {
        oi = identifier_printer(qn.front(), qn.is_absolute() ? "::"sv : ""sv, std::move(oi), uf);
    
        for (identifier const& id : qn.subspan(1)) {
            oi = identifier_printer(id, "::"sv, std::move(oi), uf);
        }
    }
    return std::move(oi);
}

std::ostream& environment::print_to(std::ostream& os, identifier const& id) const
{
    boost::container::small_vector<char, 32> result;
    identifier_printer(id, ""sv, std::back_inserter(result), [](identifier const& id, string_view prefix, auto & oi) {
        std::ostringstream ss;
        ss << prefix << "@"sv << id.value;
        auto str = ss.str();
        oi = std::copy(str.begin(), str.end(), std::move(oi));
    });
    os.write(result.data(), result.size());
    return os;
}

std::ostream& environment::print_to(std::ostream& os, entity_identifier const& id) const
{
    if (id) {
        eregistry_.get(id).print_to(os, *this);
    } else {
        os << "nil-entity"sv;
    }
    return os;
}

std::ostream& environment::print_to(std::ostream& os, entity const& e) const
{
    return e.print_to(os, *this);
}

std::ostream& environment::print_to(std::ostream& os, field_descriptor const& fd) const
{
    if (fd.name()) {
        print_to(os, fd.name()) << ": "sv;
    }
    if (fd.entity_id() == get(builtin_eid::void_)) {
        return os << "()"sv;
    } else {
        if (fd.is_const()) os << "const "sv;
        return print_to(os, fd.entity_id());
    }
}

std::ostream& environment::print_to(std::ostream& os, entity_signature const& sgn) const
{
    os << print(sgn.name);
    if (!sgn.fields().empty()) {
        os << '(';
        bool first = true;

        for (uint32_t i = 0; i < sgn.fields().size(); ++i) {
            if (first) first = false;
            else os << ", "sv;
            
            print_to(os, sgn.fields()[i]);
        }

        os <<')';
    }
    if (sgn.result && sgn.result->entity_id() != get(builtin_eid::typename_)) {
        os << "->"sv;
        print_to(os, *sgn.result);
    }
    return os;
}

std::ostream& environment::print_to(std::ostream& os, syntax_pattern::signature_descriptor const& ptrnsig) const
{
    visit([&os, this](auto const& p) {
        if constexpr (std::is_same_v<annotated_qname_view, std::decay_t<decltype(p)>>) {
            print_to(os, p.value);
        } else if constexpr (std::is_same_v<context_identifier, std::decay_t<decltype(p)>>) {
            print_to(os, p.name.value);
        } else if constexpr (std::is_same_v<placeholder, std::decay_t<decltype(p)>>) {
            os << '_';
        } else { // syntax_expression
            print_to(os << '{', p) << '}';
        }
    }, ptrnsig.name);
    if (!ptrnsig.fields.empty()) {
        os << '(';
        bool first = true;
        for (auto const& f : ptrnsig.fields) {
            if (first) first = false; else os << ", "sv;

            visit([&os, this](auto const& p) {
                if constexpr (std::is_same_v<placeholder, std::decay_t<decltype(p)>>) {
                    os << "_ : "sv;
                } else if constexpr (std::is_same_v<annotated_identifier, std::decay_t<decltype(p)>>) {
                    print_to(os, p.value) << ": "sv;
                } else if constexpr (std::is_same_v<context_identifier, std::decay_t<decltype(p)>>) {
                    print_to(os, p.name.value) << ": "sv;
                } else if constexpr (std::is_same_v<syntax_expression, std::decay_t<decltype(p)>>) {
                    print_to(os << '{', p) << "}: "sv;
                } else { // nullptr_t
                    BOOST_ASSERT(p == nullptr);
                }
            }, f.name);

            print_to(os, *f.value);
            if (f.ellipsis) { os << "... "sv; }
        }
        os << ')';
    }
    return os;
}

std::ostream& environment::print_to(std::ostream& os, syntax_pattern const& ptrn) const
{
    visit([&os, this](auto const& d) {
        if constexpr (std::is_same_v<placeholder, std::decay_t<decltype(d)>>) {
            os << '_';
        } else if constexpr (std::is_same_v<syntax_pattern::signature_descriptor, std::decay_t<decltype(d)>>) {
            print_to(os, d);
        } else if constexpr (std::is_same_v<syntax_expression const*, std::decay_t<decltype(d)>>) {
            print_to(os << "={"sv, d) << '}';
        } else if constexpr (std::is_same_v<context_identifier, std::decay_t<decltype(d)>>) {
            print_to(os, d.name.value);
        } else {
            static_assert(false);
        }
    }, ptrn.descriptor);

    if (!ptrn.concepts.empty()) {
        bool first = true;
        for (auto const& c : ptrn.concepts) {
            if (first) first = false; else os << ", "sv;
            print_to(os << '@', c);
        }
    }
    return os;
}

std::ostream& environment::print_to(std::ostream& os, qname_view const& qn) const
{
    small_vector<char, 32> result;
    name_printer(qn, std::back_inserter(result), [](identifier const& id, string_view prefix, auto & oi) {
        std::ostringstream ss;
        ss << prefix << "@"sv << id.value;
        auto str = ss.str();
        oi = std::copy(str.begin(), str.end(), std::move(oi));
    });
    os.write(result.data(), result.size());
    return os;
}

std::ostream& environment::print_to(std::ostream& os, qname_identifier const& qid) const
{
    if (qid) {
        return print_to(os, functional_registry_.resolve(qid).name());
    }
    return os << "`uninitialized qname`"s;
}

std::ostream& environment::print_to(std::ostream& os, small_u32string const& str, bool in_quotes) const
{
    using namespace dataforge;
    if (in_quotes) os << '`';
    (quark_push_iterator(utf32 | utf8, std::ostreambuf_iterator(os)) << str).flush();
    if (in_quotes) os << '`';
    return os;
}

std::ostream& environment::print_to(std::ostream& os, resource_location const& loc, string_view indent, resource_print_mode_t mode) const
{
    try {
        return get_resource(loc.resource_id).print_to(os, indent, loc.line, loc.column, mode);
    }
    catch (std::exception const&) {
        return os << "<unknown resource>"sv << '(' << loc.line << ',' << loc.column << ')';
    }
    //return os << ("%1%(%2%,%3%)"_fmt % loc.resource % loc.line % loc.column).str();
}

struct type_printer_visitor : static_visitor<void>
{
    environment const& e_;
    std::ostringstream & ss;
    explicit type_printer_visitor(environment const& e, std::ostringstream& s) : e_{e}, ss{s} {}

    template <typename T>
    inline void operator()(T const& v) const
    {
        (void)v;
        THROW_NOT_IMPLEMENTED_ERROR("environment::type_printer_visitor operator()");
    }

    inline void operator()(annotated_qname const& qn) const { ss << e_.print(qn.value); }
    inline void operator()(annotated_identifier const& obj) const { ss << e_.print(obj.value); }
    //inline void operator()(annium_object_t const& obj) const { ss << e_.print(obj.id()); }
        
    inline void operator()(annium_fn_type const& fn) const
    {
        ss << '(';
        (*this)(fn.args);
        ss << ")->"sv;
        if (fn.result) {
            std::visit(*this, fn.result->value);
        } else {
            ss << "()"sv;
        }
    }

    inline void operator()(span<const opt_named_expression_t> nel) const
    {
        ss << '(';
        bool first = true;
        for (auto const& f : nel) {
            if (first) first = false; else ss << ',';
            if (auto* pname = f.name(); pname) {
                ss << e_.print(pname->value) << ": "sv;
            }
            std::visit(*this, f.value().value);
        }
        ss << ')';
    }

    inline void operator()(bracket_expression const& v) const
    {
        ss << '[';
        std::visit(*this, v.type->value);
        ss << ']';
    }

    inline void operator()(index_expression const& ie) const
    {
        std::visit(*this, ie.base->value);
        ss << '[';
        std::visit(*this, ie.index->value);
        ss << ']';
    }

    //inline void operator()(annium_tuple_t const& tpl) const
    //{
    //    ss << '(';
    //    for (auto const& f : tpl.fields) {
    //        if (&f != &tpl.fields.front()) ss << ',';
    //        if (auto* pname = f.name(); pname) {
    //            ss << e_.print(pname->value) << ": "sv;
    //        }
    //        apply_visitor(*this, f.value());
    //    }
    //    ss << ')';
    //}

    //template <typename FamilyT>
    //inline void operator()(annium_tuple<FamilyT> const& tpl) const
    //{
    //    ss << '(';
    //    for (auto const& f : tpl.fields) {
    //        if (&f != &tpl.fields.front()) ss << ',';
    //        apply_visitor(*this, f);
    //    }
    //    ss << ')';
    //}

    //inline void operator()(annium_bunion_t const& bu) const
    //{
    //    ss << "{true: "sv;
    //    apply_visitor(*this, bu.true_type);
    //    ss << ", false: "sv;
    //    apply_visitor(*this, bu.true_type);
    //    ss << '}';
    //}

    //inline void operator()(annium_union_t const& tpl) const
    //{
    //    bool first = true;
    //    for (auto const& f : tpl) {
    //        if (!first) ss << "|"sv; else first = false;
    //        apply_visitor(*this, f);
    //    }
    //}

    //template <typename FamilyT>
    //inline void operator()(annium_union<FamilyT> const& tpl) const
    //{
    //    for (auto const& f : tpl.members) {
    //        if (&f != &tpl.members.front()) ss << "||";
    //        apply_visitor(*this, f);
    //    }
    //}
};

//std::string environment::print(annium_preliminary_type const& tp) const
//{
//    std::ostringstream ss;
//    type_printer_visitor vis{ *this, ss };
//    apply_visitor(vis, tp);
//    return ss.str();
//}

//std::string environment::print(annium_type const& tp) const
//{
//    std::ostringstream ss;
//    type_printer_visitor vis{ *this, ss };
//    apply_visitor(vis, tp);
//    return ss.str();
//}

//small_string environment::as_string(identifier const& id) const
//{
//    boost::container::small_vector<char, 32> result;
//    identifier_printer(id, ""sv, std::back_inserter(result), [](identifier const& id, string_view, auto &) {
//        throw exception("identifier '%1%' has no string representation"_fmt % id.value);
//    });
//    return { result.data(), result.size() };
//}
//
//small_string environment::as_string(entity_identifier const& id) const
//{
//    THROW_NOT_IMPLEMENTED_ERROR("environment::as_string entity_identifier");
//}
//
//small_string environment::as_string(qname_view qn) const
//{
//    boost::container::small_vector<char, 32> result;
//    name_printer(qn, std::back_inserter(result), [](identifier const& id, string_view, auto &) {
//        throw exception("identifier '%1%' has no string representation"_fmt % id.value);
//    });
//    return { result.data(), result.size() };
//}
//
//small_string environment::as_string(qname_identifier name) const
//{
//    return as_string(functional_registry_.resolve(name).name());
//}

//small_u32string environment::as_u32string(identifier const& id) const
//{
//    namespace cvt = boost::conversion;
//    if (auto const* pstr = slregistry_.resolve(id); pstr) {
//        boost::container::small_vector<char32_t, 32> result;
//        (cvt::cvt_push_iterator(cvt::utf8 | cvt::utf32, std::back_inserter(result)) << *pstr).flush();
//        return small_u32string{ result.data(), result.size() };
//    }
//    throw exception("identifier '%1%' has no string representation"_fmt % id.value);
//}



//small_u32string environment::as_u32string(qname_view name) const
//{
//    namespace cvt = boost::conversion;
//    boost::container::small_vector<char32_t, 32> result;
//    for (identifier const& id : name) {
//        if (&name.front() != &id || name.is_absolute()) {
//            result.push_back(':');
//            result.push_back(':');
//        }
//        if (auto const* pstr = slregistry_.resolve(id); pstr) {
//            (cvt::cvt_push_iterator(cvt::utf8 | cvt::utf32, std::back_inserter(result)) << *pstr).flush();
//        } else if (auto sp = piregistry_.resolve(id); sp) {
//
//
//        } else {
//            throw exception("identifier '%1%' has no string representation"_fmt % id.value);
//            //result.push_back('$');
//            //(cvt::cvt_push_iterator(cvt::utf8 | cvt::utf32, std::back_inserter(result)) << boost::lexical_cast<std::string>(id.value)).flush();
//        }
//    }
//    return small_u32string{ result.data(), result.size() };
//}


struct expr_printer_visitor : static_visitor<void>
{
    environment const& e_;
    std::ostream& ss;
    explicit expr_printer_visitor(environment const& e, std::ostream& s) noexcept
        : e_{ e }, ss{ s }
    {}

    template <typename T>
    void operator()(annotated<T> const& ae) const
    {
        this->operator()(ae.value);
    }

    void operator()(nil_expression const&) const
    {
        ss << "nil"sv;
    }

    void operator()(qname const& qn) const
    {
        e_.print_to(ss, qn);
    }

    void operator()(qname_view qn) const
    {
        e_.print_to(ss, qn);
    }

    void operator()(identifier const& i) const
    {
        e_.print_to(ss, i);
    }

    void operator()(bool bval) const
    {
        ss << std::boolalpha << bval;
    }

    void operator()(small_string const& s) const
    {
        ss << '"' << s << '"';
    }

    void operator()(string_view s) const
    {
        ss << '"' << s << '"';
    }

    void operator()(numetron::integer_view const& i) const
    {
        ss << i;
    }

    void operator()(numetron::decimal_view const& d) const
    {
        ss << to_string(d);
    }

    void operator()(indirect_value const& vi) const
    {
        ss << "INDIRECT(type: "sv;
        (*this)(vi.type);
        ss << ')';
    }

    void operator()(name_reference_expression const& vi) const
    {
        //if (vi.implicit) {
        //    ss << "IMPLICIT"sv;
        //}
        //ss << "VAR("sv << e_.print(vi.name.value) << ")"sv;
        e_.print_to(ss, vi.name);
    }

    void operator()(qname_reference_expression const& vi) const
    {
        //if (vi.implicit) {
        //    ss << "IMPLICIT"sv;
        //}
        //ss << "VAR("sv << e_.print(vi.name.value) << ")"sv;
        e_.print_to(ss, vi.name);
    }

    /*
    void operator()(chained_expression_t const& c) const
    {
        ss << "CHAIN("sv;
        apply_visitor(*this, c.expression);
        ss << ": "sv;
        for (opt_chain_link_t const& l : c.chaining) {
            if (&l != &c.chaining.front()) {
                ss << ", "sv;
            }
            apply_visitor(*this, l);
        }
        ss << ")"sv;
    }
    */

    void operator()(not_empty_expression const& c) const
    {
        ss << "NOTEMPTY("sv;
        visit(*this, c.value->value);
        ss << ")"sv;
    }

    void operator()(member_expression const& c) const
    {
        ss << "MEMBER("sv;
        //if (c.is_object_optional) {
        //    ss << "OPT "sv;
        //}
        visit(*this, c.object->value);
        e_.print_to(ss << ", "sv, c.property) << ')';
    }

    //void operator()(expression_vector_t const& ev) const
    //{
    //    ss << '[';
    //    bool first = true;
    //    for (auto const& e : ev.elements) {
    //        if (!first) ss << ", "sv;
    //        else first = false;
    //        apply_visitor(*this, e);
    //    }
    //    ss << ']';
    //}

    void operator()(function_call const& f) const
    {
        ss << "CALL("sv;
        if (f.fn_object) {
            visit(*this, f.fn_object->value);
        } else {
            ss << "tuple"sv;
        }
        ss << ")(args)"sv;
    }

    //template <typename T>
    //requires(is_unary_expression<T>::value)
    //void operator()(T const& ue) const
    //{
    //    ss << "unary("sv << (int)T::op << ", "sv;
    //    apply_visitor(*this, ue.argument);
    //    ss << ')';
    //}

    void operator()(unary_expression const& be) const
    {
        ss << "unary("sv << (int)be.op << ", "sv;
        (*this)(be.args);
        ss << ')';
    }

    void operator()(binary_expression const& be) const
    {
        ss << "binary("sv << to_string(be.op) << ", "sv;
        (*this)(be.args);
        ss << ')';
    }

    //void operator()(context_identifier const& f) const
    //{
    //    ss << "CONTEXT("sv << e_.print(f.name.value) << ")"sv;
    //}

    void operator()(lambda const& f) const
    {
        (void)f; // suppress unused warning
        THROW_NOT_IMPLEMENTED_ERROR();
    }

    void operator()(annotated_entity_identifier const& f) const
    {
        (*this)(f.value);
    }

    void operator()(entity_identifier const& eid) const
    {
        if (eid == e_.get(builtin_eid::void_)) {
            ss << "void"sv;
        } else {
            e_.print_to(ss << "ENTITY("sv, eid) << ')';
        }
    }

    void operator()(span<const opt_named_expression_t> nel) const
    {
        ss << '(';
        bool is_first = true;
        for (auto const& ne: nel) {
            if (is_first) is_first = false;
            else ss << ", "sv;
            if (auto const* pname = ne.name(); pname) {
                this->operator()(pname->value);
                ss << ": "sv;
            }
            visit(*this, ne.value().value);
        }
        ss << ')';
    }
    
    void operator()(placeholder const&) const
    {
        ss << '_';
    }

    void operator()(array_expression const& ae) const
    {
        ss << '[';
        bool first = true;
        for (auto const& e : ae.elements) {
            if (!first) ss << ", "sv;
            else first = false;
            visit(*this, e.value);
        }
        ss << ']';
    }

    void operator()(index_expression const& ie) const
    {
        ss << "INDEX("sv;
        visit(*this, ie.base->value);
        ss << ", "sv;
        visit(*this, ie.index->value);
        ss << ')';
    }

    void operator()(bracket_expression const& v) const
    {
        ss << '[';
        visit(*this, v.type->value);
        ss << ']';
    }

    void operator()(new_expression const& ne) const
    {
        ss << "new "sv;
        visit(*this, ne.name->value);
        (*this)(ne.arguments);
    }

    inline void operator()(syntax_expression const& se) const
    {
        visit(*this, se.value);
    }

    void operator()(annium_fn_type const& fnt) const
    {
        if (fnt.args.empty()) {
            ss << "()"sv;
        } else if (fnt.args.size() == 1) {
            opt_named_expression_t const& ne = fnt.args.front();
            auto [pname, value] = *ne;
            if (pname) {
                e_.print_to(ss << '(', pname->value) << ": "sv;
                (*this)(value);
                ss << ')';
            } else {
                (*this)(value);
            }
        } else {
            (*this)(fnt.args);
        }
        ss << "->"sv;
        (*this)(*fnt.result);
    }

    template <typename T>
    void operator()(T const& te) const
    {
        (void)te;
        THROW_NOT_IMPLEMENTED_ERROR();
    }
};

std::ostream& environment::print_to(std::ostream& os, syntax_expression const* e) const
{   
    visit(expr_printer_visitor{ *this, os }, e->value);
    return os;
}

std::ostream& environment::print_to(std::ostream& os, semantic::expression const& e) const
{
    semantic::expression_printer_visitor vis{ *this, os };
    visit(vis, e);
    return os;
}

std::ostream& environment::print_to(std::ostream& os, semantic::expression_list_t const& elist) const
{
    for (auto const& e : elist) {
        print_to(os, e);
    }
    return os;
}

std::ostream& environment::print_to(std::ostream& os, error const& err) const
{
    error_printer_visitor vis{ *this, os };
    err.visit(vis);
    return os;
}

//functional_entity& environment::get_functional_entity(binary_operator_type bop)
//{
//    qname_identifier op_qi;
//    switch (bop) {
//    case binary_operator_type::CONCAT:
//        op_qi = make_qname_identifier("concat"sv); break;
//    case binary_operator_type::PLUS:
//        op_qi = make_qname_identifier("operator_plus"sv); break;
//    default:
//        THROW_INTERNAL_ERROR("environment::get_functional_entity error: unknown operator '%1%'"_fmt % to_string(bop));
//    }
//    THROW_NOT_IMPLEMENTED_ERROR("environment::get_functional_entity");
//#if 0
//    auto func_ent = dynamic_pointer_cast<functional_entity>(eregistry().find(op_qi));
//    if (!func_ent) {
//        THROW_INTERNAL_ERROR("environment::get_functional_entity error: operator '%1%' is not defined"_fmt % to_string(bop));
//    }
//    return *func_ent;
//#endif
//}

void environment::push_back_expression(semantic::expression_list_t& l, semantic::expression_span& sp, semantic::expression&& e)
{
    semantic::expression_list_t::entry_type* pentry = semantic_expression_list_entry_pool_.new_object(std::move(e));
    if (sp) {
        l.insert(*sp.second, *pentry);
        sp.second = static_cast<semantic::expression_entry*>(pentry);
    } else {
        l.push_back(*pentry);
        sp = semantic::expression_span{ static_cast<semantic::expression_entry*>(pentry) };
    }
}

void environment::push_back_expression(semantic::expression_list_t& l, semantic::expression&& e)
{
    semantic::expression_list_t::entry_type * pentry = semantic_expression_list_entry_pool_.new_object(std::move(e));
    l.push_back(*pentry);
}

void environment::release(semantic::expression_list_t::entry_type&& e)
{
    semantic_expression_list_entry_pool_.delete_object(&e);
}

functional* environment::fregistry_find(qname_view qnid)
{
    return functional_registry_.find(qnid);
}

functional& environment::fregistry_resolve(qname_identifier qnid)
{
    return functional_registry_.resolve(qnid);
}

functional& environment::fregistry_resolve(qname_view qn)
{

    return functional_registry_.resolve(qn, [LANG_DEBUG_THIS](qname_identifier qid, qname_view qnv) {
#ifdef SONIA_LANG_DEBUG
        qid.debug_name = as_string(qnv);
#endif
        return make_shared<functional>(std::move(qid), qnv);
    });
}

entity const& environment::eregistry_get(entity_identifier eid) const
{
    return eregistry_.get(eid);
}

void environment::eregistry_insert(shared_ptr<entity> e)
{
#ifdef SONIA_LANG_DEBUG
    std::ostringstream ss;
    e->print_to(ss, *this);
    e->debug_name = ss.str();
#endif
    eregistry_.insert(std::move(e));
}

identifier_entity const& environment::make_identifier_entity(identifier value)
{
    identifier_entity smpl{ value, get(builtin_eid::identifier) };
    return static_cast<identifier_entity&>(eregistry_find_or_create(smpl, [&smpl]() {
        return make_shared<identifier_entity>(std::move(smpl));
    }));
}

empty_entity const& environment::make_empty_entity(entity_identifier type)
{
    empty_entity smpl{ type };
    return static_cast<empty_entity&>(eregistry_find_or_create(smpl, [&smpl]() {
        return make_shared<empty_entity>(std::move(smpl));
    }));
}

empty_entity const& environment::make_empty_entity(entity const& e)
{
    BOOST_ASSERT(e.signature() && e.signature()->result && e.signature()->result->entity_id() == get(builtin_eid::typename_));
    return make_empty_entity(e.id);
}

qname_entity const& environment::make_qname_entity(qname_view value)
{
    qname_entity smpl{ value, get(builtin_eid::qname) };
    return static_cast<qname_entity&>(eregistry_find_or_create(smpl, [&smpl]() {
        return make_shared<qname_entity>(std::move(smpl));
    }));
}

functional_identifier_entity const& environment::make_functional_identifier_entity(qname_identifier value)
{
    functional_identifier_entity smpl{ value, get(builtin_eid::qname) };
    return static_cast<functional_identifier_entity&>(eregistry_find_or_create(smpl, [&smpl]() {
        return make_shared<functional_identifier_entity>(std::move(smpl));
    }));
}

generic_literal_entity const& environment::make_nil_entity(entity_identifier type)
{
    generic_literal_entity smpl{ smart_blob{ }, type ? type : get(builtin_eid::void_type) };
    return static_cast<generic_literal_entity&>(eregistry_find_or_create(smpl, [&smpl]() {
        return make_shared<generic_literal_entity>(std::move(smpl));
    }));
}

generic_literal_entity const& environment::make_bool_entity(bool value, entity_identifier type)
{
    generic_literal_entity smpl{ smart_blob{ bool_blob_result(value) }, type ? type : get(builtin_eid::boolean) };
    return static_cast<generic_literal_entity&>(eregistry_find_or_create(smpl, [&smpl]() {
        return make_shared<generic_literal_entity>(std::move(smpl));
    }));
}

generic_literal_entity const& environment::make_generic_entity(smart_blob value, entity_identifier type)
{
    generic_literal_entity smpl{ std::move(value), std::move(type) };
    return static_cast<generic_literal_entity&>(eregistry_find_or_create(smpl, [&smpl]() {
        return make_shared<generic_literal_entity>(generic_literal_entity{ smart_blob{ smpl.value() }.allocate(), smpl.get_type() });
    }));
}

generic_literal_entity const& environment::make_integer_entity(numetron::integer_view value, entity_identifier type)
{
    return make_generic_entity(smart_blob{ bigint_blob_result(value) }, type ? type : get(builtin_eid::integer));
}

generic_literal_entity const& environment::make_decimal_entity(numetron::decimal_view value, entity_identifier type)
{
    return make_generic_entity(smart_blob{ decimal_blob_result(value) }, type ? type : get(builtin_eid::decimal));
}

generic_literal_entity const& environment::make_string_entity(string_view value, entity_identifier type)
{
    return make_generic_entity(smart_blob{ string_blob_result(value) }, type ? type : get(builtin_eid::string));
}

basic_signatured_entity const& environment::make_basic_signatured_entity(entity_signature&& sig)
{
    indirect_signatured_entity smpl{ sig };
    return static_cast<basic_signatured_entity&>(eregistry_find_or_create(smpl, [&sig]() {
        return make_shared<basic_signatured_entity>(std::move(sig));
    }));
}

basic_signatured_entity const& environment::make_array_type_entity(entity_identifier element_type, optional<size_t> sz)
{
    entity_signature sig{ get(builtin_qnid::array), get(builtin_eid::typename_) };
    sig.emplace_back(get(builtin_id::of), element_type, true);
    if (sz) {
        entity_identifier szeid = make_integer_entity((uint64_t)*sz).id;
        sig.emplace_back(get(builtin_id::size), szeid, true);
    }
    return make_basic_signatured_entity(std::move(sig));
}

basic_signatured_entity const& environment::make_array_entity(entity_identifier element_type, span<entity_identifier> const& values)
{
    entity_identifier tp = make_array_type_entity(element_type, values.size()).id;
    entity_signature sig{ get(builtin_qnid::data), tp };
    for (auto const& v : values) {
        sig.emplace_back(v, true);
    }
    return make_basic_signatured_entity(std::move(sig));
}

entity const& environment::make_union_type_entity(span<entity_identifier> const& items)
{
    if (items.empty()) {
        return get_entity(*this, get(builtin_eid::void_type));
    }

    if (items.size() == 1) {
        return get_entity(*this, *items.begin());
    }

    entity_signature usig(get(builtin_qnid::union_), get(builtin_eid::typename_));
    for (entity_identifier const& eid : items) {
        bool is_const = get_entity(*this, eid).get_type() != get(builtin_eid::typename_);
        usig.push_back(field_descriptor{ eid, is_const });
    }

    return make_basic_signatured_entity(std::move(usig));
}

environment::environment()
    : semantic_expression_list_entry_pool_{ 128, 128 }
    , slregistry_{ identifier_builder_ }
    , piregistry_{ identifier_builder_ }
    , expressions_{ *this }
    , fn_identifier_counter_ { (size_t)virtual_stack_machine::builtin_fn::eof_type }
    , bvm_{ std::make_unique<virtual_stack_machine>() }
    , asm_builder_{ std::make_unique<asm_builder_t>(*bvm_) }
{
    //// ids
#define ANNIUM_PRINT_ENUM_ASSIGN(r, data, i, elem) \
    builtin_ids_[(size_t)builtin_id::BOOST_PP_TUPLE_ELEM(2, 0, elem)] = make_identifier(BOOST_PP_TUPLE_ELEM(2, 1, elem));
    BOOST_PP_SEQ_FOR_EACH_I(ANNIUM_PRINT_ENUM_ASSIGN, _, ANNIUM_BUILTIN_ID_SEQ)
#undef ANNIUM_PRINT_ENUM_ASSIGN

    //// qnids
#define ANNIUM_PRINT_ENUM_ASSIGN(r, data, i, elem) \
    builtin_qnids_[(size_t)builtin_qnid::BOOST_PP_TUPLE_ELEM(2, 0, elem)] = make_qname_identifier(BOOST_PP_TUPLE_ELEM(2, 1, elem));
    BOOST_PP_SEQ_FOR_EACH_I(ANNIUM_PRINT_ENUM_ASSIGN, _, ANNIUM_BUILTIN_QNAMES_SEQ)
#undef ANNIUM_PRINT_ENUM_ASSIGN

    //// typename entity definition
    entity_signature typename_sig{ get(builtin_qnid::typename_) };
    basic_signatured_entity const& typename_entity = make_basic_signatured_entity(std::move(typename_sig));
    builtin_eids_[(size_t)builtin_eid::typename_] = typename_entity.id;

    //// builtin types definitions
#define ANNIUM_PRINT_ENUM_ASSIGN(r, data, elem) \
    setup_type(builtin_qnid::elem, builtin_eid::elem); \
    BOOST_ASSERT(get(builtin_eid::elem).value == static_cast<entity_identifier::value_type>(builtin_eid::elem));
    BOOST_PP_SEQ_FOR_EACH(ANNIUM_PRINT_ENUM_ASSIGN, _, ANNIUM_BUILTIN_TYPES_SEQ)
#undef ANNIUM_PRINT_ENUM_ASSIGN

#if 0
    auto punpack = make_shared<external_function_entity>(new_qname_identifier(), (size_t)virtual_stack_machine::builtin_fn::unpack);
    eregistry_insert(punpack);
    set_efn(builtin_fn::unpack, punpack->name());

    auto pweak_create = make_shared<external_function_entity>(new_qname_identifier(), (size_t)virtual_stack_machine::builtin_fn::weak_create);
    eregistry_insert(pweak_create);
    set_efn(builtin_fn::weak_create, pweak_create->name());

    auto pweak_lock = make_shared<external_function_entity>(new_qname_identifier(), (size_t)virtual_stack_machine::builtin_fn::weak_lock);
    eregistry_insert(pweak_lock);
    set_efn(builtin_fn::weak_lock, pweak_lock->name());

    auto peogp = make_shared<external_function_entity>(new_qname_identifier(), (size_t)virtual_stack_machine::builtin_fn::extern_object_get_property);
    eregistry_insert(peogp);
    set_efn(builtin_fn::extern_object_get_property, peogp->name());

    auto pefc = make_shared<external_function_entity>(new_qname_identifier(), (size_t)virtual_stack_machine::builtin_fn::extern_function_call);
    eregistry_insert(pefc);
    set_efn(builtin_fn::extern_function_call, pefc->name());

    set_extern("operator_plus(decimal,decimal)->decimal"sv, &annium_operator_plus_decimal);
    set_extern("decimal(text: string)->decimal|()"sv, &annium_to_decimal);
#endif
        
    // void
    entity_signature empty_tuple_sig{ get(builtin_qnid::tuple), get(builtin_eid::typename_) };
    basic_signatured_entity const& empty_tuple_ent = make_basic_signatured_entity(std::move(empty_tuple_sig));
    builtin_eids_[(size_t)builtin_eid::void_type] = empty_tuple_ent.id;
    empty_entity const& void_entity = make_empty_entity(empty_tuple_ent);
    builtin_eids_[(size_t)builtin_eid::void_] = void_entity.id;

    // boolean, true, false
    builtin_eids_[(size_t)builtin_eid::true_] = make_bool_entity(true).id;
    builtin_eids_[(size_t)builtin_eid::false_] = make_bool_entity(false).id;
        
    setup_type(builtin_qnid::object, builtin_eid::object);
    setup_type(builtin_qnid::identifier, builtin_eid::identifier);
    setup_type(builtin_qnid::qname, builtin_eid::qname);
    //setup_type(builtin_qnid::metaobject, builtin_eid::metaobject);

    /////// built in patterns
    // runtime_cast(_)
    functional& runtime_cast_fnl = fregistry_resolve(get(builtin_qnid::runtime_cast));
    runtime_cast_fnl.push(make_shared<runtime_cast_pattern>());

    // operator*(type: typename)
    functional& deref_fnl = fregistry_resolve(get(builtin_qnid::deref));
    deref_fnl.push(make_shared<deref_pattern>());

    // operator...(type: typename)
    functional& ellipsis_fnl = fregistry_resolve(get(builtin_qnid::ellipsis));
    ellipsis_fnl.push(make_shared<ellipsis_pattern>());

    // error(_) -> ()
    functional& error_fnl = fregistry_resolve(get(builtin_qnid::error));
    error_fnl.push(make_shared<error_pattern>());

    // assert(...) -> ()
    functional& assert_fnl = fregistry_resolve(get(builtin_qnid::assert));
    assert_fnl.push(make_shared<assert_pattern>());

    // equal(_, _) -> bool
    functional& equal_fnl = fregistry_resolve(get(builtin_qnid::eq));
    equal_fnl.push(make_shared<enum_equal_pattern>());
    equal_fnl.push(make_shared<tuple_equal_pattern>());
    equal_fnl.push(make_shared<numeric_literal_equal_pattern>());
    equal_fnl.push(make_shared<equal_pattern>());

    functional& logical_not_fnl = fregistry_resolve(get(builtin_qnid::logical_not));
    logical_not_fnl.push(make_shared<logical_not_pattern>());

    functional& typeof_fnl = fregistry_resolve(get(builtin_qnid::typeof));
    typeof_fnl.push(make_shared<typeof_pattern>());

    functional& minus_fnl = fregistry_resolve(get(builtin_qnid::minus));
    minus_fnl.push(make_shared<numeric_literal_unary_minus_pattern>());

    // typeof(object: const metaobject, property: const __identifier) -> typename
    //typeof_fnl.push(make_shared<metaobject_typeof_pattern>());

    functional& to_string_fnl = fregistry_resolve(get(builtin_qnid::to_string));
    to_string_fnl.push(make_shared<to_string_pattern>());
    to_string_fnl.push(make_shared<enum_to_string_pattern>());

    functional& to_integer_fnl = fregistry_resolve(get(builtin_qnid::to_integer));
    to_integer_fnl.push(make_shared<enum_to_integer_pattern>());

    functional& tuple_fnl = fregistry_resolve(get(builtin_qnid::tuple));
    tuple_fnl.push(make_shared<tuple_pattern>());

    functional& implicit_cast_fnl = fregistry_resolve(get(builtin_qnid::implicit_cast));
    //implicit_cast_fnl.push(make_shared<struct_implicit_cast_pattern>());
    implicit_cast_fnl.push(make_shared<enum_implicit_cast_pattern>());
    implicit_cast_fnl.push(make_shared<enum_implicit_runtime_cast_pattern>());
    //implicit_cast_fnl.push(make_shared<fixed_array_implicit_cast_pattern>()); // array to vector
    implicit_cast_fnl.push(make_shared<array_implicit_cast_pattern>()); // vector to vector
    //implicit_cast_fnl.push(make_shared<fixed_array_elements_implicit_cast_pattern>());
    implicit_cast_fnl.push(make_shared<to_union_implicit_cast_pattern>());
    //implicit_cast_fnl.push(make_shared<numeric_implicit_cast_pattern>());
    implicit_cast_fnl.push(make_shared<tuple_implicit_cast_pattern>());
    implicit_cast_fnl.push(make_shared<numeric_literal_implicit_cast_pattern>());
    implicit_cast_fnl.push(make_shared<string_implicit_cast_pattern>());
    implicit_cast_fnl.push(make_shared<to_callable_implicit_cast_pattern>());
    implicit_cast_fnl.push(make_shared<void_implicit_cast_pattern>());
    implicit_cast_fnl.push(make_shared<any_implicit_cast_pattern>());

    auto union_pattern = make_shared<union_bit_or_pattern>();
    functional& bit_or_fnl = fregistry_resolve(get(builtin_qnid::bit_or));
    bit_or_fnl.push(union_pattern);

    functional& union_fnl = fregistry_resolve(get(builtin_qnid::union_));
    union_fnl.push(union_pattern);

    // apply(union(...), visitor) -> auto  
    functional& apply_fnl = fregistry_resolve(get(builtin_qnid::apply));
    apply_fnl.push(make_shared<union_apply_pattern>());

    // make_tuple(...) -> tuple(...)
    functional& make_tuple_fnl = fregistry_resolve(get(builtin_qnid::make_tuple));
    make_tuple_fnl.push(make_shared<tuple_make_pattern>());

    // make_array(of?, ...) -> array(of, size)
    functional& make_array_fnl = fregistry_resolve(get(builtin_qnid::make_array));
    make_array_fnl.push(make_shared<fixed_array_make_pattern>());
    make_array_fnl.push(make_shared<array_from_iterator_make_pattern>());

    functional& get_fnl = fregistry_resolve(get(builtin_qnid::get));
    get_fnl.push(make_shared<tuple_typename_get_pattern>());
    get_fnl.push(make_shared<tuple_get_pattern>());
    get_fnl.push(make_shared<fixed_array_get_pattern>());
    get_fnl.push(make_shared<tuple_project_get_pattern>());
    //get_fnl.push(make_shared<struct_get_pattern>());
    get_fnl.push(make_shared<enum_get_pattern>());


    functional& set_fnl = fregistry_resolve(get(builtin_qnid::set));
    set_fnl.push(make_shared<tuple_set_pattern>());
    set_fnl.push(make_shared<struct_set_pattern>());

    // size(signatured_entity)->integer
    functional& sz_fnl = fregistry_resolve(get(builtin_qnid::size));
    sz_fnl.push(make_shared<tuple_size_pattern>());
    sz_fnl.push(make_shared<tuple_project_size_pattern>());

    // __id(const string) -> __identifier
    functional& idfnl = fregistry_resolve(get(builtin_qnid::idfn));
    idfnl.push(make_shared<create_identifier_pattern>());

    // head(tuple(...)|array(...)) -> ???
    functional& head_fnl = fregistry_resolve(get(builtin_qnid::head));
    head_fnl.push(make_shared<tuple_head_pattern>());
    head_fnl.push(make_shared<fixed_array_head_pattern>());

    // tail(metaobject) -> @metaobject
    functional& tail_fnl = fregistry_resolve(get(builtin_qnid::tail));
    tail_fnl.push(make_shared<tuple_tail_pattern>());
    tail_fnl.push(make_shared<fixed_array_tail_pattern>());

    functional& empty_fnl = fregistry_resolve(get(builtin_qnid::empty));
    //empty_fnl.push(make_shared<metaobject_empty_pattern>());
    empty_fnl.push(make_shared<tuple_empty_pattern>());
    empty_fnl.push(make_shared<string_empty_pattern>());

    // is_const(_) -> const bool
    functional& is_const_fnl = fregistry_resolve(get(builtin_qnid::is_const));
    is_const_fnl.push(make_shared<is_const_pattern>());
    
    // new(type: typename $T @struct, ...) -> $T
    functional& newfnl = fregistry_resolve(get(builtin_qnid::new_));
    newfnl.push(make_shared<struct_new_pattern>());

    // Return register the string_concat pattern
    functional& string_concat_fnl = fregistry_resolve(get(builtin_qnid::string_concat));
    string_concat_fnl.push(make_shared<string_concat_pattern>());

    functional& init_fnl = fregistry_resolve(get(builtin_qnid::init));
    init_fnl.push(make_shared<struct_init_pattern>());

    // TRAITS/CONCEPTS
    functional& is_struct_fnl = fregistry_resolve(get(builtin_qnid::is_struct));
    is_struct_fnl.push(make_shared<is_struct_pattern>());

    functional& tuple_of_fnl = fregistry_resolve(get(builtin_qnid::tuple_of));
    tuple_of_fnl.push(make_shared<tuple_of_pattern>());

    //fn_result_identifier_ = make_identifier("->");

    //eq_qname_identifier_ = make_qname_identifier("==");
    //functional& eq_fnl = fregistry_resolve(eq_qname_identifier_);
    //eq_fnl.push(make_shared<eq_pattern>());

    builtin_eids_[(size_t)builtin_eid::arrayify] = set_builtin_extern("__arrayify(..., runtime integer)->tuple($0...)"sv, &annium_arrayify);
    builtin_eids_[(size_t)builtin_eid::unfold] = set_builtin_extern("__unfold(~runtime array(...))"sv, &annium_unfold);
    set_builtin_extern("__array_size(runtime)->u64"sv, &annium_array_size);
    builtin_eids_[(size_t)builtin_eid::array_tail] = set_builtin_extern("__array_tail(~runtime tuple(_, $t...))->tuple($t...)"sv, &annium_array_tail);
    builtin_eids_[(size_t)builtin_eid::array_at] = set_builtin_extern("__array_at()"sv, &annium_array_at);
    builtin_eids_[(size_t)builtin_eid::array_set_at] = set_builtin_extern("__array_set_at($arr: runtime, $index: runtime integer, $value)"sv, &annium_array_set_at);
    builtin_eids_[(size_t)builtin_eid::equal] = set_builtin_extern("__equal(runtime, runtime)->bool"sv, &annium_any_equal);
    builtin_eids_[(size_t)builtin_eid::assert] = set_builtin_extern("__assert(runtime)"sv, &annium_assert);
    builtin_eids_[(size_t)builtin_eid::string_empty] = set_builtin_extern("empty(runtime string)->bool"sv, &annium_string_empty);
    builtin_eids_[(size_t)builtin_eid::string_size] = set_builtin_extern("size(runtime string)->integer"sv, &annium_string_size);
    builtin_eids_[(size_t)builtin_eid::to_string] = set_builtin_extern("__to_string(runtime)->string"sv, &annium_tostring);
    builtin_eids_[(size_t)builtin_eid::logical_not] = set_builtin_extern("__logical_not(runtime)->bool"sv, &annium_logical_not);
    builtin_eids_[(size_t)builtin_eid::unary_minus] = set_builtin_extern("__unary_minus(runtime)"sv, &annium_unary_minus);
    builtin_eids_[(size_t)builtin_eid::concat] = set_builtin_extern("__concat(runtime)->string"sv, &annium_concat);
    builtin_eids_[(size_t)builtin_eid::error] = set_builtin_extern("__error(runtime string)"sv, &annium_error);
    builtin_eids_[(size_t)builtin_eid::get_frame_stack_height] = set_builtin_extern("__get_frame_stack_height()->integer"sv, &annium_get_frame_stack_height);
    //set_const_extern<to_string_pattern>("size(const metaobjct))->integer"sv);

    //set_extern<external_fn_pattern>("__error(mut string)"sv, &annium_error);
    set_builtin_extern("__print(runtime ..., runtime integer)"sv, &annium_print_string);

    //set_extern("implicit_cast(to: typename string, _)->string"sv, &annium_tostring);
    //set_const_extern<to_string_pattern>("to_string(const __identifier)->string"sv);
    //set_extern<external_fn_pattern>("to_string(_)->string"sv, &annium_tostring);
    builtin_eids_[(size_t)builtin_eid::to_integer] = set_builtin_extern("__to_integer(runtime)->integer"sv, &annium_to_integer);
    builtin_eids_[(size_t)builtin_eid::int2dec] = set_builtin_extern("__int2dec(runtime)->decimal"sv, &annium_int2dec);
    //set_extern<external_fn_pattern>("implicit_cast(mut integer)->float"sv, &annium_int2flt);
    set_builtin_extern("create_extern_object(runtime string)->object"sv, &annium_create_extern_object);
    set_builtin_extern("__extern_invoke(runtime string, runtime ..., runtime integer)~>$R"sv, &annium_invoke);
    set_builtin_extern("__extern_invoke(runtime string, runtime ..., runtime integer)~>()"sv, &annium_invoke_void);
    //set_extern<external_fn_pattern>("set(self: object, property: const __identifier, any)"sv, &annium_set_object_property);

    set_builtin_extern("set(self: object, property: runtime string, runtime)->object"sv, &annium_set_object_property);

    //set_extern("string(any)->string"sv, &annium_tostring);
    //set_extern<external_fn_pattern>("assert(bool)"sv, &annium_assert);

    // temporary
    
    //set_extern<external_fn_pattern>("negate(mut _)->bool"sv, &annium_negate);
    set_builtin_extern("__plus(runtime integer, runtime integer)~>integer"sv, &annium_operator_plus_integer);
    set_builtin_extern("__plus(runtime decimal, runtime decimal)~>decimal"sv, &annium_operator_plus_decimal);

    builtin_eids_[(size_t)builtin_eid::isubtract] = set_builtin_extern("__minus(runtime integer, runtime integer)~>integer"sv, &annium_operator_minus_integer);

}

intptr_t environment::retrieve_function_rt_identifier(internal_function_entity const& fn_ent)
{
    asm_builder_t& asm_builder = static_cast<asm_builder_t&>(*asm_builder_);
    asm_builder_t::function_descriptor& fd = asm_builder.resolve_function(vmasm::fn_identity<entity_identifier>{ fn_ent.id });
    //if (fd.address) return *fd.address;
    if (!fd.index) {
        fd.index = asm_builder.allocate_constant_index();
    }
    return static_cast<intptr_t>(*fd.index);
}

size_t environment::compile(internal_function_entity const& fn_ent)
{
    //GLOBAL_LOG_INFO() << "environment : compiling function: " << print(fn_ent.name());
    //fn_ent.body.for_each([this](semantic::expression const& e) {
    //    GLOBAL_LOG_INFO() << print(e); // << "\n"sv
    //});

    asm_builder_t& asm_builder = static_cast<asm_builder_t&>(*asm_builder_);
    asm_builder_t::function_descriptor& fd = asm_builder.resolve_function(vmasm::fn_identity<entity_identifier>{ fn_ent.id });
    if (!fd.address) {
        asm_builder_t::function_builder fb{ asm_builder, fd };

        vm::compiler_visitor vmcvis{ *this, fb, fn_ent };
        vmcvis(fn_ent.body);
        //if (!vmcvis.local_return_position) { // no explicit return
        //    fb.append_ret();
        //}
        fb.materialize();
        if (fd.index) {
            bvm().set_const(*fd.index, smart_blob{ ui64_blob_result(*fd.address) });
        }
        bvm().set_address_description(*fd.address, print(fn_ent));
    }
    
    return *fd.address;
}

}
