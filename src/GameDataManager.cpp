#include "GameDataManager.h"
#include <fstream>

bool GameDataManager::saveScore(
    const std::string& filename,
    int score
) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    file << score << "\n";

    file.close();
    return file.good();
}

bool GameDataManager::loadScore(
    const std::string& filename,
    int& score
) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    int loadedScore;

    if (!(file >> loadedScore)) {
        return false;
    }

    score = loadedScore;
    return true;
}