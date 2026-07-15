set (MODULE_HOME ${CMAKE_CURRENT_LIST_DIR}/../../..)

include_directories(${MODULE_HOME}/src)
include_directories(${MODULES}/sonia-prime)
include_directories(${MODULES}/dataforge/include)
include_directories(${MODULES}/numetron/include)
include_directories(${THIRD_PARTY}/lexertl14/include)
# Debug/Release specific definitions

add_compile_definitions(AUTO_TEST_REGISTRATION SONIA_NO_PRIME_BUNDLE SONIA_PRIME_STATIC SONIA_NO_NET SONIA_NO_BOOKKEEPER SONIA_NO_TENGER)

set (MODULE_NAME annium_tests)

set (ANNIUM_TESTS_SOURCES
    ${MODULES}/sonia-prime/applied/scoped_services.cpp
    ${MODULES}/sonia-prime/applied/tests_external.cpp
    ${MODULES}/sonia-prime/applied/tests_main.cpp
    
    ${MODULES}/sonia-prime/sonia/fibers/algo/algorithm.cpp
    ${MODULES}/sonia-prime/sonia/fibers/algo/round_robin.cpp
    ${MODULES}/sonia-prime/sonia/fibers/barrier.cpp
    ${MODULES}/sonia-prime/sonia/fibers/condition_variable.cpp
    ${MODULES}/sonia-prime/sonia/fibers/context.cpp
    ${MODULES}/sonia-prime/sonia/fibers/context_shared.cpp
    ${MODULES}/sonia-prime/sonia/fibers/default_stack.cpp
    ${MODULES}/sonia-prime/sonia/fibers/fiber.cpp
    ${MODULES}/sonia-prime/sonia/fibers/future.cpp
    ${MODULES}/sonia-prime/sonia/fibers/mutex.cpp
    ${MODULES}/sonia-prime/sonia/fibers/postponer.cpp
    ${MODULES}/sonia-prime/sonia/fibers/scheduler.cpp
    
    ${MODULES}/sonia-prime/sonia/logger/logger.cpp
    
    ${MODULES}/sonia-prime/sonia/utility/invocation/invocable.cpp
    ${MODULES}/sonia-prime/sonia/utility/invocation/invocation.cpp
    ${MODULES}/sonia-prime/sonia/utility/json/json_value.cpp
    ${MODULES}/sonia-prime/sonia/utility/parsers/json/json_model.cpp
    ${MODULES}/sonia-prime/sonia/utility/mvvm/view_model.cpp
    ${MODULES}/sonia-prime/sonia/utility/file_persister.cpp
    ${MODULES}/sonia-prime/sonia/utility/iterators/file_region_iterator.cpp
    ${MODULES}/sonia-prime/sonia/utility/assert_handler.cpp
    
    ${MODULES}/sonia-prime/sonia/services/service_locator.cpp
    ${MODULES}/sonia-prime/sonia/services/services.cpp
    ${MODULES}/sonia-prime/sonia/services/services_host.cpp
    ${MODULES}/sonia-prime/sonia/services/singleton_locator.cpp
    ${MODULES}/sonia-prime/sonia/services/durable_type_registry.cpp
    ${MODULES}/sonia-prime/sonia/services/environment.cpp
    ${MODULES}/sonia-prime/sonia/services/basic_service_factory.cpp
    ${MODULES}/sonia-prime/sonia/services/local_service_registry.cpp
    ${MODULES}/sonia-prime/sonia/services/local_type_registry.cpp
    ${MODULES}/sonia-prime/sonia/services/multimethod_registry.cpp
    #${MODULES}/sonia-prime/sonia/services/prime_bundle.cpp
    
    ${MODULES}/sonia-prime/sonia/sal/posix_sal.cpp
    ${MODULES}/sonia-prime/sonia/sys/posix/posix.cpp
    ${MODULES}/sonia-prime/sonia/sys/linux/signals.cpp
    ${MODULES}/sonia-prime/sonia/sys/linux/linux_timer.cpp
    ${MODULES}/sonia-prime/sonia/sys/linux/signals_api.cpp
    
    ${MODULE_HOME}/tests/annium_test.cpp
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
    set_property(SOURCE ${MODULE_HOME}/modules/sonia-prime/sonia/sal/posix_sal.cpp APPEND PROPERTY COMPILE_OPTIONS "-Wno-maybe-uninitialized")
endif()
