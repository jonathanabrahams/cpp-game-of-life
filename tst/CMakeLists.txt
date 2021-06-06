# find_package(GTest REQUIRED)

include(ExternalProject)
ExternalProject_Add(googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG master
    SOURCE_DIR "${CMAKE_BINARY_DIR}/googletest-src"
    BINARY_DIR "${CMAKE_BINARY_DIR}/googletest-build"
    CONFIGURE_COMMAND ""
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
include(GoogleTest)

enable_testing()

set(BINARY ${CMAKE_PROJECT_NAME}_tst)
set(SOURCES main_test.cpp)

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PUBLIC GTest::GTest gtest_main)

gtest_discover_tests(${BINARY})
