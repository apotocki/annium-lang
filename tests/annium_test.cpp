//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

#define TEST_FOLDER "annium_suite_test"

#include "sonia/config.hpp"

#include <fstream>
#include <iterator>

#include "sonia/small_vector.hpp"

#include "applied/sonia_test.hpp"

#include "sonia/filesystem.hpp"

#include "sonia/utility/parsers/json/lexertl_lexer.hpp"
#include "sonia/utility/parsers/json/model.hpp"
#include "sonia/utility/parsers/json/parser.hpp"

#include "applied/sonia_test.hpp"
#include "applied/scoped_services.hpp"

#include "annium/annium.hpp"

using namespace sonia;

namespace {

    void get_configuration(std::ostream& os)
    {
        os <<
            "{"
            "   hosts: ["
            "       {"
            "           name: 'default',"
            "           services: []"
            "       }"
            "   ],"
            "   services: {"
            "       http-static-application-factory: { factory: 'prime', layer: 0, parameters: {name: 'http-static'} },"
            "       http-connector-factory: { factory: 'prime', layer: 0, parameters: {name: 'http-server'} },"
            "       net-server-factory: { factory: 'prime', layer: 0, parameters: { name: 'net-server' } },"
            "       http-auth-factory: { factory: 'prime', layer: 0, parameters: {name: 'http-auth'} },"
            "       efs-factory: { factory: 'efs-core', layer: 0, parameters: { name: 'efs' } },"
            "       web-fe-factory: { factory: 'efs-core', layer: 0, parameters: {name: 'web-fe'} },"
            "       scheduler-factory: { factory: 'prime', layer: 0, parameters: { name: 'scheduler' } },"
            "       io-factory: { factory: 'prime', layer: 0, parameters: { name: 'io' } },"
            "       ui-factory: { factory: 'ui', layer: 0, parameters: { name: 'ui-manager' } }"
            "   },"
            "   bundles: {"
            "       prime: {lib: 'sonia-prime'}"
            "   }"
            "}";
    }
}
#if 0
struct pause_alloc_hook {
    _CRT_ALLOC_HOOK newhook_;
    pause_alloc_hook() : newhook_(_CrtSetAllocHook(0)) {}

    ~pause_alloc_hook() {
        _CrtSetAllocHook(newhook_);
    }
};

int counter = 0;
int AllocHook(int allocType, void* userData, size_t size, int
    blockType, long requestNumber, const unsigned char* filename, int
    lineNumber)
{
    if (size == 80) {
        pause_alloc_hook guard_;
        std::cout << size << ", req# " << requestNumber << ", c: " << counter << "\n";
        if (counter == 317) {
            int k = 0;
        }
        ++counter;
    }

    //if (!size) return TRUE;
    //pause_alloc_hook guard_;
    //std::cout << size << "\n";

    return TRUE;
}

#endif

void annium_suite_test()
{
    try {
#ifdef BOOST_WINDOWS
    system("cls");
#endif

    //_CrtSetAllocHook(AllocHook);
    //_CrtSetBreakAlloc(10282);

    scoped_services ss{ "base-path=" TEST_FOLDER "/" };
    std::stringstream cfgss;
    get_configuration(cfgss);

    sonia::services::load_configuration(cfgss);

    char const* path = std::getenv("TESTS_HOME");
    fs::path suitedir{ (path ? fs::path(path) : fs::path("..\\..\\tests")) / "test-suite" };
    fs::path suitefile = suitedir / "annium_suite.json";

    std::string suite_text;
    std::ifstream file(suitefile.string().c_str());
    std::copy(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>(), std::back_inserter(suite_text));

    parsers::json::model model;

    parsers::parse<
        parsers::json::light_lexertl_lexer,
        parsers::json::parser
    >(model, suite_text.c_str(), suite_text.c_str() + suite_text.size());
    
    json_value res = model.detach_result();
    auto testspan = res.get_array();
    for (json_value const& test_descr : testspan) {
        json_object test_obj = test_descr.get_object();
        auto filename = test_obj["src"]->get_u8string();
        fs::path srcpath = suitedir / filename;
        std::cout << srcpath.string() << "\n";

        boost::container::small_vector<string_view, 16> args;
        if (json_value* argsobj = test_obj["arguments"]; argsobj) {
            for (json_value const& arg : argsobj->get_array()) {
                args.emplace_back(arg.get_string());
            }
        }
        auto expected_output = test_obj["output"]->get_string();

        annium::language lang;
        std::ostringstream output;
        lang.set_cout_writer([&output](string_view str) { output << str; });
        lang.load(srcpath, args);

        BOOST_CHECK_EQUAL(expected_output, output.str());
    }

    } catch (std::exception const& ex) {
        std::cout << "Exception: \n" << boost::current_exception_diagnostic_information() << "\n";
        BOOST_CHECK(false);
    }
}

void annium_test_registrar()
{
    //register_test(BOOST_TEST_CASE(&annium_test));
    register_test(BOOST_TEST_CASE(&annium_suite_test));
}

#ifdef AUTO_TEST_REGISTRATION
AUTOTEST(annium_test_registrar)
#endif
