cmake_minimum_required(VERSION 3.8)

project (SecureChat LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

#set(Qt5_DIR "/home/kegar/Qt/5.8/gcc_64/lib/cmake/Qt5")
option(enableTest false)

file(GLOB SOURCES src/*.cpp)
file(GLOB HEADERS includes/*.h)

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)
find_package(CryptoPP REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} src/request.cpp src/qml.qrc)

target_link_libraries(${PROJECT_NAME} -pthread ${CRYPTOPP_LIBRARIES})
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Widgets Qt5::Qml)

if(enableTest)
enable_testing(true)
add_subdirectory(test)
endif()
