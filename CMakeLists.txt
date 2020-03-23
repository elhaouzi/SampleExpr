cmake_minimum_required(VERSION 3.15)
project(SampleExpr C)

set(CMAKE_C_STANDARD 11)

add_executable(
        SampleExpr
        main.c
        parser.h
        parser.c
        error.h
        error.c
        backend.h
        backend.c
        lex.h
        lex.c

)
