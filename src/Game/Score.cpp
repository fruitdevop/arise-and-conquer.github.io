#include "Score.h"

void Score::add(int points) {
    value += points;
}

int Score::get() const {
    return value;
}