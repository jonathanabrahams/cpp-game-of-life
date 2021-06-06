cmake_minimum_required(VERSION 3.16)

project(GameOfLife 
    VERSION 0.0.1
    LANGUAGES CXX
    HOMEPAGE_URL https://github.com/jonathanabrahams/cpp-game-of-life
)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

add_subdirectory(src)
add_subdirectory(tst)