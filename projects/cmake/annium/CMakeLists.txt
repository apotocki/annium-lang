if (DEFINED COMMON_INCLUDE)
    include (${COMMON_INCLUDE})
endif()

include_directories(${ANNIUM_HOME}/src)
include_directories(${NUMETRON_HOME}/include)
include_directories(${DATAFORGE_HOME}/include)
include_directories(${SONIA_HOME})

# Debug/Release specific definitions
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(SONIA_LANG_DEBUG)
endif()

set (LIBRARY_NAME annium)
set (ANNIUM_SRC ${ANNIUM_HOME}/src)

# Generate bootstrap_code.generated.hpp from bootstrap.ann
set(BOOTSTRAP_ANN ${ANNIUM_SRC}/annium/bootstrap.ann)
set(BOOTSTRAP_HPP ${ANNIUM_SRC}/annium/bootstrap_code.generated.hpp)

add_custom_command(
    OUTPUT ${BOOTSTRAP_HPP}
    COMMAND ${CMAKE_COMMAND}
        -DINPUT_FILE=${BOOTSTRAP_ANN}
        -DOUTPUT_FILE=${BOOTSTRAP_HPP}
        -P ${ANNIUM_HOME}/projects/cmake/annium/generate_bootstrap.cmake
    DEPENDS ${BOOTSTRAP_ANN}
    COMMENT "Generating bootstrap_code.generated.hpp from bootstrap.ann"
)

set (LIBRARY_SOURCES
    ${ANNIUM_SRC}/annium/annium.cpp
    ${ANNIUM_SRC}/annium/annium.tab.cpp
    ${ANNIUM_SRC}/annium/annium.yy.cpp
    ${ANNIUM_SRC}/annium/annium_errors.cpp
    ${ANNIUM_SRC}/annium/annium_parser.cpp
    ${ANNIUM_SRC}/annium/annium_semantic.cpp
    ${ANNIUM_SRC}/annium/annium_environment.cpp
    ${ANNIUM_SRC}/annium/annium_auxiliary.cpp
    ${ANNIUM_SRC}/annium/ast/assign_expression_visitor.cpp
    ${ANNIUM_SRC}/annium/ast/ast_resource.cpp
    ${ANNIUM_SRC}/annium/ast/base_expression_visitor.cpp
    ${ANNIUM_SRC}/annium/ast/declaration_visitor.cpp
    ${ANNIUM_SRC}/annium/ast/fn_compiler_context.cpp
    ${ANNIUM_SRC}/annium/entities/functional_binding.cpp
    ${ANNIUM_SRC}/annium/entities/layered_binding_set.cpp
    ${ANNIUM_SRC}/annium/entities/prepared_call.cpp
    ${ANNIUM_SRC}/annium/entities/variable_entity.cpp
    
    ${ANNIUM_SRC}/annium/entities/array/array_from_iterator_make_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/array/array_implicit_cast_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/fixed_array/fixed_array_elements_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/fixed_array/fixed_array_make_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/fixed_array/fixed_array_head_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/fixed_array/fixed_array_tail_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/fixed_array/fixed_array_get_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/ellipsis/ellipsis_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/enum/enum_entity.cpp
    ${ANNIUM_SRC}/annium/entities/enum/enum_equal_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/enum/enum_get_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/enum/enum_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/enum/enum_implicit_runtime_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/enum/enum_to_integer_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/enum/enum_to_string_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/functions/expression_resolver.cpp
    ${ANNIUM_SRC}/annium/entities/functions/internal_function_entity.cpp
    
    ${ANNIUM_SRC}/annium/entities/callables/to_callable_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/callables/to_external_callable_implicit_cast_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/literals/numeric_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_equal_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_unary_minus_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/string/string_empty_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/string/string_concat_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/string/string_implicit_cast_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/struct/is_struct_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/struct/struct_entity.cpp
    ${ANNIUM_SRC}/annium/entities/struct/struct_fn_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/struct/struct_get_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/struct/struct_init_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/struct/struct_new_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/struct/struct_set_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/struct/tuple_of_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_empty_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_equal_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_get_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_head_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_make_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_pattern_base.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_project_get_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_project_size_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_set_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_size_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_tail_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_typename_get_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/union/to_union_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/union/union_apply_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/union/union_bit_or_pattern.cpp
    
    ${ANNIUM_SRC}/annium/functional/match_penalty.cpp
    ${ANNIUM_SRC}/annium/functional/functional.cpp
    ${ANNIUM_SRC}/annium/functional/basic_fn_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/external_fn_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/internal_fn_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/typefn_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/expression_property_visitor.cpp
    ${ANNIUM_SRC}/annium/functional/parameter_matcher.cpp
    ${ANNIUM_SRC}/annium/functional/pattern_matcher.cpp
        
    ${ANNIUM_SRC}/annium/functional/general/assert_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/create_identifier_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/deref_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/equal_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/error_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/is_const_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/logical_not_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/runtime_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/to_string_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/typeof_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/void_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/any_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/qname_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/reinterpret_any_pattern.cpp
    
    ${ANNIUM_SRC}/annium/errors/assign_error.cpp
    ${ANNIUM_SRC}/annium/errors/cast_error.cpp
    ${ANNIUM_SRC}/annium/errors/circular_dependency_error.cpp
    ${ANNIUM_SRC}/annium/errors/function_call_match_error.cpp
    ${ANNIUM_SRC}/annium/errors/identifier_redefinition_error.cpp
    ${ANNIUM_SRC}/annium/errors/no_position_argument_error.cpp
    ${ANNIUM_SRC}/annium/errors/pattern_match_error.cpp
    ${ANNIUM_SRC}/annium/errors/signature_name_mismatch_error.cpp
    ${ANNIUM_SRC}/annium/errors/type_mismatch_error.cpp
    ${ANNIUM_SRC}/annium/errors/value_mismatch_error.cpp
    
    ${ANNIUM_SRC}/annium/semantic/semantic_expression_printer.cpp

    ${ANNIUM_SRC}/annium/library/annium_library.cpp
    ${ANNIUM_SRC}/annium/library/annium_std.cpp
    ${ANNIUM_SRC}/annium/library/annium_chained_host.cpp
    ${ANNIUM_SRC}/annium/vm/annium_vm.cpp
    ${ANNIUM_SRC}/sonia/mvvm/annium_view_model.cpp
    ${ANNIUM_SRC}/sonia/mvvm/builder_view_model.cpp
    ${ANNIUM_SRC}/sonia/mvvm/bunch_builder_view_model.cpp
)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})
target_sources(${LIBRARY_NAME} PRIVATE ${BOOTSTRAP_HPP})

if(NOT DO_NOT_LINK_BOOST_HEADERS)
target_link_libraries(${LIBRARY_NAME} PRIVATE Boost::headers)
endif()

if(MSVC)
    target_compile_options(${LIBRARY_NAME} PRIVATE /W3 /MP)
    target_compile_options(${LIBRARY_NAME} PRIVATE /Zc:__cplusplus)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${LIBRARY_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-missing-field-initializers)

    set_property(SOURCE ${ANNIUM_SRC}/annium/annium.tab.cpp APPEND PROPERTY COMPILE_OPTIONS "-Wno-missing-field-initializers" "-Wno-unused-but-set-variable")
    set_property(SOURCE ${ANNIUM_SRC}/annium/annium.yy.cpp APPEND PROPERTY COMPILE_OPTIONS "-Wno-unused-function")
endif()
