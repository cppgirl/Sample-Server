cmake_minimum_required(VERSION 3.10)

project(test VERSION 1.0)

add_subdirectory(dependencies)

add_executable(test source.c)

target_link_libraries(test tinycsocket)

target_include_directories(test PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/tinycsocket/include)
