cmake_minimum_required(VERSION 3.16)
project(CppDataStructure)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

include(${PROJECT_SOURCE_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(CppDataStructure main.cpp)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})