cmake_minimum_required(VERSION 3.23.2)
project(untitled C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c terminalReader.c terminalReader.h utils.h fileHelper.c fileHelper.h arrayHelper.c arrayHelper.h utils.c sortHelper.c sortHelper.h compareHelper.c compareHelper.h)
