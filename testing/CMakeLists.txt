cmake_minimum_required(VERSION 3.27)
project(test)
set(CMAKE_CXX_STANDARD 17)

enable_testing()

# add_subdirectory(../googletest/googletest/include)
add_executable(${PROJECT_NAME} test.cpp test.h ../BST.h ../Set.h)
target_link_libraries(${PROJECT_NAME} gtest gtest_main)
#target_include_directories(${PROJECT_NAME} PRIVATE ../googletest/googletest/include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include(GoogleTest)
gtest_discover_tests(test)