#pragma once
#include "Cell.h"
#include "Hero.h"
#include "Monster.h"
#include <vector>

class Field {
private:
    int width;
    int height;
    std::vector<std::vector<Cell>> cells;
    bool isCellFreeAroundHero(int heroX, int heroY) const;
    friend void PrintField(Field*);

public:
    HeroBase* hero;
    Monster* monster;
    std::vector<Monster*> monsters;
    Field(int m, int n);
    //bool isCellHasObstacle(int x, int y);
    bool isWithinBounds(int x, int y) const;
    void placeHero();
    void placeObstacles(int obstacleCount);
    bool IsCellFree(int x, int y) const;

    void moveUnit(Character &unit, int new_x, int new_y);

    void placeNearHero();

    void eraseContent(int x, int y);

    void moveHero(int x, int y);
};