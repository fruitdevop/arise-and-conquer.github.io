#include "Player.h"
#include "Bullet.h"
#include <GLFW/glfw3.h>

extern GLFWwindow* window;

void Player::init() {
    x = 0.0f;
    y = -0.8f;
}

void Player::update() {
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        x -= 0.02f;
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        x += 0.02f;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS && cooldown <= 0.0f) {
        bullets.emplace_back(x, y + 0.1f);
        cooldown = 0.25f;
    }

    for (auto& b : bullets) b.update();
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet& b) { return !b.isActive(); }), bullets.end());

    if (cooldown > 0.0f) cooldown -= 0.016f;
}

void drawQuad(float x, float y, float w, float h, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + w, y);
        glVertex2f(x + w, y + h);
        glVertex2f(x, y + h);
    glEnd();
}

void drawPixel(float x, float y, float size = 0.01f) {
    glBegin(GL_QUADS);
        glVertex2f(x,         y);
        glVertex2f(x + size,  y);
        glVertex2f(x + size,  y + size);
        glVertex2f(x,         y + size);
    glEnd();
}

void drawShip(float x, float y) {
    float s = 0.01f;  // dimensione di un pixel
    float px = x;
    float py = y;

    // Riga 1
    drawPixel(px + 3*s, py + 4*s);

    // Riga 2
    drawPixel(px + 2*s, py + 3*s);
    drawPixel(px + 3*s, py + 3*s);
    drawPixel(px + 4*s, py + 3*s);

    // Riga 3
    for (int i = 1; i <= 5; ++i)
        drawPixel(px + i*s, py + 2*s);

    // Riga 4
    for (int i = 0; i <= 6; ++i)
        drawPixel(px + i*s, py + 1*s);

    // Riga 5
    drawPixel(px + 0*s, py + 0*s);
    drawPixel(px + 1*s, py + 0*s);
    drawPixel(px + 5*s, py + 0*s);
    drawPixel(px + 6*s, py + 0*s);
}

void Player::render() {
    glColor3f(1.0f, 1.0f, 1.0f); // colore bianco
    drawShip(x,y);

    for (auto& b : bullets)
        b.render();
}


std::vector<Bullet>& Player::getBullets() {
    return bullets;
}



