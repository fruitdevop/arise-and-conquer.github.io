#pragma once

class Score {
public:
    void add(int points);
    int get() const;
private:
    int value = 0;
};