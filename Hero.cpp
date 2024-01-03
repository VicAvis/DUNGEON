#include <algorithm>
#include "Hero.h"
#include "Field.h"
#include "Monster.h"

int Hero::getDistance() const { return distance; }

Hero::Hero() noexcept
        : Character(){
    setDistance(2);
    setSpeed(maxValue);
    setHealth(maxValue);
    setProtection(3);
    setDamage(maxValue);
}

void Hero::increaseDistance(int amount) { setDistance(getDistance() + amount); }


int Hero::move(int new_x, int new_y, Field* gameField) {
    if (gameField->freeCell(new_x, new_y)) {
        int deltaX = std::abs(new_x - getX());
        int deltaY = std::abs(new_y - getY());

        int moveCost = 0;
        if (deltaX == deltaY) { // diagonal
            if (deltaX == 1 && deltaY == 1) {
                moveCost = 3; // move 1 cell - 3 points
            } else {
                moveCost = 3 + (deltaX - 1); // move by more cells
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

    int moveCost = 0;
    if (deltaX == deltaY) { // diagonal
        if (deltaX == 1 && deltaY == 1) {
            moveCost = 3; // move 1 cell - 3 points
        } else {
            moveCost = 3 + (deltaX - 1); // move by more cells
        }
    } else { // straight movement
        if (!deltaX || !deltaY) {
            moveCost = std::max(deltaX, deltaY) + 1;
        } else {}
    }
    if (moveCost <= getDistance()) {

        int damageNeeded = target.getProtection();

        // check if the hero has enough damage points to attack
        if (getDamage() >= damageNeeded) {
            int damageDealt = getDamage() - damageNeeded;
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
