#pragma once

struct Rectangle {
    float x;
    float y;
    float width;
    float height;
};

class CollisionDetector {
public:
    static bool checkAABB(
        const Rectangle& a,
        const Rectangle& b
    );
};
