#pragma once
#include "Cell.h"
#include "Hero.h"
#include "Monster.h"
#include <vector>

class Field {
private:
    int width;
    int height;
    Cell** cells;
    bool isCellFreeAroundHero(int heroX, int heroY) const;
    friend void PrintField(Field*);

public:
    Hero* hero;
    Monster* monster;
    std::vector<Monster*> monsters;
    Field(int m, int n);
    bool isWithinBounds(int x, int y) const;
    void placeHero();
    void placeObstacles(int obstacleCount);
    bool freeCell(int x, int y) const;
    // Copy Constructor
    Field(const Field& other);
    // Copy Assignment Operator
    Field& operator=(const Field& other);
    // Move Constructor
    Field(Field&& other) noexcept;
    // Move Assignment Operator
    Field& operator=(Field&& other) noexcept;
    ~Field();

    void moveUnit(Character &unit, int new_x, int new_y);

    void placeNearHero();

    void eraseContent(int x, int y);

    void moveHero(int x, int y);
};