#pragma once
#include "Character.h"
#include "Cell.h"

class Field {
private:
    int width;
    int height;
    Cell** cells;
    Hero* hero;
    Monster* monster;
    bool isCellFreeAroundHero(int heroX, int heroY) const;
    friend void PrintField(Field*);

public:
    Field(int m, int n);
    bool isWithinBounds(int x, int y) const; // було private
    void placeHero();
    void placeObstacles(int obstacleCount);
    void placeMonsters(int monsterCount);
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
};