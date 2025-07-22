#include "Bullet.h"
#include <GLFW/glfw3.h>

Bullet::Bullet(float startX, float startY) : x(startX), y(startY), active(true) {}

void Bullet::update() {
    if (!active) return;
    y += 0.04f;
    if (y > 1.0f) active = false;
}

void Bullet::render() {
    if (!active) return;
    glBegin(GL_QUADS);
        glVertex2f(x - 0.01f, y);
        glVertex2f(x + 0.01f, y);
        glVertex2f(x + 0.01f, y + 0.05f);
        glVertex2f(x - 0.01f, y + 0.05f);
    glEnd();
}

float Bullet::getX() const { return x; }
float Bullet::getY() const { return y; }
bool Bullet::isActive() const { return active; }
void Bullet::deactivate() { active = false; }
