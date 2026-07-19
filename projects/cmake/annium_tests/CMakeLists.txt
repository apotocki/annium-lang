include_directories(${ANNIUM_HOME}/src)
include_directories(${DATAFORGE_HOME}/include)
include_directories(${NUMETRON_HOME}/include)
include_directories(${SONIA_HOME})
include_directories(${THIRD_PARTY}/lexertl14/include)

# Debug/Release specific definitions
add_compile_definitions(AUTO_TEST_REGISTRATION SONIA_NO_PRIME_BUNDLE SONIA_PRIME_STATIC SONIA_NO_NET SONIA_NO_BOOKKEEPER SONIA_NO_TENGER)

set (MODULE_NAME annium_tests)

set (ANNIUM_TESTS_SOURCES
    ${SONIA_HOME}/applied/scoped_services.cpp
    ${SONIA_HOME}/applied/tests_external.cpp
    ${SONIA_HOME}/applied/tests_main.cpp
    
    ${SONIA_HOME}/sonia/fibers/algo/algorithm.cpp
    ${SONIA_HOME}/sonia/fibers/algo/round_robin.cpp
    ${SONIA_HOME}/sonia/fibers/barrier.cpp
    ${SONIA_HOME}/sonia/fibers/condition_variable.cpp
    ${SONIA_HOME}/sonia/fibers/context.cpp
    ${SONIA_HOME}/sonia/fibers/context_shared.cpp
    ${SONIA_HOME}/sonia/fibers/default_stack.cpp
    ${SONIA_HOME}/sonia/fibers/fiber.cpp
    ${SONIA_HOME}/sonia/fibers/future.cpp
    ${SONIA_HOME}/sonia/fibers/mutex.cpp
    ${SONIA_HOME}/sonia/fibers/postponer.cpp
    ${SONIA_HOME}/sonia/fibers/scheduler.cpp
    
    ${SONIA_HOME}/sonia/logger/logger.cpp
    
    ${SONIA_HOME}/sonia/utility/invocation/invocable.cpp
    ${SONIA_HOME}/sonia/utility/invocation/invocation.cpp
    ${SONIA_HOME}/sonia/utility/json/json_value.cpp
    ${SONIA_HOME}/sonia/utility/parsers/json/json_model.cpp
    ${SONIA_HOME}/sonia/utility/mvvm/view_model.cpp
    ${SONIA_HOME}/sonia/utility/file_persister.cpp
    ${SONIA_HOME}/sonia/utility/iterators/file_region_iterator.cpp
    ${SONIA_HOME}/sonia/utility/assert_handler.cpp
    
    ${SONIA_HOME}/sonia/services/service_locator.cpp
    ${SONIA_HOME}/sonia/services/services.cpp
    ${SONIA_HOME}/sonia/services/services_host.cpp
    ${SONIA_HOME}/sonia/services/singleton_locator.cpp
    ${SONIA_HOME}/sonia/services/durable_type_registry.cpp
    ${SONIA_HOME}/sonia/services/environment.cpp
    ${SONIA_HOME}/sonia/services/basic_service_factory.cpp
    ${SONIA_HOME}/sonia/services/local_service_registry.cpp
    ${SONIA_HOME}/sonia/services/local_type_registry.cpp
    ${SONIA_HOME}/sonia/services/multimethod_registry.cpp
    #${SONIA_HOME}/sonia/services/prime_bundle.cpp
    
    ${SONIA_HOME}/sonia/sal/posix_sal.cpp
    ${SONIA_HOME}/sonia/sys/posix/posix.cpp
    ${SONIA_HOME}/sonia/sys/linux/signals.cpp
    ${SONIA_HOME}/sonia/sys/linux/linux_timer.cpp
    ${SONIA_HOME}/sonia/sys/linux/signals_api.cpp
    
    ${ANNIUM_HOME}/tests/annium_test.cpp
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
    set_property(SOURCE ${SONIA_HOME}/sonia/sal/posix_sal.cpp APPEND PROPERTY COMPILE_OPTIONS "-Wno-maybe-uninitialized")
endif()
