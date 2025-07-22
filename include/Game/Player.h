#pragma once
#include <vector>
#include "Bullet.h"

class Player {
public:
    void init();
    void update();
    void render();
    std::vector<Bullet>& getBullets();
    float getX() const { return x; }
    float getY() const { return y; }
private:
    float x, y;
    float cooldown = 0.0f;
    std::vector<Bullet> bullets;
};
