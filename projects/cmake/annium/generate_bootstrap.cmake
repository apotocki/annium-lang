# generate_bootstrap.cmake
# Called by add_custom_command to generate bootstrap_code.generated.hpp from bootstrap.ann.
# Usage: cmake -DINPUT_FILE=<path> -DOUTPUT_FILE=<path> -P generate_bootstrap.cmake

file(READ "${INPUT_FILE}" CONTENT)
file(WRITE "${OUTPUT_FILE}" "// AUTO-GENERATED -- do not edit manually.\n// Source: bootstrap.ann\n\nconst char annium_bootstrap_code[] = R\"#(\n${CONTENT})#\";\n")
