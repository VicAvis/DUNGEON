#include "Manager.h"
#include "Character.h"
#include <iostream>

using namespace std;

Manager::Manager() : CurrentLevel(1), gameField(nullptr), PersoneName("") {}

void Manager::createField(int fieldWidth, int fieldHeight, int obstacles, int monster) {
    gameField = new Field(fieldWidth, fieldHeight);
    generationObjects(obstacles);
}

void Manager::generationObjects(int obst) {
    gameField->placeHero();
    gameField->placeObstacles(obst);
    gameField->placeNearHero();
}

int Manager::getCurrentLevel(){
    return CurrentLevel;
}

Manager::~Manager() {
    delete gameField;
}