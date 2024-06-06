cmake_minimum_required(VERSION 3.27)

set(TEST_PROJECT_NAME
    CoreLibraryTests
)
set(LIBRARY_TESTS_SOURCE
        boardTests.cpp
        ultimateboardTests.cpp
)

project(${TEST_PROJECT_NAME})

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${TEST_PROJECT_NAME} ${LIBRARY_TESTS_SOURCE})
target_link_libraries(${TEST_PROJECT_NAME}
    ${LIBRARY_NAME}
    ${GTEST_LIBRARIES}
)

add_test(${TEST_PROJECT_NAME} ${TEST_PROJECT_NAME})
