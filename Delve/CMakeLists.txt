cmake_minimum_required(VERSION 3.20)


set(PROJECT_NAME "Delve")
set(PROJECTDIR "${CMAKE_CURRENT_SOURCE_DIR}")


project(${PROJECT_NAME} LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED)


file(GLOB_RECURSE inc "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")
file(GLOB_RECURSE inl "${CMAKE_CURRENT_SOURCE_DIR}/include/implementation/*.inl")


add_definitions(-DDELVE_API)

add_library(${PROJECT_NAME} INTERFACE  ${inc} ${inl})
target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include/)
