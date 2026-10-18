cmake_minimum_required(VERSION 3.20)

project(ATM_Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ATM application
add_executable(ATM
    src/main.cpp
    src/atm.cpp
)

target_include_directories(ATM PRIVATE include)

# Unit tests will be configured after we choose the testing framework.
