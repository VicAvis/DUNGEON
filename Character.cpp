#include <cstdlib>
#include "Character.h"
#include "Hero.h"

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
void Character::increaseDamage(int amount) { setDamage(getDamage() + amount); }
void Character::increaseProtection(int amount) { setProtection(getProtection() + amount); }

void Character::diceResults() {
    setSpeed(getSpeed() + (rand() % 6 + 1));
    setDamage(getDamage() + (rand() % 6 + 1));
    setProtection(getProtection() + (rand() % 6 + 1));
}

void Character::reduceHealth(int amount) {
    health -= amount;
    if (health < 0) {
        health = 0;
    }
}


