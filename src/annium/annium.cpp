//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#include "sonia/config.hpp"
#include "annium.hpp"

#include "environment.hpp"
#include "parser.hpp"

#include <fstream>
#include <iterator>

#include "vm/annium_vm.hpp"
#include "vm/image.hpp"
#include "library/library.hpp"
#include "library/chained_host.hpp"

#include "ast/fn_compiler_context.hpp"
#include "ast/declaration_visitor.hpp"

#include "entities/functions/internal_function_entity.hpp"
#include "entities/literals/literal_entity.hpp"

//#include "vm/compiler_visitor.hpp"

#include "sonia/utility/scope_exit.hpp"

// Per-load phase timing, logged once per load: bootstrap / parse / build_main / build_fns / codegen
// for sources, read / image for a precompiled image, then run. Define ANNIUM_LOAD_TIMING=0 to
// compile it out.
#ifndef ANNIUM_LOAD_TIMING
#   define ANNIUM_LOAD_TIMING 1
#endif

#if ANNIUM_LOAD_TIMING
#   include <algorithm>
#   include <chrono>
#   include <vector>
#   include <exception>
#   include <sstream>
#   define ANNIUM_TIMING_LAP(phase) if (timing_) timing_->lap(phase)
#else
#   define ANNIUM_TIMING_LAP(phase) ((void)0)
#endif

namespace annium::detail {

#if ANNIUM_LOAD_TIMING
class load_timing
{
    using clock = std::chrono::steady_clock;

public:
    explicit load_timing(std::string name)
        : name_{ std::move(name) }
        , start_{ clock::now() }
        , last_{ start_ }
        , uncaught_{ std::uncaught_exceptions() }
    {}

    load_timing(load_timing const&) = delete;
    load_timing& operator=(load_timing const&) = delete;

    ~load_timing()
    {
        try {
            bool failed = std::uncaught_exceptions() > uncaught_;
            GLOBAL_LOG_INFO() << "annium load '" << name_ << "'" << (failed ? " (failed)" : "")
                << ": total=" << ms(clock::now() - start_) << "ms" << laps_.str();
        } catch (...) {}
    }

    void lap(string_view phase)
    {
        auto now = clock::now();
        laps_ << ", " << phase << '=' << ms(now - last_) << "ms";
        last_ = now;
    }

    // the extern function calls of the run: their total and the most expensive ones
    void note_efn_profile(vm::efn_profile const& profile, vm::context const& ctx)
    {
        constexpr size_t top_count = 6;
        constexpr size_t max_name_size = 48;

        std::vector<size_t> indices;
        size_t calls = 0;
        clock::duration total{};
        for (size_t i = 0; i < profile.entries.size(); ++i) {
            auto const& e = profile.entries[i];
            if (!e.calls) continue;
            calls += e.calls;
            total += e.time;
            indices.push_back(i);
        }
        std::ranges::sort(indices, [&profile](size_t l, size_t r) { return profile.entries[l].time > profile.entries[r].time; });
        if (indices.size() > top_count) indices.resize(top_count);

        laps_ << " (efn " << ms(total) << "ms in " << calls << " calls:";
        for (size_t i : indices) {
            std::string name = ctx.ecall_describe(i);
            if (name.size() > max_name_size) name = name.substr(0, max_name_size) + "...";
            laps_ << ' ' << name << ' ' << profile.entries[i].calls << "x " << ms(profile.entries[i].time) << "ms;";
        }
        laps_ << ')';
    }

private:
    static long long ms(clock::duration d) { return std::chrono::duration_cast<std::chrono::milliseconds>(d).count(); }

    std::string name_;
    clock::time_point start_, last_;
    int uncaught_;
    std::ostringstream laps_;
};
#endif

//using annium::vm::compiler_visitor;

class annium_impl
{
public:
    //void build(fs::path const&);
    //void build(string_view code);
    void run(span<string_view> args);

    annium_impl();
    annium_impl(annium_impl const&) = delete;
    annium_impl& operator=(annium_impl const&) = delete;
    ~annium_impl();

    void set_cout_writer(function<void(string_view)> writer) { environment_->set_cout_writer(std::move(writer)); }
    void set_host(chained_host::parent_ref phost) { chained_host_->extend(std::move(phost)); }
    void load(fs::path const& srcfile, span<string_view> args = {});
    void load(string_view code, span<string_view> args = {});
    void build_image(fs::path const& srcfile, fs::path const& imagefile, bool strip);

