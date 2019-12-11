cmake_minimum_required(VERSION 3.0)

project(blaster C)

set(CMAKE_C_STANDARD 11)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
enable_testing()

include_directories(src/headers)
include_directories(src/uthash-master/src)
set( BLAST_SRC
        src/symbol.c
        src/lex.yy.c
        src/y.tab.c
        )
set(
        TEST_SRC
        test/test1.c
)
add_executable(blaster src/main.c ${BLAST_SRC})
target_compile_options(blaster PRIVATE  -Wall -Werror=implicit-function-declaration)





#TODO Serradje....START

add_executable(result test_sources/out.c)





#serradje...END
#TODO add testing exec

