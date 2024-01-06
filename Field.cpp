#include "Field.h"
#include <cstdlib> // for rand()
#include <iostream>

bool Field::isWithinBounds(int x, int y) const {
    return x >= 0 && x < width && y >= 0 && y < height;
}

void Field::moveHero(int x, int y) {
    int herosOldX = hero->getX();
    int herosOldY = hero->getY();
    if (isWithinBounds(x, y)) {
        cells[y][x].setUnitPresent(true);
        hero->setX(x);
        hero->setX(y);
    }
    if (isWithinBounds(herosOldX, herosOldY)) {
        cells[herosOldY][herosOldX].setObstacle(false);
        cells[herosOldY][herosOldX].setUnitPresent(false);
    }
}
void Field::eraseContent(int x, int y) {
    if (isWithinBounds(x, y)) {
        cells[y][x].setObstacle(false);
        cells[y][x].setUnitPresent(false);
    }
}

bool Field::isCellFreeAroundHero(int heroX, int heroY) const {
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            int x = heroX + dx;
            int y = heroY + dy;

            if (isWithinBounds(x, y) && (cells[y][x].hasObstacle() || cells[y][x].hasUnitPresent()))
                return false;
        }
    }
    return true;
}

Field::Field(int m, int n) : width(m), height(n) {
    cells.resize(height, std::vector<Cell>(width));
    hero = new Hero();
    monster = new Monster;
}

void Field::placeHero() {
    int x = width / 2;
    int y = 1;
    hero->setX(x);
    hero->setY(y);
    moveUnit(*hero, x, y);
}

void Field::moveUnit(Character& unit, int new_x, int new_y) {
    if (isWithinBounds(unit.getX(), unit.getY())) {
        cells[unit.getY()][unit.getX()].setUnitPresent(false);
    }
    if (isWithinBounds(new_x, new_y)) {
        cells[new_y][new_x].setUnitPresent(true);
        unit.setX(new_x);
        unit.setY(new_y);
    }
    unit.setX(new_x);
    unit.setY(new_y);
}

void Field::placeObstacles(int obstacleCount) {
    for (int i = 0; i < obstacleCount; ++i) {
        int x, y;
        do {
            x = rand() % width;
            y = rand() % height;
        } while (!isCellFreeAroundHero(x, y));

        cells[y][x].setObstacle(true);
    }
}

//bool Field::isCellHasObstacle(int x, int y) {
//    return cells[y][x].hasObstacle();
//}
void Field::placeNearHero() {
    int heroX = hero->getX();
    int heroY = hero->getY();
    //int newX, newY;
    //newX=rand()%
    if (isWithinBounds(heroX + 2, heroY) && IsCellFree(heroX + 2, heroY)) {
        //monster->setY(heroY + 2);
        moveUnit(*monster, heroX + 2, heroY);
        return;
    }
    monster->ChangeState(*hero);
    //else placeNearHero();
}

//void Field::placeMonsters(int monsterCount) {
////    for (int i = 0; i < monsterCount; ++i) {
//        int x, y;
//        do {
//            x = rand() % width;
//            y = rand() % height;
//        } while (!isCellFreeAroundHero(x, y));
//
//        monster->setX(x);
//        monster->setY(y);
//        moveUnit(*monster, x, y);
//        cells[y][x].setUnitPresent(true);
////    }
//}

Field::Field(Field&& other) noexcept : width(0), height(0), cells() {
    cells.swap(other.cells);

    width = other.width;
    height = other.height;

    other.width = 0;
    other.height = 0;
}



Field& Field::operator=(const Field& other) {
    if (this != &other) {
        cells.clear();

        width = other.width;
        height = other.height;

        cells.resize(height, std::vector<Cell>(width));

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                cells[i][j] = other.cells[i][j];
            }
        }
    }
    return *this;
}

Field::Field(const Field& other) : width(other.width), height(other.height) {
    cells.resize(height, std::vector<Cell>(width));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            cells[i][j] = other.cells[i][j];
        }
    }
}

Field& Field::operator=(Field&& other) noexcept {
    if (this != &other) {
        cells.clear();

        width = other.width;
        height = other.height;
        cells = std::move(other.cells);

        other.width = 0;
        other.height = 0;
    }
    return *this;
}

bool Field::IsCellFree(int x, int y) const {
    return isWithinBounds(x, y) && !cells[y][x].hasObstacle() && !cells[y][x].hasUnitPresent();
}

//Field::~Field() {
////    delete hero;
////    delete monster;
//
//    for (int i = 0; i < height; ++i) {
//        delete[] cells[i];
//    }
//    delete[] cells;
//}
