cmake_minimum_required(VERSION 3.0)

project(blaster C)

set(CMAKE_C_STANDARD 11)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

add_executable(blaster src/main.c src/symbol.c src/lex.yy.c src/y.tab.c src/headers/symbol.h src/headers/defs.h src/headers/y.tab.h src/headers/ast.h src/ast.c )

target_link_libraries(blaster rt pthread )

target_compile_options(blaster PRIVATE  -Wall -Werror)



