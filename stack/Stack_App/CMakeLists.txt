cmake_minimum_required(VERSION 3.24)
project(Stack_App C)

set(CMAKE_C_STANDARD 99)

add_executable(Stack_App app/main.c program/program.c program/program.c stack/stack.c)
