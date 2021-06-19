find_package(GTest)
if(NOT GTEST_LIBRARY)
    include(FetchContent)
    FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        release-1.10.0
    )
    FetchContent_MakeAvailable(googletest)
else()
    SET(GTEST_NS GTest::GTest)
endif()

set(BINARY ${CMAKE_PROJECT_NAME}_tst)
file(GLOB SOURCES 
    ${CMAKE_SOURCE_DIR}/src/*.test.cpp 
    ${CMAKE_SOURCE_DIR}/lib/GOL/*.test.cpp
)

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PUBLIC ${GTEST_NS} gtest_main)

enable_testing()
include(GoogleTest)
gtest_discover_tests(${BINARY})

