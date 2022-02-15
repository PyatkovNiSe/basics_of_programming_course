cmake_minimum_required(VERSION 3.20)
project(lab_5b C)

set(CMAKE_C_STANDARD 11)

add_executable(course main.c)

add_subdirectory(libs)
add_subdirectory(lab5d)
target_link_libraries(course data_structures)
target_link_libraries(course algorithms)
target_link_libraries(course lab5d)

