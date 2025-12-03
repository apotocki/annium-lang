cmake_minimum_required(VERSION 3.16)

project(annium-lang VERSION 0.1.0 LANGUAGES CXX ASM)

set (PROJECT_HOME ${CMAKE_CURRENT_SOURCE_DIR})
set (TPLS ${CMAKE_CURRENT_SOURCE_DIR}/tpls)

# Set C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Debug information option
option(ENABLE_DEBUG_INFO "Enable debug information for GCC builds" OFF)

option(VALGRIND_BUILD "Build with Valgrind compatibility" OFF)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Find required packages
find_package(Boost REQUIRED COMPONENTS headers context log log_setup program_options thread unit_test_framework)
#find_package(PkgConfig REQUIRED)

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

# Compiler-specific options
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # GCC specific flags
    if(ENABLE_DEBUG_INFO)
        add_compile_options(-g3 -O0 -fno-omit-frame-pointer)
        message(STATUS "Debug information enabled for GCC build")
    else()
        # Default optimization for release builds
        if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
            add_compile_options(-O2)
        endif()
    endif()
    
    # Additional GCC flags for better debugging experience
    if(ENABLE_DEBUG_INFO)
        add_compile_options(-ggdb -fno-inline -fno-optimize-sibling-calls)
        add_link_options(-rdynamic)
    endif()
endif()

if(VALGRIND_BUILD AND UNIX AND NOT APPLE)
    find_program(VALGRIND_EXECUTABLE 
        NAMES valgrind
        PATHS /usr/bin /usr/local/bin /opt/local/bin
        DOC "Valgrind executable")

    find_path(VALGRIND_INCLUDE_DIR 
        NAMES valgrind.h
        PATHS 
            /usr/include/valgrind
            /usr/local/include/valgrind
            /opt/local/include/valgrind
        PATH_SUFFIXES valgrind)
    
    if(VALGRIND_EXECUTABLE AND VALGRIND_INCLUDE_DIR)
        message(STATUS "Valgrind found: ${VALGRIND_EXECUTABLE}")
        message(STATUS "Valgrind headers: ${VALGRIND_INCLUDE_DIR}")
    
        add_definitions(-DBOOST_USE_VALGRIND)
        add_definitions(-DBOOST_CONTEXT_USE_MAP_STACK)
        include_directories(${VALGRIND_INCLUDE_DIR})
    
        if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
            add_compile_options(-fno-omit-frame-pointer)
            add_compile_options(-fno-inline-functions-called-once)
            add_compile_options(-fno-inline-small-functions)
            add_compile_options(-fstack-protector)
        endif()
    else()
        message(WARNING "Valgrind not found properly:")
        message(WARNING "  Executable: ${VALGRIND_EXECUTABLE}")
        message(WARNING "  Headers: ${VALGRIND_INCLUDE_DIR}")
        message(FATAL_ERROR "Valgrind compatibility build requested but Valgrind not found")
    endif()

elseif(VALGRIND_BUILD)
    message(FATAL_ERROR "Valgrind compatibility build is only supported on Linux")
endif()

add_definitions(-DSONIA_PRIME_STATIC -DSONIA_NO_PRIME_BUNDLE -DAUTO_TEST_REGISTRATION)

# Platform-specific definitions
if(WIN32)
    add_definitions(-DBOOST_NO_USER_CONFIG -DBOOST_ALL_DYN_LINK -DBOOST_STACKTRACE_LINK)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/projects/cmake/annium)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tpls/numetron/lib)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/projects/cmake/annium_tests)


# Link Boost libraries to annium
#target_link_libraries(annium PUBLIC
#    Boost::system
#    Boost::filesystem
#    Boost::thread
#)

# Platform-specific linking for annium
#if(WIN32)
#    target_link_libraries(annium PRIVATE ws2_32 wsock32)
#elseif(UNIX)
#    target_link_libraries(annium PRIVATE pthread dl)
#endif()

# Filter sonia sources that exist on current platform


# Enable testing
#enable_testing()
#add_test(NAME annium_tests COMMAND tests)

# Install targets
#install(TARGETS annium tests
#    ARCHIVE DESTINATION lib
#    LIBRARY DESTINATION lib
#    RUNTIME DESTINATION bin
#)

# Install headers
#install(DIRECTORY src/annium/
#    DESTINATION include/annium
#    FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h"
#)

# Display configuration information
message(STATUS "")
message(STATUS "========== Build Configuration ==========")
message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "Version: ${PROJECT_VERSION}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Install Prefix: ${CMAKE_INSTALL_PREFIX}")
message(STATUS "Boost Version: ${Boost_VERSION}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Debug Info Enabled: ${ENABLE_DEBUG_INFO}")
message(STATUS "Valgrind Build: ${VALGRIND_BUILD}")
message(STATUS "========================================")
message(STATUS "")