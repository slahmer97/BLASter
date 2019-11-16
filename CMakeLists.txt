cmake_minimum_required(VERSION 3.15)
project(blaster C)

set(CMAKE_C_STANDARD 11)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

include_directories("uthash-master/src")

add_executable(blaster main.c symbol.c defs.h symbol.h)
target_compile_options(blaster PRIVATE -Werror -Wall -Wextra)
