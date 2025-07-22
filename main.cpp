#include <GLFW/glfw3.h>
#include "include/Game/Game.h"

GLFWwindow* window = nullptr;

int main() {
    if (!glfwInit()) return -1;

    window = glfwCreateWindow(800, 600, "Space Invaders Prototype", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    Game game;
    game.init();

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        game.update();
        game.render();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
