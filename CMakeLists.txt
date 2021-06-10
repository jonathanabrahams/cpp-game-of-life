cmake_minimum_required(VERSION 3.16)

project(GameOfLife
    DESCRIPTION "Game of life is a cellular automaton game invented."
    VERSION 0.0.1
    LANGUAGES CXX
    HOMEPAGE_URL https://github.com/jonathanabrahams/cpp-game-of-life
)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

configure_file(${PROJECT_SOURCE_DIR}/config.h.in ${PROJECT_BINARY_DIR}/config.h)

add_subdirectory(src)
add_subdirectory(tst)