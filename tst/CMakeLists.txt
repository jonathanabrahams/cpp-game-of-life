
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)

set(BINARY ${CMAKE_PROJECT_NAME}_tst)
set(SOURCES main_test.cpp)

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PUBLIC gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${BINARY})
