#include "Manager.h"
#include "Character.h"
#include <iostream>

using namespace std;

Manager::Manager() : CurrentLevel(1), gameField(nullptr), PersoneName("") {}

void Manager::createField(int fieldWidth, int fieldHeight, int obstacles, Monster* monster) {
    gameField = new Field(fieldWidth, fieldHeight);
    gameField->monster = monster;
    generationObjects(obstacles);
}

void Manager::generationObjects(int obst) {
    gameField->placeHero();
    gameField->placeNearHero();
    gameField->placeObstacles(obst);
}

int Manager::getCurrentLevel() const{
    return CurrentLevel;
}

Manager::~Manager() {
    delete gameField;
}