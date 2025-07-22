#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Score.h"
#include <vector>

class Game {
public:
    void init();
    void lime();
    void update();
    void render();
    void spawnEnemies(int rows, int cols);
private:
    Player player;
    std::vector<Enemy> enemies;
    float enemyDir = 1.0f;
    Score score;
    bool gameOver = false;
    
    int enemyCount = 5;
};
