set(SOURCES GOL/cell.cpp GOL/life.cpp GOL/world.cpp)

add_library(${CMAKE_PROJECT_NAME}_lib
    STATIC ${SOURCES}
)

target_include_directories(${CMAKE_PROJECT_NAME}_lib
    PRIVATE ${CMAKE_SOURCE_DIR}/include/GOL
)