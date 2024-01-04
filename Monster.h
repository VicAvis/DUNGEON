#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
class Hero;
class MonsterState;

class Monster : public Character {
public:
    //MonsterState* state;
    //void ChangeState();
    //using MonsterContainer = std::array<Monster, 3>;
    using Character::Character;
    Monster() noexcept;
    //   void setMonsterContainer(int level);
    bool isActive() const;
    virtual void MonsterAttack(Hero &hero, Monster& monsters);
    virtual void MonsterMove(Hero& hero, Monster& monsters, Field* gameField);
    int move(int new_x, int new_y, Field* gameField) override;
    void attack(Character& target, Field* gameField) override;
    int getMoveCost() const override;
};
/*class MonsterState {
protected:
public:
    Monster monster;
    MonsterState() : monster() {}
    //MonsterState(Monster newmonster) :
    //    monster(newmonster) {}
    virtual void Attack(Hero& hero, Monster& monster);
    virtual void Move();
};
class AttackState : public MonsterState {
public:
    AttackState() : MonsterState(){}
    virtual void Attack(Hero& hero, Monster& monster);
    virtual void Move();
};
class NearHeroState : public MonsterState {
public:
    NearHeroState() : MonsterState() {}
    virtual void Attack(Hero& hero, Monster& monster);
    virtual void Move();
};
class FarFromHeroState : public MonsterState {
public:
    FarFromHeroState() : MonsterState() {}
    virtual void Attack(Hero& hero, Monster& monster);
    virtual void Move();
};*/
class Goblin : public Monster {
    virtual void MonsterAttack(Hero& hero, Monster& monster);
    virtual void MonsterMove(Hero& hero, Monster& monsters, Field* gameField);
};

class Hydra : public Monster {
    virtual void MonsterAttack(Hero& hero, Monster& monster);
    virtual void MonsterMove(Hero& hero, Monster& monsters, Field* gameField);
};

#endif // MONSTER_H
