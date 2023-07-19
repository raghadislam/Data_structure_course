cmake_minimum_required(VERSION 3.24)
project(global_ C)

set(CMAKE_C_STANDARD 23)

add_executable(global_ main.c queue/queue.h queue/queue.c stack/stack.h stack/stack.c global.h list/list.c list/list.h)
