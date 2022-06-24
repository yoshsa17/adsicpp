cmake_minimum_required(VERSION 3.16)
project(adsicpp_bst)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp)
file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(main ${headers} ${sources})

target_link_libraries(main GTest::Main)