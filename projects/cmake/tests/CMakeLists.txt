cmake_minimum_required(VERSION 3.16)

project(annium-lang VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Find required packages
find_package(Boost REQUIRED COMPONENTS system filesystem thread)
find_package(PkgConfig REQUIRED)

# vcpkg integration - try to find vcpkg installed dependencies
if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed)
    set(VCPKG_INSTALLED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed)
    if(WIN32)
        list(APPEND CMAKE_PREFIX_PATH ${VCPKG_INSTALLED_DIR}/x64-windows-cpp23)
        include_directories(${VCPKG_INSTALLED_DIR}/x64-windows-cpp23/include)
    elseif(UNIX AND NOT APPLE)
        list(APPEND CMAKE_PREFIX_PATH ${VCPKG_INSTALLED_DIR}/x64-linux)
        include_directories(${VCPKG_INSTALLED_DIR}/x64-linux/include)
    elseif(APPLE)
        list(APPEND CMAKE_PREFIX_PATH ${VCPKG_INSTALLED_DIR}/x64-osx)
        include_directories(${VCPKG_INSTALLED_DIR}/x64-osx/include)
    endif()
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/projects/cmake/annium)
# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tpls/sonia-prime)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tpls/lexertl14/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/tpls/dataforge/include)

# Platform-specific definitions
if(WIN32)
    add_definitions(-DSONIA_PRIME_STATIC -DBOOST_NO_USER_CONFIG -DBOOST_ALL_DYN_LINK -DBOOST_STACKTRACE_LINK)
endif()

# Debug/Release specific definitions
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DSONIA_LANG_DEBUG)
endif()

