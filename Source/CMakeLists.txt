cmake_minimum_required(VERSION 3.20)


set(PROJECT_NAME "Delve")

project(${PROJECT_NAME} LANGUAGES CXX)


file(GLOB_RECURSE src "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB_RECURSE inc "${CMAKE_CURRENT_SOURCE_DIR}/../include/*.hpp")

add_definitions(-DDELVE_API)

add_library(${PROJECT_NAME} SHARED ${src} ${inc})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)