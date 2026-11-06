#include "CollisionDetector.h"
#include <iostream>

int main() {
    int passed = 0;
    int failed = 0;

    Rectangle a{10, 10, 50, 50};
    Rectangle b{40, 40, 50, 50};
    Rectangle c{200, 200, 40, 40};
    Rectangle d{60, 10, 30, 30};

    // Test 1: Overlapping rectangles
    if (CollisionDetector::checkAABB(a, b)) {
        std::cout << "PASS: Overlapping\n";
        passed++;
    } else {
        std::cout << "FAIL: Overlapping\n";
        failed++;
    }

    // Test 2: Separated rectangles
    if (!CollisionDetector::checkAABB(a, c)) {
        std::cout << "PASS: Separated\n";
        passed++;
    } else {
        std::cout << "FAIL: Separated\n";
        failed++;
    }

    // Test 3: Touching edges
    if (!CollisionDetector::checkAABB(a, d)) {
        std::cout << "PASS: Touching edges\n";
        passed++;
    } else {
        std::cout << "FAIL: Touching edges\n";
        failed++;
    }

    std::cout << "Passed: " << passed
              << " | Failed: " << failed << "\n";

    return failed == 0 ? 0 : 1;
}