cmake_minimum_required(VERSION 3.5)
project (SecureChat VERSION 0.1 LANGUAGES CXX)

###  CMAKE CONFIGURATION

set(Qt5_DIR "/home/kegar/Qt/5.8/gcc_64/lib/cmake/Qt5") # <----- TODO
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}")

### PROJECT CONFIGURATION

file(GLOB SOURCES src/*/*.cpp)
file(GLOB HEADERS src/*/*.h)

add_executable(${PROJECT_NAME} ${ROOT_SRC} ${SOURCES} ${HEADERS} src/qml.qrc src/main.cpp)
target_link_libraries(${PROJECT_NAME} -pthread)

###  QT5 CONFIGURATION

find_package(Qt5 COMPONENTS Core Quick Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Quick Qt5::Widgets Qt5::Qml)


### CRYPTO++ CONFIGURATION

find_package(CryptoPP REQUIRED)
target_link_libraries(${PROJECT_NAME} ${CRYPTOPP_LIBRARIES})

enable_testing()
add_subdirectory(test)


SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Ivan Voloshyn") #required
 
INCLUDE(CPack)