    smart_blob invoke(blob_result& ftor, span<const blob_result> args) noexcept;
    smart_blob call(string_view name, span<const std::pair<string_view, const blob_result>> namedargs, span<const blob_result> args);

protected:
    // compiles the program, returns the address of its main function (not run yet)
    size_t compile(span<const statement>, span<string_view> args);
    void do_compile(internal_function_entity const&);
    void run_main(size_t address);

    void load_image(fs::path const& imagefile, span<string_view> args);
    void expect_sources();

    void bootstrap();

private:
    // A precompiled image is a complete program: it can only be loaded into an empty instance, and
    // nothing can be compiled into the instance after it (the compiler state is not in the image).
    enum class content { none, sources, image };
    content content_ = content::none;

    shared_ptr<environment> environment_ = make_shared<environment>();
    shared_ptr<chained_host> chained_host_ = make_shared<chained_host>();
    //optional<fn_compiler_context> default_ctx_;
    optional<internal_function_entity> main_function_;
    shared_ptr<internal_function_entity> main_fn_ent_; // the last compiled main function

    //asm_builder_t vmasm_;
    bool bootstrapped_ = false;

#if ANNIUM_LOAD_TIMING
    load_timing* timing_ = nullptr; // set only for the duration of a load()
#endif
};

}

namespace annium {

language::language()
    : impl_{make_shared<detail::annium_impl>()}
{

}

language::~language()
{

}

void language::set_cout_writer(function<void(string_view)> writer)
{
    impl_->set_cout_writer(std::move(writer));
}

void language::set_host(invocation::invocable* phost)
{
    impl_->set_host(phost);
}

void language::load(fs::path const& srcfile, span<string_view> args)
{
    impl_->load(srcfile, args);
}

void language::load(string_view code, span<string_view> args)
{
    impl_->load(code, args);
}

void language::build_image(fs::path const& srcfile, fs::path const& imagefile, bool strip)
{
    impl_->build_image(srcfile, imagefile, strip);
}

smart_blob language::invoke(blob_result& ftor, span<const blob_result> args) noexcept
{
    return impl_->invoke(ftor, args);
}

smart_blob language::call(string_view name, span<const std::pair<string_view, const blob_result>> namedargs, span<const blob_result> args)
{
    return impl_->call(name, namedargs, args);
}

}

