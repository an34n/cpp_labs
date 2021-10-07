cmake_minimum_required(VERSION 3.0.0)
project(lab2 VERSION 0.1.0)

include(CTest)
include(GoogleTest)
enable_testing()

add_subdirectory(tests)
add_executable(test2 tests/test.cpp tests/lib.cpp)
target_link_libraries(test2 gtest gmock gtest_main)
add_test(test2 test2)

add_executable(lab2 src/main.cpp src/lib.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
