#pragma once
#ifndef HERO_H
#define HERO_H

#include "Character.h"
class Monster;

class Hero : public Character {
private:
    int distance;

public:
    using Character::Character;
    Hero() noexcept;

    void setDistance(int value);
    int getDistance() const;

    void increaseDistance(int amount);

    int move(int new_x, int new_y, Field *gameField) override;

    void attack(Character &target, Field *gameField) override;

    void restoreHealth();
};

#endif //HERO_H
