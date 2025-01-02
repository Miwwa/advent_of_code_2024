cmake_minimum_required(VERSION 3.30)
project(advent_of_code_2024)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(day1
        day1/main.cpp
        day1/day1.cpp
        day1/day1.h
)

add_executable(day1_test
        day1/day1_test.cpp
        day1/day1.cpp
        day1/day1.h
)

target_link_libraries(day1_test PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(day1_test)