namespace annium::detail {

using namespace annium;

#include "bootstrap_code.generated.hpp"

annium_impl::annium_impl()
{
    // consteval evaluation runs during compilation, deep inside declaration_visitor, with no
    // path back to annium_impl's own chained_host_ -- give environment_ a standing pointer to
    // the same host up front so it's there by the time any consteval expression needs it.
    environment_->set_compile_time_host(chained_host_.get());
}

annium_impl::~annium_impl()
{
    //default_ctx_ = nullopt;
}

void annium_impl::bootstrap()
{
    if (bootstrapped_) return;
    parser_context parser{ *environment_ };
    auto decls = parser.parse_string(string_view{ annium_bootstrap_code });
    if (!decls.has_value()) throw exception(decls.error());
    
    internal_function_entity dummy{ *environment_, qname{}, entity_signature{}, resource_location{}, field_descriptor{} };
    dummy.set_body(*decls);
    
    forward_declaration_visitor fdvis{ dummy.context() };
    if (auto res = fdvis.apply(*decls); !res)
        throw exception(environment_->print(*res.error()));

    declaration_visitor dvis{ dummy.context() };
    if (auto res = dvis.apply(*decls); !res)
        throw exception(environment_->print(*res.error()));
    auto res = dummy.context().finish_frame(dummy);
    if (!res) {
        throw exception(environment_->print(*res.error()));
    }

    bootstrapped_ = true;
}

void annium_impl::load(fs::path const& f, span<string_view> args)
{
#if ANNIUM_LOAD_TIMING
    load_timing timing{ f.generic_string() };
    timing_ = &timing;
    SCOPE_EXIT([this]() { timing_ = nullptr; });
#endif
    try {
        if (f.extension() == image_file_extension) {
            load_image(f, args);
            return;
        }
        expect_sources();
        bootstrap();
        ANNIUM_TIMING_LAP("bootstrap");
        parser_context parser{ *environment_ };
        auto decls = parser.parse(f);
        if (!decls.has_value()) throw exception(decls.error());
        ANNIUM_TIMING_LAP("parse");
        run_main(compile(std::move(*decls), args));
    } catch (error const& e) {
        throw exception(environment_->print(e));
    }
}

void annium_impl::load(string_view code, span<string_view> args)
{
#if ANNIUM_LOAD_TIMING
    // no file name here: identify the code by its size and first line
    string_view first_line = code.substr(0, std::min(code.find_first_of("\r\n"), size_t{ 60 }));
    load_timing timing{ "<code " + std::to_string(code.size()) + " bytes: " + std::string{ first_line } + ">" };
    timing_ = &timing;
    SCOPE_EXIT([this]() { timing_ = nullptr; });
#endif
    try {
        expect_sources();
        bootstrap();
        ANNIUM_TIMING_LAP("bootstrap");
        parser_context parser{ *environment_ };
        auto decls = parser.parse_string(code);
        if (!decls.has_value()) throw exception(decls.error());
        ANNIUM_TIMING_LAP("parse");
        run_main(compile(std::move(*decls), args));
    } catch (error const& e) {
        throw exception(environment_->print(e));
    }
}

void annium_impl::expect_sources()
{
    if (content_ == content::image) {
        throw exception("no code can be loaded after a precompiled annium image");
    }
    content_ = content::sources;
}

void annium_impl::build_image(fs::path const& srcfile, fs::path const& imagefile, bool strip)
{
    std::vector<uint8_t> image;
    try {
        expect_sources();
        bootstrap();
        parser_context parser{ *environment_ };
        auto decls = parser.parse(srcfile);
        if (!decls.has_value()) throw exception(decls.error());
        // compiled, not run: the image holds the machine state the program starts from
        size_t address = compile(std::move(*decls), {});
        image = save_image(environment_->bvm(), address, srcfile.filename().generic_string(), !strip);
    } catch (error const& e) {
        throw exception(environment_->print(e));
    }

    std::ofstream out{ imagefile, std::ios::binary | std::ios::trunc };
    out.write(reinterpret_cast<char const*>(image.data()), static_cast<std::streamsize>(image.size()));
    out.close();
    if (!out) {
        throw exception("can't write annium image '%1%'"_fmt % imagefile.generic_string());
    }
}

void annium_impl::load_image(fs::path const& f, span<string_view> args)
{
    std::string name = f.generic_string();
    if (!args.empty()) {
        throw exception("annium image '%1%': arguments are not supported for a precompiled image"_fmt % name);
    }
    if (content_ != content::none) {
        throw exception("annium image '%1%' can only be loaded into an empty language instance"_fmt % name);
    }

    std::ifstream in{ f, std::ios::binary };
    if (!in) {
        throw exception("can't open annium image '%1%'"_fmt % name);
    }
    std::vector<uint8_t> image(std::istreambuf_iterator<char>{ in }, std::istreambuf_iterator<char>{});
    if (in.bad()) {
        throw exception("can't read annium image '%1%'"_fmt % name);
    }
    ANNIUM_TIMING_LAP("read");

    size_t address = annium::load_image(environment_->bvm(), image, name);
    content_ = content::image;
    ANNIUM_TIMING_LAP("image");
    run_main(address);
}

void annium_impl::run_main(size_t address)
{
    vm::context vmctx{ *environment_, chained_host_.get() };
#if ANNIUM_LOAD_TIMING
    vm::efn_profile profile;
    if (timing_) vmctx.set_efn_profile(&profile);
#endif
    environment_->bvm().run(vmctx, address);
    ANNIUM_TIMING_LAP("run");
#if ANNIUM_LOAD_TIMING
    if (timing_) timing_->note_efn_profile(profile, vmctx);
#endif
}

size_t annium_impl::compile(span<const statement> decls, span<string_view> args)
{
    //identifier main_id = environment_->new_identifier();
    entity_signature main_sig{};
    auto main_fn_ent = make_shared<internal_function_entity>(*environment_, qname{/*main_id*/}, std::move(main_sig), resource_location{}, field_descriptor{});
    main_fn_ent->set_body(decls);
    fn_compiler_context ctx{ *environment_, *main_fn_ent };
    size_t argindex = 0;
    std::array<char, 16> argname = { '$' };
    for (string_view arg : args) {
        bool reversed = false;
        char * epos = numetron::to_string(span{ &argindex, 1 }, argname.data() + 1, reversed);
        if (reversed) std::reverse(argname.data() + 1, epos);

        entity const& argent = environment_->make_string_entity(arg);
        identifier argid = environment_->slregistry().resolve(string_view{ argname.data(), epos });
        functional& arg_fnl = environment_->fregistry_resolve(ctx.ns() / argid);
        arg_fnl.set_default_entity(annotated_entity_identifier{ argent.id, {} });
            
        //ctx.new_const_entity(string_view{ argname.data(), epos }, std::move(ent));
        ++argindex;
    }
    argname[1] = '$';
    entity const& argent = environment_->make_integer_entity(argindex);
    identifier argid = environment_->slregistry().resolve(string_view{ argname.data(), 2 });
    functional& arg_fnl = environment_->fregistry_resolve(ctx.ns() / argid);
    arg_fnl.set_default_entity(annotated_entity_identifier{ argent.id, {} });
        

    //if (!default_ctx_) {
    //    default_ctx_.emplace(environment_, qname{});
    //}

    // separate declarations
    // retrieve forward declarations
    //forward_declaration_visitor fdvis{ *default_ctx_, pctx };
    //for (auto& d : decls) {
    //    apply_visitor(fdvis, d);
    //}

    // main
    
    auto err = main_fn_ent->build(ctx);
    if (err) {
        throw exception(environment_->print(*err));
    }
    ANNIUM_TIMING_LAP("build_main");

    // at first built all functions, then compile them
    std::vector<internal_function_entity*> fns;
    environment_->eregistry_traverse([this, &fns](entity& e) {
        //GLOBAL_LOG_INFO() << environment_->print(e);
        if (auto* fe = dynamic_cast<internal_function_entity*>(&e); fe && !fe->is_provision()) {
            if (!fe->is_built()) {
                if (auto err = fe->build()) {
                    throw exception("function '%1%' build error:\n%2%"_fmt % environment_->print(fe->id) % environment_->print(*err));
                }
            }
            fns.push_back(fe);
        }
        return true;
    });
    ANNIUM_TIMING_LAP("build_fns");
    for (internal_function_entity* fe : fns) {
        //GLOBAL_LOG_INFO() << environment_->print(*fe);
        do_compile(*fe);
    }

    // all arguments referenced as constants => no fp prolog/epilog code
    size_t address = environment_->compile(*main_fn_ent);
#if ANNIUM_LOAD_TIMING
    if (timing_) timing_->lap("codegen(" + std::to_string(fns.size()) + " fns)");
#endif
#if 0
    asm_builder_t::function_descriptor& fd = vmasm_.resolve_function(vmasm::fn_identity<identifier>{ main_id });
    asm_builder_t::function_builder fb{ vmasm_, fd }; // = vmasm_.create_function(sonia::vmasm::fn_identity<identifier>{ main_id });
    vm::compiler_visitor vmcvis{ environment_, fb, main_fn_ent };
    //auto& bvm = environment_->bvm();
    //size_t main_address = bvm.get_ip();
    
    //std::ostringstream fn_code_str;
    //main_fn_ent.body.for_each([this, &fn_code_str](semantic::expression const& e) {
    //    fn_code_str << environment_->print(e);
    //});
    //GLOBAL_LOG_INFO() << "body expression:\n"sv << fn_code_str.str();

    vmcvis(main_fn_ent.body);

    if (!vmcvis.local_return_position) { // no explicit return
        fb.append_ret();
    }
    fb.materialize();
#endif
    // keep the main function entity alive until its code has been run, as before compile and run were split
    main_fn_ent_ = std::move(main_fn_ent);
    return address;

    //function_signature main_sig{ };
    //main_sig.position_parameters().emplace_back(annium_vector_t{ annium_string_t{} });
    //main_function_.emplace(entity_identifier{}, environment_->make_qname_identifier("main"sv), std::move(main_sig));
    //main_function_->body = std::move(ctx.expressions());
    //do_compile(vmcvis, *main_function_);
}

void annium_impl::do_compile(internal_function_entity const& fe)
{
    //GLOBAL_LOG_INFO() << "compiling function: " << environment_->print(fe.name());
    //fe.body.for_each([this](semantic::expression const& e) {
    //    GLOBAL_LOG_INFO() << environment_->print(e); // << "\n"sv
    //});

    if (!fe.is_built()) {
        auto err = const_cast<internal_function_entity&>(fe).build();
        if (err) {
            throw exception(environment_->print(*err));
        }
    }
    
    if (fe.is_inline() || fe.is_empty())
        return;

    environment_->compile(fe);
}

void annium_impl::run(span<string_view> args)
{
    vm::context ctx{ *environment_, chained_host_.get() };
    for (string_view arg : args) {
        smart_blob argblob{ string_blob_result(arg) };
        argblob.allocate();
        ctx.stack_push(std::move(argblob));
    }
    if (!args.empty()) {
        ctx.stack_push(ui64_blob_result(args.size()));
        annium_arrayify(ctx);
    } else {
        ctx.stack_push(nil_blob_result());
    }
    THROW_NOT_IMPLEMENTED_ERROR("annium_impl::run");
#if 0
    environment_->bvm().run(ctx, main_function_->get_address());
#endif
}

smart_blob annium_impl::call(string_view /*fnsig*/, span<const std::pair<string_view, const blob_result>> /*namedargs*/, span<const blob_result> args)
{
    smart_blob result;
    vm::context ctx{ *environment_, chained_host_.get() };
    for (blob_result const& arg : args) {
        ctx.stack_push(smart_blob(arg));
    }
    //qname_identifier qid = environment_->get_function_entity_identifier(fnsig);
    //span<qname_identifier> fnsig{};
    //identifier mandled_sig_id = environment_->piregistry().resolve(fnsig);
    //qname fnqn = qname{environment_->slregistry().resolve(name)} + mandled_sig_id;
    //qname_identifier qid = environment_->qnregistry().resolve(fnqn);
    THROW_NOT_IMPLEMENTED_ERROR("annium_impl::call");
#if 0
    auto ent = environment_->eregistry().find(qid);
    auto fnent = dynamic_pointer_cast<function_entity>(ent);
    if (!fnent) {
        throw exception("function '%1%' is not found"_fmt % fnsig);
    }
    if (fnent->signature().parameters_count() != args.size() + namedargs.size()) {
        throw exception("function '%1%' error: wrong number of arguments, expected: %2%, provided: %3%"_fmt % fnsig %
            fnent->signature().parameters_count() % (args.size() + namedargs.size()));
    }
    environment_->bvm().run(ctx, fnent->get_address());
    if (fnent->signature().fn_type.result != annium_tuple_t()) {
        result.replace(std::move(ctx.stack_back()));
        ctx.stack_pop();
    }
    return result;
#endif
}

smart_blob annium_impl::invoke(blob_result & ftor, span<const blob_result> args) noexcept
{
    try {
        vm::context ctx{ *environment_, chained_host_.get() };
        size_t init_stack_sz = ctx.stack_size();
        ctx.stack_push(smart_blob{ftor});
        annium_unfold(ctx);
        size_t cindex = ctx.stack_back().as<size_t>();
        size_t address = ctx.const_at(cindex).as<size_t>();
        ctx.stack_pop();
        for (auto const& arg : args) {
            ctx.stack_push(smart_blob(arg));
        }
        environment_->bvm().run(ctx, address);
        size_t final_stack_sz = ctx.stack_size();
        smart_blob result;
        if (final_stack_sz > init_stack_sz) {
            BOOST_ASSERT(final_stack_sz == init_stack_sz + 1);
            result = std::move(ctx.stack_back());
            ctx.stack_pop();
        }
        BOOST_ASSERT(ctx.stack_size() == init_stack_sz);
        return result;
    } catch (...) {
        GLOBAL_LOG_ERROR() << "Exception in annium_impl::invoke: " << boost::current_exception_diagnostic_information();
        return smart_blob{ error_blob_result(boost::current_exception_diagnostic_information()) };
    }
}

//void annium_impl::set_cout_writer(function<void(string_view)> writer)
//{
//    environment_->set_cout_writer(std::move(writer));
//}

}
