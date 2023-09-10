cmake_minimum_required(VERSION 3.23)
project(intro_lab_0a)

set(CMAKE_CXX_STANDARD 14)

add_executable(intro_lab_0a main.cpp module2/module2.cpp module2/module2.h)

target_include_directories(intro_lab_0a PRIVATE module1 module2)

add_subdirectory(module1)
target_link_libraries(intro_lab_0a PRIVATE module1_t)