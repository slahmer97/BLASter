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
add_executable(optimizer src/optimizer.c src/symbol.c)

target_link_libraries(blaster rt pthread )
target_link_libraries(optimizer rt pthread )

target_compile_options(blaster PRIVATE  -Wall -Werror=implicit-function-declaration)
target_compile_options(optimizer PRIVATE  -Wall -Werror=implicit-function-declaration)

#TODO add testing execs



