cmake_minimum_required(VERSION 3.8)
project(Test)

add_subdirectory(gtest-1.6.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(testUser main.cpp testUser.cpp)
target_link_libraries(testUser gtest gtest_main)
