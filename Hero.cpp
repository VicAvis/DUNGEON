#include <algorithm>
#include <iostream>
#include "Hero.h"
#include "Field.h"
#include "Monster.h"
#include "Manager.h"

Manager myManager;

int Hero::getDistance() const { return distance; }
void Hero::setDistance(int value) { distance = value; }

int Hero::getMoveCost() const { return moveCost; }

void Hero::setMoveCost(int value) { moveCost = value; }

Hero::Hero() noexcept
        : Character(){
    setDistance(2);
    setSpeed(startValue);
    setHealth(maxValue);
    setProtection(startValue);
    setDamage(startValue);
    setMoveCost(3);
}

void Hero::increaseDistance(int amount) { setDistance(getDistance() + amount); }

int Hero::move(int new_x, int new_y, Field* gameField) {

    if (gameField->freeCell(new_x, new_y)) {
        int deltaX = std::abs(new_x - getX());
        int deltaY = std::abs(new_y - getY());
        int movementCost = getMoveCost();
        int moveCost = 0;
        if (deltaX == deltaY) { // diagonal
            if (deltaX == 1 && deltaY == 1) {
                moveCost = movementCost; // move 1 cell - 3 points
            } else {
                moveCost = movementCost + (deltaX - 1); // move by more cells
            }
        } else { // straight movement
            moveCost = std::max(deltaX, deltaY) + 1;
        }

        int curSpeed = getSpeed();
        if (curSpeed >= moveCost) {
            gameField->eraseContent(getX(),getY()); // затерли клітинку
            setX(new_x); // встановили нові координати
            setY(new_y);
            gameField->moveHero(new_x,new_y); // оновили поле

            curSpeed -= moveCost;
            int newDistance = getDistance() + 1;
            setDistance(newDistance);
        }
        return moveCost;
    }
    return 1;
}

void Hero::attack(Character& target, Field* gameField) {

    int target_x = target.getX();
    int target_y = target.getY();

    int deltaX = std::abs(target_x - getX());
    int deltaY = std::abs(target_y - getY());

    int movementCost = move(target_x, target_y, gameField);

    if (movementCost <= getDistance()) {
        int damageNeeded = target.getProtection();

        // check if the hero has enough damage points to attack
        if (getDamage() >= damageNeeded) {
            int damageDealt = std::max(0, getDamage() - damageNeeded);
            target.setHealth(target.getHealth() - damageDealt);

            if (target.getHealth() <= 0) {
                target.setHealth(0);
                gameField->eraseContent(target.getX(),target.getY());
            }
        } else {
        }
    }
}

void Hero::restoreHealth() { setHealth(maxValue); }

int Decorator::move(int new_x, int new_y, Field *gameField) {
    return 0;
}

int ArcherDecorator::getNumberOfArrows() const { return numberOfArrows; }
void ArcherDecorator::setNumberOfArrows(int arrows) { numberOfArrows = arrows; }

ArcherDecorator::ArcherDecorator(Hero* unit) : character(unit), numberOfArrows(myManager.getCurrentLevel() * 3) {
    character->setSpeed(3);
}


int ArcherDecorator::getMoveCost() const {
    return character->getMoveCost();
}

int ArcherDecorator::move(int new_x, int new_y, Field *gameField) {
    return character->move(new_x, new_y, gameField);
}

void ArcherDecorator::attack(Character &target, Field *gameField) {
    int target_x = target.getX();
    int target_y = target.getY();

    int damageNeeded = target.getProtection();

    int damageDealt = std::max(0, getDamage() - damageNeeded + numberOfArrows / 3);

    target.setHealth(target.getHealth() - damageDealt);

    if (target.getHealth() <= 0) {
        target.setHealth(0);
        gameField->eraseContent(target.getX(), target.getY());
    }
}



KnightDecorator::KnightDecorator(Hero& unit) : character(&unit), swordPoints(myManager.getCurrentLevel() + 3), armorPoints(myManager.getCurrentLevel() + 3) {
    character->setProtection(3);
}

int KnightDecorator::getMoveCost() const {
    int baseMoveCost = character->getMoveCost();
    return baseMoveCost + armorPoints / 2;
}

int KnightDecorator::getSwordPoints() const { return swordPoints; }
void KnightDecorator::setSwordPoints(int points) { swordPoints = points; }

int KnightDecorator::getArmorPoints() const { return armorPoints; }
void KnightDecorator::setArmorPoints(int points) { armorPoints = points; }

int KnightDecorator::move(int new_x, int new_y, Field *gameField) {
    return character->move(new_x, new_y, gameField);
}

void KnightDecorator::attack(Character &target, Field *gameField) {
    int target_x = target.getX();
    int target_y = target.getY();

    int damageNeeded = target.getProtection();

    int damageDealt = std::max(0, getDamage() - damageNeeded + swordPoints / 3);

    target.setHealth(target.getHealth() - damageDealt);

    if (target.getHealth() <= 0) {
        target.setHealth(0);
        gameField->eraseContent(target.getX(), target.getY());

    }
}



