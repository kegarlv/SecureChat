cmake_minimum_required(VERSION 3.8)
project(Test)

add_subdirectory(gtest-1.6.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(testUser main.cpp testUser.cpp ../src/User.cpp ../src/CurrentUser.cpp ../src/Dialog.cpp ../src/Message.cpp ../libs/json.h ../libs/restclient-cpp/helpers.cc ../libs/restclient-cpp/restclient.cc ../libs/restclient-cpp/connection.cc)
target_link_libraries(testUser gtest gtest_main -lcurl)
