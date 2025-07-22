#include "Enemy.h"
#include <GLFW/glfw3.h>

static void drawQuad(float x, float y, float w, float h) {
    glBegin(GL_QUADS);
        glVertex2f(x,     y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x,     y + h);
    glEnd();
}

Enemy::Enemy(float startX, float startY)
    : x(startX), y(startY), alive(true), width(0.08f), height(0.05f) {}

void Enemy::update() {
    // Es: muovi verso il basso lentamente
    y -= 0.001f;
}

void Enemy::shift(float dx, float dy) {
    x += dx;
    y += dy;
}

void Enemy::render() {
    if (!alive) return;

    glColor3f(1.0f, 0.0f, 0.0f); // rosso
    drawQuad(x - width/2, y, width, height);
}

float Enemy::getX() const { return x; }
float Enemy::getY() const { return y; }

void Enemy::setAlive(bool state) { alive = state; }
bool Enemy::isAlive() const { return alive; }
