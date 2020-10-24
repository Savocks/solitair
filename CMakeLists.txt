cmake_minimum_required(VERSION 3.13)  # CMake version check
project(solitair)               # Create project "simple_example"
set(CMAKE_C_STANDARD 11)            # Enable c++14 standard
SET(CMAKE_BUILD_TYPE Debug)
# Add main.cpp file of project root directory as source file
set(SOURCE_FILES osmosis.c mapperutils.h printer.h models.h utils.h cards.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(solitair ${SOURCE_FILES})