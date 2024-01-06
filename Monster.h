#pragma once
#ifndef MONSTER_H
#define MONSTER_H

#include "Character.h"
class HeroBase;
class MonsterState;

class Monster : public Character {
public:
    MonsterState* state;
    void ChangeState(HeroBase& hero);
    //using MonsterContainer = std::array<Monster, 3>;
    using Character::Character;
    Monster(); // noexcept;
    bool isActive() const;
    //virtual void MonsterAttack(Hero &hero);
    //virtual void MonsterMove(Hero& hero, Monster& monsters, Field* gameField);
    virtual void Attack(HeroBase& hero, Monster& monster);
    virtual void Move(HeroBase& hero, Field* gameField, Monster& monster);
    void setState(MonsterState* newState);
    ~Monster();
};

class MonsterState {
protected:
public:
    //Monster monster;
    int StateName;
    MonsterState(int sn) : StateName(sn) {}
    //MonsterState(Monster& newmonster);
    virtual void Attack(HeroBase& hero, Monster& monster); //, Monster& monster
    virtual void Move(HeroBase& hero, Field* gameField, Monster& monster);
};

class AttackState : public MonsterState {
public:

    //int StateName;
    AttackState(int sn);
    virtual void Attack(HeroBase& hero, Monster& monster);
    virtual void Move(HeroBase& hero, Field* gameField, Monster& monster);
};

class NearHeroState : public MonsterState {
public:

    //int StateName;
    NearHeroState(int sn);
    virtual void Attack(HeroBase& hero, Monster& monster);
    virtual void Move(HeroBase& hero, Field* gameField, Monster& monster);
};

class FarFromHeroState : public MonsterState {
public:
    //int StateName; 
    FarFromHeroState(int sn);
    virtual void Attack(HeroBase& hero, Monster& monster);
    virtual void Move(HeroBase& hero, Field* gameField, Monster& monster);
};

/*class Goblin : public Monster {
    virtual void MonsterAttack(Hero& hero, Monster& monster);
    virtual void MonsterMove(Hero& hero, Monster& monsters, Field* gameField);
};

class Hydra : public Monster {
    virtual void MonsterAttack(Hero& hero, Monster& monster);
    virtual void MonsterMove(Hero& hero, Monster& monsters, Field* gameField);
};
*/
#endif // MONSTER_H