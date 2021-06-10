set(BINARY ${CMAKE_PROJECT_NAME})
set(SOURCES main.cpp)

include_directories("${PROJECT_BINARY_DIR}")

add_executable(${BINARY}_run ${SOURCES})