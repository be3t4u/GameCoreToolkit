#!/bin/bash

set -e //Stops the script if a command fails

# Move to the directory containing this script
cd "$(dirname "$0")"

echo "================================="
echo " GameCore Toolkit Build System"
echo "================================="

echo "[1/3] Configuring project..."
cmake -S . -B build

echo "[2/3] Compiling C++ source files..."
cmake --build build

echo "[3/3] Running application..."
./build/gamecore

echo "================================="
echo " Build and execution completed!"
echo "================================="