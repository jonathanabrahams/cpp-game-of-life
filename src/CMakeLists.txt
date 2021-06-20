set(BINARY ${CMAKE_PROJECT_NAME})
set(SOURCES main.cpp)

add_executable(${BINARY}_run ${SOURCES})

target_include_directories(${BINARY}_run
    PRIVATE ${PROJECT_BINARY_DIR} ${CMAKE_SOURCE_DIR}/include/GOL
)

target_link_libraries(${BINARY}_run
    PRIVATE ${CMAKE_PROJECT_NAME}_lib
)