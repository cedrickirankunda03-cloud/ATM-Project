cmake_minimum_required(VERSION 3.14)
project(ATM_Project VERSION 1.0.0 LANGUAGES CXX)

# 1. Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Enable Compile Commands (Fixes VS Code red squiggly lines for GTest)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 3. Include Directories
include_directories(include)

# 4. Main Application Source Files
set(MAIN_SOURCES
    src/main.cpp
    src/atm.cpp
    src/VoiceGuidance.cpp
    # Nathan will add src/Account.cpp here later
)

add_executable(ATM_Project ${MAIN_SOURCES})

# 5. Unit Testing Setup (Google Test)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 6. Test Executable
enable_testing()
set(TEST_SOURCES
    tests/test_atm.cpp
    # Nathan will add tests/test_account.cpp here later
)

add_executable(ATM_Tests ${TEST_SOURCES})

# Include this line from Nathan so tests find the headers
target_include_directories(ATM_Tests PRIVATE include)

target_link_libraries(ATM_Tests PRIVATE GTest::gtest_main)

# 7. Register tests with CTest
include(GoogleTest)
gtest_discover_tests(ATM_Tests)

# 8. Doxygen Documentation
find_package(Doxygen)
if (DOXYGEN_FOUND)
    set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR}/include ${PROJECT_SOURCE_DIR}/src)
    set(DOXYGEN_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/docs/html)
    doxygen_add_docs(
        doc
        ${DOXYGEN_INPUT_DIR}
        COMMENT "Generate Doxygen documentation"
    )
endif()