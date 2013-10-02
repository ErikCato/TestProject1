#Specify the version being used aswell as the language
cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
#Name your project here
project(HELLO)

#Sends the -std=c99 flag to the gcc compiler
add_definitions(-std=c99)

set(hello_source_files src/hello.c)
add_executable(hello ${hello_source_files})

#add_subdirectory(src)


