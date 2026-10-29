cmake_minimum_required(VERSION 3.20)

project(ATM_Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Download and configure GoogleTest
include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

FetchContent_MakeAvailable(googletest)

# Build the ATM application
add_executable(ATM
    src/main.cpp
    src/atm.cpp
)

target_include_directories(ATM PRIVATE include)

# Build the automated tests
enable_testing()

add_executable(ATMTests
    tests/test_atm.cpp
    src/atm.cpp
)

target_include_directories(ATMTests PRIVATE include)

target_link_libraries(ATMTests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(ATMTests)
