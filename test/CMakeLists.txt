cmake_minimum_required(VERSION 3.5)
project(Test LANGUAGES CXX)

add_subdirectory(gtest-1.6.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB SOURCES ../src/*/*.cpp)
include_directories(../)

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)
find_package(CryptoPP REQUIRED)

add_executable(testStructs main.cpp testUser.cpp ${SOURCES})
target_link_libraries(testStructs gtest gtest_main ${CRYPTOPP_LIBRARIES})
target_link_libraries(testStructs Qt5::Core Qt5::Quick Qt5::Widgets Qt5::Qml)
add_test(TestStructs testStructs)
