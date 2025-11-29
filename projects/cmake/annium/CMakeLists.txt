
include_directories(${PROJECT_HOME}/src)
include_directories(${TPLS}/sonia-prime)
include_directories(${TPLS}/lexertl14/include)
include_directories(${TPLS}/dataforge/include)
include_directories(${TPLS}/numetron/include)

# Debug/Release specific definitions
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DSONIA_LANG_DEBUG)
endif()

set (LIBRARY_NAME annium)
set (LIBRARY_HOME ${PROJECT_HOME}/src)

set (LIBRARY_SOURCES2
    ${LIBRARY_HOME}/annium/annium.cpp
    ${LIBRARY_HOME}/annium/annium.tab.cpp
    ${LIBRARY_HOME}/annium/annium.yy.cpp
    ${LIBRARY_HOME}/annium/annium_errors.cpp
    ${LIBRARY_HOME}/annium/annium_parser.cpp
    ${LIBRARY_HOME}/annium/annium_semantic.cpp
    ${LIBRARY_HOME}/annium/annium_environment.cpp
    ${LIBRARY_HOME}/annium/annium_auxiliary.cpp
    ${LIBRARY_HOME}/annium/ast/assign_expression_visitor.cpp
    ${LIBRARY_HOME}/annium/ast/ast_resource.cpp
    ${LIBRARY_HOME}/annium/ast/base_expression_visitor.cpp
    ${LIBRARY_HOME}/annium/ast/declaration_visitor.cpp
    ${LIBRARY_HOME}/annium/ast/fn_compiler_context.cpp
    ${LIBRARY_HOME}/annium/entities/functional.cpp
    ${LIBRARY_HOME}/annium/entities/prepared_call.cpp
    ${LIBRARY_HOME}/annium/entities/variable_entity.cpp
    
    ${LIBRARY_HOME}/annium/entities/array/array_from_iterator_make_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/array/array_implicit_cast_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/fixed_array/fixed_array_elements_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/fixed_array/fixed_array_make_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/fixed_array/fixed_array_head_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/fixed_array/fixed_array_tail_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/fixed_array/fixed_array_get_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/ellipsis/ellipsis_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/enum/enum_entity.cpp
    ${LIBRARY_HOME}/annium/entities/enum/enum_equal_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/enum/enum_get_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/enum/enum_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/enum/enum_to_integer_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/enum/enum_to_string_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/functions/expression_resolver.cpp
    ${LIBRARY_HOME}/annium/entities/functions/internal_function_entity.cpp
    
    ${LIBRARY_HOME}/annium/entities/callables/to_callable_implicit_cast_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/literals/numeric_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/literals/numeric_literal_equal_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/literals/numeric_literal_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/literals/numeric_literal_unary_minus_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/literals/string_concat_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/literals/string_implicit_cast_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/struct/is_struct_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_entity.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_fn_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_get_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_init_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_new_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_set_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/tuple_of_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_empty_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_equal_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_get_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_head_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_make_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_pattern_base.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_project_get_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_project_size_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_set_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_size_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_tail_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_typename_get_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/union/to_union_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/union/union_apply_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/union/union_bit_or_pattern.cpp
    
    ${LIBRARY_HOME}/annium/functional/basic_fn_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/external_fn_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/internal_fn_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/typefn_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/expression_property_visitor.cpp
    ${LIBRARY_HOME}/annium/functional/parameter_matcher.cpp
    ${LIBRARY_HOME}/annium/functional/pattern_matcher.cpp
    
    ${LIBRARY_HOME}/annium/functional/general/assert_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/create_identifier_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/deref_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/equal_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/error_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/is_const_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/logical_not_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/runtime_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/to_string_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/typeof_pattern.cpp
    
    ${LIBRARY_HOME}/annium/errors/assign_error.cpp
    ${LIBRARY_HOME}/annium/errors/cast_error.cpp
    ${LIBRARY_HOME}/annium/errors/circular_dependency_error.cpp
    ${LIBRARY_HOME}/annium/errors/function_call_match_error.cpp
    ${LIBRARY_HOME}/annium/errors/identifier_redefinition_error.cpp
    ${LIBRARY_HOME}/annium/errors/no_position_argument_error.cpp
    ${LIBRARY_HOME}/annium/errors/pattern_match_error.cpp
    ${LIBRARY_HOME}/annium/errors/signature_name_mismatch_error.cpp
    ${LIBRARY_HOME}/annium/errors/type_mismatch_error.cpp
    ${LIBRARY_HOME}/annium/errors/value_mismatch_error.cpp
    
    ${LIBRARY_HOME}/annium/semantic/semantic_expression_printer.cpp

    ${LIBRARY_HOME}/annium/library/annium_library.cpp
    ${LIBRARY_HOME}/annium/vm/annium_vm.cpp
    ${LIBRARY_HOME}/sonia/mvvm/annium_view_model.cpp
    ${LIBRARY_HOME}/sonia/mvvm/builder_view_model.cpp
    ${LIBRARY_HOME}/sonia/mvvm/bunch_builder_view_model.cpp
)

