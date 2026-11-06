
#include <iostream>
#include <string>
#include "CollisionDetector.h"
#include "GameDataManager.h"

enum class GameState {
    Menu,
    Playing,
    Paused,
    GameOver,
    Testing
};


class GameStateManager {
private:
    GameState currentState = GameState::Menu;

    bool isValidTransition(GameState next) const {
        switch (currentState) {
            case GameState::Menu:
                return next == GameState::Playing;

            case GameState::Playing:
                return next == GameState::Paused ||
                       next == GameState::GameOver;

            case GameState::Paused:
                return next == GameState::Playing ||
                       next == GameState::Menu;

            case GameState::GameOver:
                return next == GameState::Menu;
        }
        return false;
    }

public:
    bool setState(GameState next) {
        if (!isValidTransition(next)) {
            std::cout << "Invalid transition!\n";
            return false;
        }

        currentState = next;
        std::cout << "State changed: " << getStateName() << "\n";
        return true;
    }

    std::string getStateName() const {
        switch (currentState) {
            case GameState::Menu: return "Menu";
            case GameState::Playing: return "Playing";
            case GameState::Paused: return "Paused";
            case GameState::GameOver: return "GameOver";
        }
        return "Unknown";
    }
};

int main() {
    GameStateManager game;

    std::cout << "Initial state: " << game.getStateName() << "\n";

    game.setState(GameState::Playing);
    game.setState(GameState::Paused);
    game.setState(GameState::Playing);
    game.setState(GameState::GameOver);

    // Intentionally invalid
    game.setState(GameState::Paused);

    game.setState(GameState::Menu);

    Rectangle player{10, 10, 50, 50};
    Rectangle enemy{40, 40, 50, 50};
    Rectangle wall{200, 200, 40, 40};
    
    std::cout << "\n--- Collision Detection ---\n";
    /*
    std::cout << "Player vs Enemy: "
    << (CollisionDetector::checkAABB(player, enemy)
    ? "Collision"
    : "No collision")
    << "\n";
    int x,y,w,h = 0;
    std::cin>>x>>y>>w>>h;
    Rectangle test{x, y, w, h};
    
    std::cout << "Player vs Wall: "
    << (CollisionDetector::checkAABB(player, wall)
    ? "Collision"
    : "No collision")
    << "\n";
    std::cout << "Hiii    " << (CollisionDetector::checkAABB(player, test) ? "Collision" : "No Collision") << "\n";
    */

std::cout << "\n--- Game Data Management ---\n";

int playerScore = 1500;

if (GameDataManager::saveScore(
        "savegame.txt", playerScore)) {
    std::cout << "Score saved successfully!\n";
} else {
    std::cout << "Failed to save score!\n";
}

int loadedScore = 0;

if (GameDataManager::loadScore(
        "savegame.txt", loadedScore)) {
    std::cout << "Loaded score: "
              << loadedScore << "\n";
} else {
    std::cout << "Failed to load score!\n";
}

return 0;

}
