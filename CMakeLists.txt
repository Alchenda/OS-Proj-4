cmake_minimum_required(VERSION 3.21)
project(OS-Proj-4)

set(CMAKE_CXX_STANDARD 14)

add_executable(OS-Proj-4 main.cpp ThreadCreation.cpp PTE.cpp ThreadCreation.hpp PTE.hpp)


target_link_libraries(OS-Proj-4 -pthread)