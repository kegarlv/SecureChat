cmake_minimum_required(VERSION 3.8)
project (SecureChat)
set(CMAKE_CXX_STANDARD 14)

#option(enableTest true)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS includes/*.h)

add_executable(SecureChat ${SOURCES} ${HEADERS} src/CurrentUser.cpp src/CurrentUser.h src/Message.cpp src/Message.h src/Dialog.cpp src/Dialog.h libs/json.h libs/restclient-cpp/helpers.cc libs/restclient-cpp/restclient.cc libs/restclient-cpp/connection.cc)

target_link_libraries(SecureChat -lcurl -pthread)
#if(enableTest)
    add_subdirectory(test)
#endif()