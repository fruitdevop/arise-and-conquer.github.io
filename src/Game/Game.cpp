#include "Game.h"
#include "Enemy.h"
#include <cmath>
#include <GLFW/glfw3.h>
#include <GLUT/glut.h>  // Per macOS
#include <iostream>

void Game::init() {
    player.init();
    enemies.clear();
    
    spawnEnemies(3, 6); // 3 righe, 6 colonne = 18 nemici disposti a griglia
    
    enemyDir = 1.0f;
    gameOver = false;
}

void Game::update() {
    if (gameOver) return;

    player.update();

    float step = 0.005f * enemyDir;
    bool reverse = false;
    for (auto& e : enemies) {
        if (!e.isAlive()) continue;
        float newX = e.getX() + step;
        if (newX > 0.9f || newX < -0.9f) {
            reverse = true;
            break;
        }
    }

    for (auto& e : enemies) {
        if (!e.isAlive()) continue;
        if (reverse) {
            e.shift(0.0f, -0.05f);
        } else {
            e.shift(step, 0.0f);
        }
    }
    if (reverse) enemyDir *= -1;

    for (auto& bullet : player.getBullets()) {
        for (auto& enemy : enemies) {
            if (!enemy.isAlive()) continue;
            float dx = bullet.getX() - enemy.getX();
            float dy = bullet.getY() - enemy.getY();
            if (std::sqrt(dx*dx + dy*dy) < 0.06f) {
                enemy.setAlive(false);
                bullet.deactivate();
                score.add(100);
            }
        }
    }

    // Check if any enemy reached bottom
    for (auto& enemy : enemies) {
        if (enemy.isAlive() && enemy.getY() < -0.7f) {
            gameOver = true;
            std::cout << "Game Over!";
        }
    }
}

void Game::render() {
    player.render();
    for (auto& e : enemies) e.render();

    // Simple text score (use console for now)
    glRasterPos2f(-0.95f, 0.9f);
    std::string scoreText = "Score: " + std::to_string(score.get());
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
    }

    if (gameOver) {
        glRasterPos2f(-0.2f, 0.0f);
        std::string overText = "GAME OVER";
        for (char c : overText) {
            glutBitmapCharacter(GLUT_BITMAP_9_BY_15, c);
        }
    }
}

void Game::spawnEnemies(int rows, int cols) {
    enemies.clear(); // opzionale: svuota eventuali nemici precedenti

    float startX = -0.8f;
    float startY = 0.8f;
    float spacingX = 0.18f; // distanza tra nemici in orizzontale
    float spacingY = 0.1f;  // distanza tra righe

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            float x = startX + col * spacingX;
            float y = startY - row * spacingY;
            enemies.emplace_back(x, y); // crea nemico con posizione unica
        }
    }
}

