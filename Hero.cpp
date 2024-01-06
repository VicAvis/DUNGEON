#include <algorithm>
#include <iostream>
#include "Hero.h"
#include "Field.h"
#include "Monster.h"
#include "Manager.h"

Manager myManager;

int HeroBase::getDistance() const { return distance; }
void HeroBase::setDistance(int value) { distance = value; }

void HeroBase::setMoveCost(int value) { moveCost = value; }

HeroBase::HeroBase() noexcept
        : Character(){
    setDistance(4);
    setSpeed(startValue);
    setHealth(maxValue);
    setProtection(startValue);
    setDamage(startValue);
    setMoveCost(0);
}


void HeroBase::diceResults() {
    setSpeed(getSpeed() + (rand() % 6 + 1));
    setDamage(getDamage() + (rand() % 6 + 1));
    setProtection(getProtection() + (rand() % 6 + 1));
    setHealth(getHealth() + (rand() % 3 + 1));
}

void HeroBase::increaseDistance(int amount) { setDistance(getDistance() + amount); }

int Hero::getMoveCost() const { return moveCost; }
int Hero::move(int new_x, int new_y, Field* gameField, int movementCost) {
    //std::cout << "X" <<  gameField->hero->getX() << "Y " << gameField->hero->getY() << std::endl;
    if (gameField->IsCellFree(new_x, new_y)) {
        int deltaX = std::abs(new_x - gameField->hero->getX());
        int deltaY = std::abs(new_y - gameField->hero->getY());
        int moveCost = 0;
        if (deltaX == deltaY) { // diagonal
            if (deltaX == 1 && deltaY == 1) {
                moveCost = movementCost; // move 1 cell - 3 points
            } else {
                moveCost = movementCost + (deltaX - 1); // move by more cells
            }
        } else { // straight movement
         //   std::cout << "movementCost " << movementCost<< std::endl;
            moveCost = movementCost + std::max(deltaX, deltaY) + 1;
        }
        int curSpeed = gameField->hero->getSpeed();
        //std::cout << "curSpeed" <<  curSpeed << "moveCost " << moveCost << std::endl;
        if (curSpeed >= moveCost) {
          //  std::cout << "X" <<  gameField->hero->getX() << "Y " << gameField->hero->getY() << std::endl;
            gameField->eraseContent(gameField->hero->getX(),gameField->hero->getY()); // затерли клітинку
            setX(new_x); // встановили нові координати
            setY(new_y);
            gameField->moveHero(new_x,new_y); // оновили поле

            curSpeed -= moveCost;
            int newDistance = getDistance() + 1;
            setDistance(newDistance);
        }
        else{
            return -1;
        }
        return moveCost;
    }
    return 0;
}

void Hero::attack(Character& target, Field* gameField, int damageDealt, bool fromDistance) {
    int target_x = target.getX();
    int target_y = target.getY();
    int deltaX = std::abs(target_x - getX());
    int deltaY = std::abs(target_y - getY());

    if (fromDistance || (deltaX <= 1 && deltaY <= 1)) {
        int damageNeeded = target.getProtection();

        if (damageDealt >= damageNeeded) {
            target.setHealth(target.getHealth() - damageDealt);

            if (target.getHealth() <= 0) {
                target.setHealth(0);
                gameField->eraseContent(target.getX(), target.getY());
            }
        } else {
        }
    } else {
    }
}


std::string Hero::getType() const {
    return "Hero";
}

int Hero::getNumberOfArrows() const {
    return 0;
}

int Hero::getSwordPoints() const {
    return 0;
}

int Hero::getArmorPoints() const {
    return 0;
}

void HeroBase::restoreHealth() { setHealth(maxValue); }

int ArcherDecorator::getNumberOfArrows() const { return numberOfArrows; }
void ArcherDecorator::setNumberOfArrows(int arrows) { numberOfArrows = arrows; }

ArcherDecorator::ArcherDecorator(Hero* unit) : character(unit), numberOfArrows(myManager.getCurrentLevel() * 4){
    setSpeed(3);
}

int ArcherDecorator::getMoveCost() const {
    return character->getMoveCost();
}

int ArcherDecorator::move(int new_x, int new_y, Field *gameField, int movementCost) {
    return character->move(new_x, new_y, gameField, 0);
}

void ArcherDecorator::attack(Character &target, Field *gameField, int damageDealt, bool fromDistance) {
    int damageNeeded = target.getProtection();
    int damage = std::max(0, getDamage() - damageNeeded + numberOfArrows / 2);

    character->attack(target, gameField, damage,1);
    setNumberOfArrows(getNumberOfArrows() - (numberOfArrows / 2));
}

std::string ArcherDecorator::getType() const {
    return "Archer";
}

int ArcherDecorator::getSwordPoints() const {
    return 0;
}

int ArcherDecorator::getArmorPoints() const {
    return 0;
}

KnightDecorator::KnightDecorator(Hero* unit) : character(unit), swordPoints(myManager.getCurrentLevel() + 3), armorPoints(myManager.getCurrentLevel() + 3) {
    setProtection(3);
}

int KnightDecorator::getMoveCost() const {
    int moveCost = character->getMoveCost();
    return moveCost + (armorPoints / 2);
}

int KnightDecorator::getSwordPoints() const { return swordPoints; }
void KnightDecorator::setSwordPoints(int points) { swordPoints = points; }

int KnightDecorator::getArmorPoints() const{ return armorPoints; }
void KnightDecorator::setArmorPoints(int points) { armorPoints = points; }

int KnightDecorator::move(int new_x, int new_y, Field *gameField, int movementCost) {
    int moveC = getMoveCost();
    return character->move(new_x, new_y, gameField, moveC);
}

void KnightDecorator::attack(Character &target, Field *gameField, int damageDealt, bool fromDistance) {
    int damageNeeded = target.getProtection();
    int damage = std::max(0, getDamage() - damageNeeded + swordPoints / 2);
    character->attack(target, gameField, damage, 0);
    setSwordPoints(std::max(0, getSwordPoints() - (swordPoints / 2)));
}

std::string KnightDecorator::getType() const {
    return "Knight";
}

int KnightDecorator::getNumberOfArrows() const {
    return 0;
}



