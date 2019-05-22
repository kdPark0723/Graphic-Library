execute_process(
    COMMAND git submodule update --init external/gl3w
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)
execute_process(
    COMMAND git submodule update --init external/glfw
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
)

# Download include/GL/glcorearb.h & generate src/gl3w.c and include/GL/gl3w.h
execute_process(
    COMMAND ./gl3w_gen.py
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/external/gl3w
)

add_subdirectory(gl3w)
add_subdirectory(glfw)
