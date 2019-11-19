cmake_minimum_required(VERSION 3.15)

project(blaster C)

set(CMAKE_C_STANDARD 11)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
enable_testing()

include_directories(src/headers)
include_directories(src/uthash-master/src)

set( BLAST_SRC
        src/main.c
        src/symbol.c
)
set(
        TEST_SRC
        test/test1.c
)
add_executable(blaster ${BLAST_SRC})
target_compile_options(blaster PRIVATE -Werror -Wall -Wextra)

#TODO add testing exec

