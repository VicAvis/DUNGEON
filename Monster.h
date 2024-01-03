#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
class Hero;

class Monster : public Character {

public:
    //using MonsterContainer = std::array<Monster, 3>;
    using Character::Character;
    Monster() noexcept;
    //   void setMonsterContainer(int level);
    bool isActive() const;
    virtual void MonsterAttack(Hero &hero, Monster& monster);
    int move(int new_x, int new_y, Field* gameField) override;
    void attack(Character& target, Field* gameField) override;
};

class Goblin : public Monster {
    virtual void MonsterAttack(Hero& hero, Monster& monster);
};

class Hydra : public Monster {
    virtual void MonsterAttack(Hero& hero, Monster& monster);

};

#endif // MONSTER_H
