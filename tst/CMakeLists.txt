find_package(GTest REQUIRED)

set(BINARY ${CMAKE_PROJECT_NAME}_tst)
set(SOURCES main_test.cpp)

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PUBLIC GTest::GTest gtest_main)