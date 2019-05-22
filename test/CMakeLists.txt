file(GLOB MY_TEST_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp
    )

set(MY_TEST_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
set(MY_BINARY_NAME "UnitTestExecutor")

add_executable(${MY_BINARY_NAME}
    ${MY_TEST_SRCS}
    )

target_include_directories(${MY_BINARY_NAME} PUBLIC
    ${GTEST_INCLUDE_PATH}
    ${GMOCK_INCLUDE_PATH}

    ${MY_INCLUDE_PATH}
    ${MY_TEST_INCLUDE_PATH}
    )

target_link_libraries(${MY_BINARY_NAME}
    GTest::GTest
    GTest::GMock

    ${PROJECT_NAME}
    )

add_dependencies(${MY_BINARY_NAME}
    googletest

    ${PROJECT_NAME}
    )

