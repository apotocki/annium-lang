
include_directories(${PROJECT_HOME}/src)
include_directories(${TPLS}/sonia-prime)
include_directories(${TPLS}/lexertl14/include)
include_directories(${TPLS}/dataforge/include)
include_directories(${TPLS}/numetron/include)

# Debug/Release specific definitions

add_definitions(-DAUTO_TEST_REGISTRATION -DSONIA_NO_PRIME_BUNDLE -DSONIA_PRIME_STATIC -DSONIA_NO_NET -DSONIA_NO_BOOKKEEPER -DSONIA_NO_TENGER)

set (MODULE_NAME annium_tests)

set (ANNIUM_TESTS_SOURCES
    ${PROJECT_HOME}/tpls/sonia-prime/applied/scoped_services.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/applied/tests_external.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/applied/tests_main.cpp
    
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/algo/algorithm.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/algo/round_robin.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/barrier.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/condition_variable.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/context.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/context_shared.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/fiber.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/future.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/mutex.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/postponer.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/fibers/scheduler.cpp
    
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/logger/logger.cpp
    
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/utility/invocation/invocable.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/utility/invocation/invocation.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/utility/json/json_value.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/utility/parsers/json/json_model.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/utility/mvvm/view_model.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/utility/file_persister.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/utility/iterators/file_region_iterator.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/utility/assert_handler.cpp
    
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/services/service_locator.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/services/services.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/services/services_host.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/services/singleton_locator.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/services/durable_type_registry.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/services/environment.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/services/basic_service_factory.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/services/local_service_registry.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/services/local_type_registry.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/services/multimethod_registry.cpp
    #${PROJECT_HOME}/tpls/sonia-prime/sonia/services/prime_bundle.cpp
    
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/sal/posix_sal.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/sys/posix/posix.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/sys/linux/signals.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/sys/linux/linux_timer.cpp
    ${PROJECT_HOME}/tpls/sonia-prime/sonia/sys/linux/signals_api.cpp
    ${PROJECT_HOME}/tests/annium_test.cpp
)

add_executable(${MODULE_NAME} ${ANNIUM_TESTS_SOURCES})

# Link annium library to tests
target_link_libraries(${MODULE_NAME} PRIVATE annium numetron)

# Link Boost libraries to tests
target_link_libraries(${MODULE_NAME} PRIVATE 
    Boost::headers
    Boost::context
    Boost::log
    Boost::log_setup
    Boost::program_options
    Boost::unit_test_framework
)

#target_link_libraries(${MODULE_NAME} PRIVATE
#    Boost::system
#    Boost::filesystem
#    Boost::thread
#)

if(MSVC)
    target_compile_options(${MODULE_NAME} PRIVATE /W3 /MP)
    target_compile_options(${MODULE_NAME} PRIVATE /Zc:__cplusplus)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${MODULE_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-missing-field-initializers)
    set_property(SOURCE ${PROJECT_HOME}/tpls/sonia-prime/sonia/sal/posix_sal.cpp APPEND PROPERTY COMPILE_OPTIONS "-Wno-maybe-uninitialized")
endif()
