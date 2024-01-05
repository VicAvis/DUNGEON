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

class Decorator: public Character{
public:
    virtual int move(int new_x, int new_y, Field *gameField);
};

class ArcherDecorator: public Decorator{
private:
    Hero* character;
    int numberOfArrows{};

public:
    ArcherDecorator(Hero* unit);
    int getNumberOfArrows() const;
    void setNumberOfArrows(int arrows);
    int getMoveCost() const override;
    int move(int new_x, int new_y, Field *gameField) override;
    void attack(Character &target, Field *gameField) override;
};

class KnightDecorator: public Decorator{
private:
    Hero* character;
    int swordPoints;
    int armorPoints;

public:
    KnightDecorator(Hero &unit);
    int getSwordPoints() const;
    void setSwordPoints(int points);
    int getArmorPoints() const;
    void setArmorPoints(int points);
    int getMoveCost() const override;
    int move(int new_x, int new_y, Field *gameField) override;
    void attack(Character &target, Field *gameField) override;
};

#endif //HERO_H
