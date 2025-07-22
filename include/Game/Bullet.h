#pragma once

class Bullet {
public:
    Bullet(float startX, float startY);
    void update();
    void render();
    float getX() const;
    float getY() const;
    bool isActive() const;
    void deactivate();
private:
    float x, y;
    bool active;
};