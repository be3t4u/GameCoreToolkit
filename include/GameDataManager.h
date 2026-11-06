#pragma once

#include <string>

class GameDataManager {
public:
    static bool saveScore(
        const std::string& filename,
        int score
    );

    static bool loadScore(
        const std::string& filename,
        int& score
    );
};