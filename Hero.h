#pragma once
#ifndef HERO_H
#define HERO_H

#include "Character.h"
class Monster;

class Hero : public Character {
private:
    int distance{};
    int moveCost{};

public:
    using Character::Character;
    Hero() noexcept;

    void setDistance(int value);
    void setMoveCost(int value);
    int getDistance() const;

    void increaseDistance(int amount);

    int move(int new_x, int new_y, Field *gameField) override;
    void attack(Character &target, Field *gameField) override;
    int getMoveCost() const override;

    void restoreHealth();
};

class Decorator: public Hero{
public:
    virtual int move(int new_x, int new_y, Field *gameField);
};

class ArcherDecorator: public Decorator{
private:
    Hero &character;

public:
    ArcherDecorator(Hero &unit);
    int getMoveCost() const override;
    int move(int new_x, int new_y, Field *gameField) override;
    void attack(Character &target, Field *gameField) override;
};

class KnightDecorator: public Decorator{
private:
    Hero &character;

public:
    KnightDecorator(Hero &unit);
    int getMoveCost() const override;
    int move(int new_x, int new_y, Field *gameField) override;
    void attack(Character &target, Field *gameField) override;
};

#endif //HERO_H
