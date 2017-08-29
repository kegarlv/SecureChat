cmake_minimum_required(VERSION 3.8)
project (SecureChat LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(Qt5_DIR "/home/kegar/Qt/5.8/gcc_64/lib/cmake/Qt5")
#option(enableTest true)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS includes/*.h)
set(TMPSOURCES src/main.qml)

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} src/CurrentUser.cpp src/CurrentUser.h src/Message.cpp src/Message.h src/Dialog.cpp src/Dialog.h libs/json.h libs/restclient-cpp/helpers.cc libs/restclient-cpp/restclient.cc libs/restclient-cpp/connection.cc src/qml.qrc src/Backend.cpp src/Backend.h src/ContactInfo.cpp src/ContactInfo.h)

target_link_libraries(${PROJECT_NAME} -lcurl -pthread)
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Widgets Qt5::Qml)

#if(enableTest)
    add_subdirectory(test)
#endif()
