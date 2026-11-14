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

# The parser, generated in the build directory and never committed: annium.tab.cpp, annium.tab.hpp and location.hh by
# Bison from annium.y, annium.yy.cpp and annium.yy.hpp by flex from annium.l. The programs: BISON_EXECUTABLE and
# FLEX_EXECUTABLE when given (the recipes of otok pass those of their toolchains), else the ones `otok install` delivers
# into Otok/tools/ of annium-lang (otok.toml, otok-tools.cmake), else bison and flex of PATH.
set(ANNIUM_OTOK_TOOLS ${ANNIUM_HOME}/Otok/tools/otok-tools.cmake)
if (EXISTS ${ANNIUM_OTOK_TOOLS})
    include(${ANNIUM_OTOK_TOOLS})
    if (DEFINED Otok_TOOL_bison AND NOT BISON_EXECUTABLE)
        set(BISON_EXECUTABLE ${Otok_TOOL_bison} CACHE FILEPATH "bison, which generates the parser of annium" FORCE)
    endif()
    if (DEFINED Otok_TOOL_flex AND NOT FLEX_EXECUTABLE)
        set(FLEX_EXECUTABLE ${Otok_TOOL_flex} CACHE FILEPATH "flex, which generates the scanner of annium" FORCE)
    endif()
endif()
# Bison 3.8: the generated parser is the same as the one annium.vcxproj makes with win_bison of winflexbison
find_package(BISON 3.8 REQUIRED)
find_package(FLEX 2.6 REQUIRED)

set(ANNIUM_PARSER_DIR ${CMAKE_CURRENT_BINARY_DIR}/parser)
file(MAKE_DIRECTORY ${ANNIUM_PARSER_DIR})
set(ANNIUM_PARSER_SOURCES ${ANNIUM_PARSER_DIR}/annium.tab.cpp ${ANNIUM_PARSER_DIR}/annium.yy.cpp)
add_custom_command(
    OUTPUT ${ANNIUM_PARSER_DIR}/annium.tab.cpp ${ANNIUM_PARSER_DIR}/annium.tab.hpp ${ANNIUM_PARSER_DIR}/location.hh
    COMMAND ${BISON_EXECUTABLE} -d -v -Wother -Wcounterexamples --output=annium.tab.cpp ${ANNIUM_SRC}/annium/annium.y
    DEPENDS ${ANNIUM_SRC}/annium/annium.y
    WORKING_DIRECTORY ${ANNIUM_PARSER_DIR}
    COMMENT "Generating annium.tab.cpp, annium.tab.hpp and location.hh from annium.y with bison"
    VERBATIM
)
# annium.l names its outputs (%option outfile, header-file), written in the working directory
add_custom_command(
    OUTPUT ${ANNIUM_PARSER_DIR}/annium.yy.cpp ${ANNIUM_PARSER_DIR}/annium.yy.hpp
    COMMAND ${FLEX_EXECUTABLE} --nounistd ${ANNIUM_SRC}/annium/annium.l
    DEPENDS ${ANNIUM_SRC}/annium/annium.l
    WORKING_DIRECTORY ${ANNIUM_PARSER_DIR}
    COMMENT "Generating annium.yy.cpp and annium.yy.hpp from annium.l with flex"
    VERBATIM
)
# the generated sources include parser.hpp and the other headers of src/annium; annium_parser.cpp includes the generated
# headers
set_source_files_properties(${ANNIUM_PARSER_SOURCES} PROPERTIES INCLUDE_DIRECTORIES ${ANNIUM_SRC}/annium)
set_source_files_properties(${ANNIUM_SRC}/annium/annium_parser.cpp PROPERTIES INCLUDE_DIRECTORIES ${ANNIUM_PARSER_DIR})

