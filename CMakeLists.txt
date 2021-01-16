cmake_minimum_required(VERSION 3.13)  # CMake version check
project(solitair)               # Create project "simple_example"
set(CMAKE_C_STANDARD 11)            # Enable c++14 standard
set(CMAKE_BUILD_TYPE Debug)
# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.c lib/card/card.c lib/card/card.h lib/foundation/foundation.c lib/foundation/foundation.h lib/discard_pile/discard_pile.c lib/discard_pile/discard_pile.h lib/stock/stock.c lib/stock/stock.h lib/deck/deck.c lib/deck/deck.h)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(solitair ${SOURCE_FILES})
target_link_libraries(solitair ${CURSES_LIBRARIES})
