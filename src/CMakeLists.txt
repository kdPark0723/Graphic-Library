add_library(${PROJECT_NAME}
    ${MY_SRCS}
    )

target_include_directories(${PROJECT_NAME} PUBLIC
    ${MY_INCLUDE_PATH}
    )

target_link_libraries(${PROJECT_NAME}
    gl3w
    glfw
    )