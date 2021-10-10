cmake_minimum_required(VERSION 3.21)

set(PROJECTNAME Unit-Tests)
set(PROJECTDIR "${CMAKE_CURRENT_SOURCE_DIR}")

file(GLOB_RECURSE src "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${src})


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(
  ${PROJECTNAME}
  ${src}
  )

set_target_properties( ${PROJECTNAME}
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
  LIBRARY_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}"
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
)

target_link_libraries(${PROJECTNAME} gtest_main)
target_link_libraries(${PROJECTNAME} Delve)
add_test(NAME Delve_test COMMAND ${PROJECTNAME})
target_include_directories(${PROJECTNAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/../Delve/include/)