set (LIBRARY_SOURCES
    ${ANNIUM_SRC}/annium/annium.cpp
    ${ANNIUM_PARSER_SOURCES}
    ${ANNIUM_PARSER_DIR}/annium.tab.hpp
    ${ANNIUM_PARSER_DIR}/annium.yy.hpp
    ${ANNIUM_PARSER_DIR}/location.hh
    ${ANNIUM_SRC}/annium/annium_errors.cpp
    ${ANNIUM_SRC}/annium/annium_parser.cpp
    ${ANNIUM_SRC}/annium/annium_semantic.cpp
    ${ANNIUM_SRC}/annium/annium_environment.cpp
    ${ANNIUM_SRC}/annium/annium_auxiliary.cpp
    ${ANNIUM_SRC}/annium/ast/ast_resource.cpp
    ${ANNIUM_SRC}/annium/ast/base_expression_visitor.cpp
    ${ANNIUM_SRC}/annium/ast/consteval_evaluator.cpp
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

    ${ANNIUM_SRC}/annium/entities/functions/expression_resolver.cpp
    ${ANNIUM_SRC}/annium/entities/functions/internal_function_entity.cpp
    
    ${ANNIUM_SRC}/annium/entities/callables/to_callable_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/callables/to_external_callable_implicit_cast_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/literals/numeric_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_equal_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_unary_minus_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_plus_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_minus_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_mul_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_div_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_mod_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_bit_and_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_literal_bit_or_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_promotion.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/numeric_cast_constexpr_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/string/string_empty_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/string/string_concat_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/literals/string/string_implicit_cast_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/struct/is_struct_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/struct/struct_entity.cpp
    ${ANNIUM_SRC}/annium/entities/struct/struct_fn_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/struct/struct_init_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/struct/struct_new_pattern.cpp
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
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_size_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_tail_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/tuple/tuple_typename_get_pattern.cpp
    
    ${ANNIUM_SRC}/annium/entities/union/to_union_implicit_cast_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/union/union_apply_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/union/union_bit_or_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/union/union_to_integer_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/union/union_get_pattern.cpp
    ${ANNIUM_SRC}/annium/entities/union/union_typeof_pattern.cpp

    ${ANNIUM_SRC}/annium/functional/match_penalty.cpp
    ${ANNIUM_SRC}/annium/functional/functional.cpp
    ${ANNIUM_SRC}/annium/functional/basic_fn_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/builtin_fn_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/extern_fn_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/internal_fn_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/typefn_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/expression_property_visitor.cpp
    ${ANNIUM_SRC}/annium/functional/parameter_matcher.cpp
    ${ANNIUM_SRC}/annium/functional/pattern_matcher.cpp
        
    ${ANNIUM_SRC}/annium/functional/general/assert_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/bool_bit_and_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/bool_bit_or_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/create_identifier_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/deref_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/ref_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/rebind_pattern.cpp
    ${ANNIUM_SRC}/annium/functional/general/deref_call_pattern.cpp
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
    ${ANNIUM_SRC}/annium/errors/concept_not_satisfied_error.cpp
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
    ${ANNIUM_SRC}/annium/vm/image.cpp
    ${ANNIUM_SRC}/sonia/mvvm/annium_view_model.cpp
    ${ANNIUM_SRC}/sonia/mvvm/builder_view_model.cpp
    ${ANNIUM_SRC}/sonia/mvvm/bunch_builder_view_model.cpp
)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_SOURCES})
target_sources(${LIBRARY_NAME} PRIVATE ${BOOTSTRAP_HPP})

# The numetron headers must see the configuration the numetron library was built with
# (NUMETRON_COMPILED, NUMETRON_BACKEND_ASM), which the `numetron` target exports.
target_link_libraries(${LIBRARY_NAME} PUBLIC numetron)

if(NOT DO_NOT_LINK_BOOST_HEADERS)
target_link_libraries(${LIBRARY_NAME} PRIVATE Boost::headers)
endif()

if(MSVC)
    target_compile_options(${LIBRARY_NAME} PRIVATE /W3 /MP)
    target_compile_options(${LIBRARY_NAME} PRIVATE /Zc:__cplusplus)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${LIBRARY_NAME} PRIVATE -Wall -Wextra -pedantic -Wno-missing-field-initializers)

    set_property(SOURCE ${ANNIUM_PARSER_DIR}/annium.tab.cpp APPEND PROPERTY COMPILE_OPTIONS "-Wno-missing-field-initializers" "-Wno-unused-but-set-variable")
    set_property(SOURCE ${ANNIUM_PARSER_DIR}/annium.yy.cpp APPEND PROPERTY COMPILE_OPTIONS "-Wno-unused-function")
endif()