set (LIBRARY_SOURCES
    ${LIBRARY_HOME}/annium/annium.cpp
    ${LIBRARY_HOME}/annium/annium.tab.cpp
    ${LIBRARY_HOME}/annium/annium.yy.cpp
    ${LIBRARY_HOME}/annium/annium_errors.cpp
    ${LIBRARY_HOME}/annium/annium_parser.cpp
    ${LIBRARY_HOME}/annium/annium_semantic.cpp
    ${LIBRARY_HOME}/annium/annium_environment.cpp
    ${LIBRARY_HOME}/annium/annium_auxiliary.cpp
    ${LIBRARY_HOME}/annium/ast/assign_expression_visitor.cpp
    ${LIBRARY_HOME}/annium/ast/base_expression_visitor.cpp
    ${LIBRARY_HOME}/annium/ast/declaration_visitor.cpp
    ${LIBRARY_HOME}/annium/ast/fn_compiler_context.cpp
    ${LIBRARY_HOME}/annium/entities/functional.cpp
    ${LIBRARY_HOME}/annium/entities/prepared_call.cpp
    ${LIBRARY_HOME}/annium/entities/variable_entity.cpp
    
    ${LIBRARY_HOME}/annium/entities/array/array_from_iterator_make_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/array/array_implicit_cast_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/fixed_array/fixed_array_elements_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/fixed_array/fixed_array_make_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/fixed_array/fixed_array_head_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/fixed_array/fixed_array_tail_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/fixed_array/fixed_array_get_pattern.cpp

    ${LIBRARY_HOME}/annium/entities/ellipsis/ellipsis_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/enum/enum_entity.cpp
    ${LIBRARY_HOME}/annium/entities/enum/enum_equal_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/enum/enum_get_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/enum/enum_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/enum/enum_to_integer_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/enum/enum_to_string_pattern.cpp
    
    ${LIBRARY_HOME}/annium/entities/functions/expression_resolver.cpp
    ${LIBRARY_HOME}/annium/entities/functions/internal_function_entity.cpp
    
    ${LIBRARY_HOME}/annium/entities/literals/numeric_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/literals/numeric_literal_equal_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/literals/numeric_literal_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/literals/numeric_literal_unary_minus_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/literals/string_concat_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/literals/string_implicit_cast_pattern.cpp

    ${LIBRARY_HOME}/annium/entities/struct/is_struct_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_entity.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_fn_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_get_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_init_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_new_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/struct_set_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/struct/tuple_of_pattern.cpp

    ${LIBRARY_HOME}/annium/entities/tuple/tuple_empty_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_equal_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_get_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_head_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_make_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_pattern_base.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_project_get_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_project_size_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_set_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_size_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_tail_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/tuple/tuple_typename_get_pattern.cpp

    ${LIBRARY_HOME}/annium/entities/union/to_union_implicit_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/union/union_apply_pattern.cpp
    ${LIBRARY_HOME}/annium/entities/union/union_bit_or_pattern.cpp
    
    ${LIBRARY_HOME}/annium/functional/basic_fn_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/internal_fn_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/external_fn_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/typefn_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/pattern_matcher.cpp
    ${LIBRARY_HOME}/annium/functional/parameter_matcher.cpp
    

    ${LIBRARY_HOME}/annium/functional/general/assert_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/create_identifier_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/deref_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/equal_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/error_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/is_const_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/logical_not_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/runtime_cast_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/to_string_pattern.cpp
    ${LIBRARY_HOME}/annium/functional/general/typeof_pattern.cpp

    ${LIBRARY_HOME}/annium/errors/assign_error.cpp
    ${LIBRARY_HOME}/annium/errors/cast_error.cpp
    ${LIBRARY_HOME}/annium/errors/circular_dependency_error.cpp
    ${LIBRARY_HOME}/annium/errors/function_call_match_error.cpp
    ${LIBRARY_HOME}/annium/errors/identifier_redefinition_error.cpp
    ${LIBRARY_HOME}/annium/errors/no_position_argument_error.cpp
    ${LIBRARY_HOME}/annium/errors/pattern_match_error.cpp
    ${LIBRARY_HOME}/annium/errors/signature_name_mismatch_error.cpp
    ${LIBRARY_HOME}/annium/errors/type_mismatch_error.cpp
    ${LIBRARY_HOME}/annium/errors/value_mismatch_error.cpp

    ${LIBRARY_HOME}/annium/semantic/semantic_expression_printer.cpp

    ${LIBRARY_HOME}/annium/library/annium_library.cpp
    ${LIBRARY_HOME}/annium/vm/annium_vm.cpp
)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES2})

target_link_libraries(${LIBRARY_NAME} PRIVATE Boost::headers)

if(MSVC)
    target_compile_options(${LIBRARY_NAME} PRIVATE /W3 /MP)
    target_compile_options(${LIBRARY_NAME} PRIVATE /Zc:__cplusplus)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${LIBRARY_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-missing-field-initializers)

    set_property(SOURCE ${LIBRARY_HOME}/annium/annium.tab.cpp APPEND PROPERTY COMPILE_OPTIONS "-Wno-missing-field-initializers")
    set_property(SOURCE ${LIBRARY_HOME}/annium/annium.yy.cpp APPEND PROPERTY COMPILE_OPTIONS "-Wno-unused-function")
endif()
