#pragma once
#include <vector>

class Enemy {
public:
    Enemy(float startX, float startY);

    void update();
    void shift(float dx, float dy);
    void render();

    float getX() const;
    float getY() const;

    void setAlive(bool state);
    bool isAlive() const;

private:
    float x, y;
    float width, height;
    bool alive;
};

