#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

const int maxValue = 6;
const int startValue = 1;

class Field;

class Character {
private:
    int char_x, char_y;
    int health;
    int protection;
    int damage;
    int speed;

public:
    int getDamage() const;
    int getSpeed() const;
    void reduceHealth(int amount);
    int getHealth() const;
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    void setHealth(int value);
    void setDamage(int value);
    void setProtection(int value);
    void setSpeed(int value);
    int getProtection() const;
    void diceResults();

    virtual int move(int new_x, int new_y, Field* gameField) = 0;
    virtual void attack(Character& target, Field* gameField) = 0;

     void increaseDamage(int amount);
     void increaseProtection(int amount);
     void increaseHealth(int amount);

 };

#endif // CHARACTER_H
