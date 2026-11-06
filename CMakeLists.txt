#* sad


cmake_minimum_required(VERSION 3.16)

project(GameCoreToolkit VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Main application
add_executable(gamecore
    src/main.cpp
    src/CollisionDetector.cpp
    src/GameDataManager.cpp
)

target_include_directories(gamecore PRIVATE include)

# Enable testing
enable_testing()

# Collision tests
add_executable(test_collision
    tests/test_collision.cpp
    src/CollisionDetector.cpp
)

target_include_directories(test_collision PRIVATE include)

# Register test with CTest
add_test(
    NAME CollisionTests
    COMMAND test_collision
)