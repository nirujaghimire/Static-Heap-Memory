cmake_minimum_required(VERSION 3.26)
project(Static_Heap_Memory C)

set(CMAKE_C_STANDARD 11)

add_executable(Static_Heap_Memory main.c static_heap.c static_heap.h)
