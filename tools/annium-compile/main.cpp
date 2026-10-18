//  Annium programming language (c) 2025 by Alexander Pototskiy
//  Annium is licensed under the terms of the MIT License.

// annium-compile: compiles annium sources into precompiled images (.annc, see annium/vm/image.hpp).
//
// Usage: annium-compile <source.ann> <image.annc> [<source.ann> <image.annc> ...]
//
// Each source is compiled in its own language instance without a host, so a consteval expression
// that needs the host fails the compilation. Any error stops the tool with exit code 1.

#include "sonia/config.hpp"

#include <fstream>
#include <iostream>

#include "sonia/filesystem.hpp"
#include "applied/scoped_services.hpp"

#include "annium/annium.hpp"

using namespace sonia;

namespace {

// The services keep their registry files in the base path and want a logger configuration;
// both go to a scratch directory, the log shows warnings and errors on the console only.
std::string prepare_services_configuration()
{
    fs::path workdir = fs::temp_directory_path() / "annium-compile";
    fs::create_directories(workdir);

    fs::path logconf = workdir / "log.conf";
    std::ofstream{ logconf } <<
        "[Core]\n"
        "Filter = \"%Severity% >= warning\"\n"
        "[Sinks.Console]\n"
        "Destination = Console\n"
        "Format = \"%Severity%: %_%\"\n"
        "Asynchronous = false\n"
        "AutoFlush = true\n";

    return "base-path=" + workdir.generic_string() + "/\n"
        + "log=" + logconf.generic_string() + "\n";
}

}

int main(int argc, char const* argv[])
{
    if (argc < 3 || (argc - 1) % 2) {
        std::cerr << "usage: annium-compile <source.ann> <image.annc> [<source.ann> <image.annc> ...]\n";
        return 2;
    }

    try {
        scoped_services ss{ prepare_services_configuration() };

        for (int i = 1; i < argc; i += 2) {
            fs::path src{ argv[i] }, image{ argv[i + 1] };
            annium::language lang;
            lang.build_image(src, image);
            std::cout << src.generic_string() << " -> " << image.generic_string() << "\n";
        }
    } catch (std::exception const& e) {
        std::cerr << "annium-compile: " << e.what() << "\n";
        return 1;
    }
    return 0;
}
