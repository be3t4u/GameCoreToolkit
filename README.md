# GameCore Toolkit

**A modular C++17 game development toolkit built and tested on Linux.**

GameCore Toolkit is a personal software engineering project focused on implementing fundamental game programming systems using modern C++.

The project demonstrates object-oriented programming, game logic, collision detection, file handling, automated builds, and software testing in a Linux development environment.

## Features

### Game State Management
- Implements a finite-state machine with Menu, Playing, Paused, and GameOver states.
- Validates state transitions.
- Prevents invalid transitions.

### Collision Detection
- Implements 2D Axis-Aligned Bounding Box (AABB) collision detection.
- Detects overlapping rectangles using position and dimensions.
- Provides reusable collision detection functions.

### Game Data Management
- Saves player scores to local files.
- Loads previously saved scores.
- Handles basic file read/write errors using C++ streams.

### Build Automation
- Uses CMake for project configuration and compilation.
- Provides Bash scripts for automated builds and execution.
- Supports clean builds.

### Automated Testing
- Uses CTest to execute automated tests.
- Includes collision detection tests for overlapping, separated, and edge-touching rectangles.

## Technologies

| Technology | Purpose |
|---|---|
| C++17 | Core application development |
| Linux (Ubuntu / WSL) | Development environment |
| GCC / G++ | C++ compilation |
| CMake | Build system |
| Bash | Build automation |
| CTest | Automated testing |
| Git & GitHub | Version control |
| Visual Studio Code | Development environment |

## Project Structure

```text
GameCoreToolkit/
├── include/
│   ├── CollisionDetector.h
│   └── GameDataManager.h
├── src/
│   ├── main.cpp
│   ├── CollisionDetector.cpp
│   └── GameDataManager.cpp
├── tests/
│   └── test_collision.cpp
├── CMakeLists.txt
├── build.sh
└── README.md
```

## Build and Run

**Requirements:** Linux, a C++17-compatible compiler, CMake, and Bash.

Clone the repository:

```bash
git clone https://github.com/be3t4u/GameCoreToolkit.git
cd GameCoreToolkit
```

Configure and compile:

```bash
cmake -S . -B build
cmake --build build
```

Run the application:

```bash
./build/gamecore
```

Alternatively, use the automated build script:

```bash
chmod +x build.sh
./build.sh
```

## Running Tests

Execute the automated tests:

```bash
ctest --test-dir build --output-on-failure
```

To display detailed test output:

```bash
ctest --test-dir build -V
```

## Future Improvements

- Separate Game State Manager into reusable header and source files.
- Add automated tests for state transitions and save/load functionality.
- Implement a game configuration system.
- Improve data validation and error handling.
- Expand the toolkit with additional gameplay components.

## Project Purpose

This project was developed to strengthen practical C++ and Linux software engineering skills through hands-on implementation of game-related systems.

It focuses on clean code organization, reusable components, debugging, build automation, and automated testing.

## Author

**Jalil Kargarbideh**

Software Developer | C++ | Unity | Unreal Engine | Game Development | XR

[GitHub Profile](https://github.com/be3t4u)
