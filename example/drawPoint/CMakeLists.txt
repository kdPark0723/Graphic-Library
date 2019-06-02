file(GLOB MY_EXAM4_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/**/*.cpp
    )

set(MY_EXAM4_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(MY_BINARY_NAME "Example4_DrawPoint")

add_executable(${MY_BINARY_NAME}
    ${MY_EXAM4_SRCS}
    )

target_include_directories(${MY_BINARY_NAME} PUBLIC
    ${MY_INCLUDE_PATH}
    ${MY_EXAM4_INCLUDE_PATH}
    )

target_link_libraries(${MY_BINARY_NAME}
    ${PROJECT_NAME}
    )

add_dependencies(${MY_BINARY_NAME}
    ${PROJECT_NAME}
    )