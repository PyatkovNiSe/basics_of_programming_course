cmake_minimum_required(VERSION 3.20)
project(course C)

set(CMAKE_C_STANDARD 11)

add_executable(course main.c)

add_subdirectory(libs)
add_subdirectory(lab5c)
add_subdirectory(lab5d)
add_subdirectory(lab5e)
add_subdirectory(string)

target_link_libraries(course data_structures)
target_link_libraries(course algorithms)
target_link_libraries(course generating)
target_link_libraries(course lab5c)
target_link_libraries(course lab5d)
target_link_libraries(course lab5e)
target_link_libraries(course tasks)


