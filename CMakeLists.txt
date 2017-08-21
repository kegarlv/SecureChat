cmake_minimum_required (VERSION 2.8.11)
project (SecureChat)
set(CMAKE_CXX_STANDARD 14)

option(enableTest false)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS includes/*.h)

add_executable(SecureChat ${SOURCES} ${HEADERS})

if(enableTest)
   enable_testing()
   add_subdirectory(libs/gtest-1.6.0)
   include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
   add_executable(testUser test/testUser.cpp)
   target_link_libraries(testUser gtest gtest_main)
   add_test(classUser testUser)
endif()