# Collect source files for annium library
file(GLOB_RECURSE ANNIUM_SOURCES
    src/annium/*.cpp
    src/annium/*.c
)

# Remove main.cpp if it exists (should be in tests only)
list(FILTER ANNIUM_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Collect header files for annium library  
file(GLOB_RECURSE ANNIUM_HEADERS
    src/annium/*.hpp
    src/annium/*.h
)

# Create annium static library
add_library(annium STATIC ${ANNIUM_SOURCES} ${ANNIUM_HEADERS})

# Set target properties for annium library
target_include_directories(annium PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/tpls/sonia-prime
    ${CMAKE_CURRENT_SOURCE_DIR}/tpls/lexertl14/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tpls/dataforge/include
)

# Link Boost libraries to annium
target_link_libraries(annium PUBLIC
    Boost::system
    Boost::filesystem
    Boost::thread
)

# Platform-specific linking for annium
if(WIN32)
    target_link_libraries(annium PRIVATE ws2_32 wsock32)
elseif(UNIX)
    target_link_libraries(annium PRIVATE pthread dl)
endif()

# Collect sonia-prime source files needed for tests
set(SONIA_PRIME_SOURCES
    tpls/sonia-prime/applied/scoped_services.cpp
    tpls/sonia-prime/applied/tests_external.cpp
    tpls/sonia-prime/applied/tests_main.cpp
    tpls/sonia-prime/sonia/fibers/algo/algorithm.cpp
    tpls/sonia-prime/sonia/fibers/algo/round_robin.cpp
    tpls/sonia-prime/sonia/fibers/barrier.cpp
    tpls/sonia-prime/sonia/fibers/condition_variable.cpp
    tpls/sonia-prime/sonia/fibers/context.cpp
    tpls/sonia-prime/sonia/fibers/fiber.cpp
    tpls/sonia-prime/sonia/fibers/future.cpp
    tpls/sonia-prime/sonia/fibers/mutex.cpp
    tpls/sonia-prime/sonia/fibers/postponer.cpp
    tpls/sonia-prime/sonia/fibers/scheduler.cpp
    tpls/sonia-prime/sonia/logger/logger.cpp
    tpls/sonia-prime/sonia/sal/windows_sal.cpp
    tpls/sonia-prime/sonia/services/basic_service_factory.cpp
    tpls/sonia-prime/sonia/services/bundle.cpp
    tpls/sonia-prime/sonia/services/durable_type_registry.cpp
    tpls/sonia-prime/sonia/services/environment.cpp
    tpls/sonia-prime/sonia/services/local_service_registry.cpp
    tpls/sonia-prime/sonia/services/local_type_registry.cpp
    tpls/sonia-prime/sonia/services/multimethod_registry.cpp
    tpls/sonia-prime/sonia/services/prime_bundle.cpp
    tpls/sonia-prime/sonia/services/service_locator.cpp
    tpls/sonia-prime/sonia/services/services.cpp
    tpls/sonia-prime/sonia/services/services_host.cpp
    tpls/sonia-prime/sonia/services/singleton_locator.cpp
    tpls/sonia-prime/sonia/sys/windows/thread_pool.cpp
    tpls/sonia-prime/sonia/sys/windows/thread_pool_api.cpp
    tpls/sonia-prime/sonia/sys/windows/windows.cpp
    tpls/sonia-prime/sonia/utility/assert_handler.cpp
    tpls/sonia-prime/sonia/utility/file_persister.cpp
    tpls/sonia-prime/sonia/utility/invocation/invocable.cpp
    tpls/sonia-prime/sonia/utility/invocation/invocation.cpp
    tpls/sonia-prime/sonia/utility/invocation/value_decoder.cpp
    tpls/sonia-prime/sonia/utility/invocation/value_encoder.cpp
    tpls/sonia-prime/sonia/utility/iterators/file_region_iterator.cpp
    tpls/sonia-prime/sonia/utility/json/json_value.cpp
    tpls/sonia-prime/sonia/utility/parsers/json/json_model.cpp
)

# Filter sonia sources that exist on current platform
set(SONIA_PRIME_SOURCES_FILTERED "")
foreach(SOURCE ${SONIA_PRIME_SOURCES})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE})
        # Skip Windows-specific files on non-Windows platforms
        if(NOT WIN32 AND ${SOURCE} MATCHES "windows")
            continue()
        endif()
        list(APPEND SONIA_PRIME_SOURCES_FILTERED ${SOURCE})
    endif()
endforeach()

# Test executable
set(TEST_SOURCES
    tests/annium_test.cpp
    ${SONIA_PRIME_SOURCES_FILTERED}
)

# Create tests executable
add_executable(tests ${TEST_SOURCES})

# Set target properties for tests
target_include_directories(tests PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/tpls/sonia-prime
    ${CMAKE_CURRENT_SOURCE_DIR}/tpls/lexertl14/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tpls/dataforge/include
    ${CMAKE_CURRENT_SOURCE_DIR}/tests
)

# Link annium library to tests
target_link_libraries(tests PRIVATE annium)

# Link Boost libraries to tests
target_link_libraries(tests PRIVATE
    Boost::system
    Boost::filesystem
    Boost::thread
)

# Platform-specific linking for tests
if(WIN32)
    target_link_libraries(tests PRIVATE ws2_32 wsock32)
elseif(UNIX)
    target_link_libraries(tests PRIVATE pthread dl)
    if(APPLE)
        # macOS specific libraries if needed
        target_link_libraries(tests PRIVATE)
    endif()
endif()

# Compiler-specific options
if(MSVC)
    target_compile_options(annium PRIVATE /W3 /MP)
    target_compile_options(tests PRIVATE /W3 /MP)
    # Enable C++14 conformance
    target_compile_options(annium PRIVATE /Zc:__cplusplus)
    target_compile_options(tests PRIVATE /Zc:__cplusplus)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(annium PRIVATE -Wall -Wextra -pedantic)
    target_compile_options(tests PRIVATE -Wall -Wextra -pedantic)
endif()

# Enable testing
enable_testing()
add_test(NAME annium_tests COMMAND tests)

# Install targets
install(TARGETS annium tests
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install headers
install(DIRECTORY src/annium/
    DESTINATION include/annium
    FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h"
)

# Display configuration information
message(STATUS "")
message(STATUS "========== Build Configuration ==========")
message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install Prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Boost Version: ${Boost_VERSION}")
message(STATUS "========================================")
message(STATUS "")