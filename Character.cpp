#include "Character.h"
#include "Manager.h"
#include "cstdlib"
#include "Field.h"
#include <array>

void Character::setProtection(int value) { protection = value; }
int Character::getProtection() const { return protection; }
void Character::increaseHealth(int amount) { setHealth(getHealth() + amount); }

void Character::setHealth(int value) { health = value; }
int Character::getHealth() const { return health; }

int Character::getX() const { return char_x; }
int Character::getY() const { return char_y; }
void Character::setX(int x) { char_x = x; }
void Character::setY(int y) { char_y = y; }


void Character::setDamage(int value) { damage = value; }
int Character::getDamage() const { return damage; }
int Character::getSpeed() const { return speed; }
void Character::setSpeed(int value) { speed = value; }
void Hero::setDistance(int value) { distance = value; }

void Character::reduceHealth(int amount) {
    health -= amount;
    if (health < 0) {
        health = 0;
    }
}
int Hero::getDistance() const { return distance; }

Hero::Hero() noexcept
        : Character(),
          distance(2) {
    setSpeed(startValue);
    setHealth(maxValue);
    setProtection(startValue);
    setDamage(startValue);
}

void Character::increaseDamage(int amount) { setDamage(getDamage() + amount); }
void Character::increaseProtection(int amount) { setProtection(getProtection() + amount); }
void Hero::increaseDistance(int amount) { setDistance(getDistance() + amount); }


void Hero::diceResults() {
    setSpeed(getSpeed() + (rand() % 6 + 1));
    setDamage(getDamage() + (rand() % 6 + 1));
    setProtection(getProtection() + (rand() % 6 + 1));
}

int Hero::move(int new_x, int new_y, Field* gameField){
    if (gameField->freeCell(new_x, new_y)) {
        int deltaX = std::abs(new_x - getX());
        int deltaY = std::abs(new_y - getY()); // герой витрачає очки швидкості для пересування, якщо по діагоналі на одну то мінус 3, а так мінус 2

        int moveCost = 0;
        if (deltaX == deltaY){ // diagonal
            if (deltaX == 1 && deltaY == 1){
                moveCost = 3; // move 1 cell - 3 points
            }
            else{
                moveCost = 3 + (deltaX - 1); // move by more cells
            }
        }
        else { // straight movement
            moveCost = std::max(deltaX, deltaY) + 1;
        }
        int curSpeed = getSpeed();
        if (curSpeed >= moveCost) {
            setX(new_x);
            setY(new_y);
            gameField->moveUnit(*this, new_x, new_y);
            curSpeed -= moveCost;
        }
        return moveCost;
    }
    return 1;
}

void Hero::attack(Monster& target, Field* gameField) {
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
        moveCost = std::max(deltaX, deltaY) + 1;
    }

    if (moveCost <= getDistance()) {
        int damageNeeded = target.getProtection();

        // check if the hero has enough damage points to attack
        if (getDamage() >= damageNeeded) {
            int damageDealt = getDamage() - damageNeeded;
            target.setHealth(target.getHealth() - damageDealt);

            if (target.getHealth() <= 0) {
                target.setHealth(0);
                target.setActive(false);
                gameField->moveUnit(target, -1, -1);
            }
        } else {
            // Handle the case when hero's damage is not enough
        }
    }
}


void Hero::restoreHealth() { setHealth(maxValue); }

bool Monster::isActive() const { return active; }
void Monster::setActive(bool active) {this->active = active; }

Monster::Monster() noexcept {
    Manager main;
    int currentLevel = main.getCurrentLevel();
    setSpeed(currentLevel + 2);
    setProtection(currentLevel + 5);
    setDamage(currentLevel + 1);
    setHealth(currentLevel + 2);
    setX(0);
    setY(0);
}

using MonsterContainer = std::array<Monster, 1>;

void Monster::calculateMonsterAttack(Hero& hero, MonsterContainer& monsters) {
    for (auto& monster : monsters) {
        int monsterDistance = std::max(std::abs(hero.getX() - monster.getX()), std::abs(hero.getY() - monster.getY()));
        int totalAttack = (monsterDistance <= hero.getDistance()) ? monster.getDamage() : 0;

        int heroDefense = hero.getProtection();
        int damage = (totalAttack > heroDefense) ? (totalAttack - heroDefense) : 0;
        hero.reduceHealth(damage);
    }
}



