cmake_minimum_required(VERSION 3.8)
project(Test)

add_subdirectory(gtest-1.6.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


file(GLOB SOURCES ../src/*.cpp)
file(GLOB HEADERS includes/*.h)

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)
find_package(CryptoPP REQUIRED)

add_executable(testUser main.cpp testUser.cpp ../src/User.cpp ../src/CurrentUser.cpp ../src/ContactInfo.cpp ../src/Dialog.cpp ../src/Message.cpp ../src/messagelist.cpp ../src/messageworker.cpp ../src/cipherhelper.cpp ../src/contactlist.cpp ${HEADERS} ../src/request.cpp)
target_link_libraries(testUser gtest gtest_main -lcurl ${CRYPTOPP_LIBRARIES})
target_link_libraries(testUser Qt5::Core Qt5::Quick Qt5::Widgets Qt5::Qml)
