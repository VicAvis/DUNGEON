#include <algorithm>
#include "Monster.h"
#include "Manager.h"

bool Monster::isActive() const { return getHealth() != 0; }

Monster::Monster() noexcept {
    Manager main;
    setSpeed(6);
    setProtection(1);
    setDamage(12);
    setHealth(10);
    setX(0);
    setY(0);
}

void Monster::MonsterAttack(Hero& hero, Monster& monster) {
    //for (auto& monster : monsters) {
    int monsterDistance = std::max(std::abs(hero.getX() - monster.getX()), std::abs(hero.getY() - monster.getY()));

    int totalAttack;
    // порахувати загальну атаку тих монстрів, які знаходяться на 1 клітинку від героя
    if(monster.isActive()){
        if (monsterDistance <= hero.getDistance()) {
            totalAttack = monster.getDamage();
        } else {
            totalAttack = 0;
        }
    }
    else{
        return;
    }

    int heroDefense = hero.getProtection();
    int damage;

    if (totalAttack > heroDefense) {
        damage = totalAttack - heroDefense;
    } else {
        damage = 0;
    }

    hero.reduceHealth(damage);
    //}
}

int Monster::move(int new_x, int new_y, Field *gameField) {
    return 0;
}

void Monster::attack(Character &target, Field *gameField) {
}

void Hydra::MonsterAttack(Hero& hero, Monster& monster) {
    //for (auto& monster : monsters) {
    int monsterDistance = std::max(std::abs(hero.getX() - monster.getX()), std::abs(hero.getY() - monster.getY()));

    int totalAttack;
    if (monster.isActive()) {
        if (monsterDistance <= hero.getDistance()) {
            totalAttack = monster.getDamage();
        }
        else {
            totalAttack = 0;
        }
    }
    else {
        return;
    }

    int heroDefense = hero.getProtection();
    int damage;

    if (totalAttack > heroDefense) {
        damage = totalAttack - heroDefense;
    }
    else {
        damage = 0;
    }

    hero.reduceHealth(damage);
    hero.setProtection(hero.getProtection() - 1);
    //}
}

void Goblin::MonsterAttack(Hero& hero, Monster& monster) {
    // for (auto& monster : monsters) {
    int monsterDistance = std::max(std::abs(hero.getX() - monster.getX()), std::abs(hero.getY() - monster.getY()));

    int totalAttack;
    if (monster.isActive()) {
        if (monsterDistance <= hero.getDistance()) {
            totalAttack = monster.getDamage();
        }
        else {
            totalAttack = 0;
        }
    }
    else {
        return;
    }

    int heroDefense = hero.getProtection();
    int damage;

    if (totalAttack > heroDefense) {
        damage = totalAttack - heroDefense;
    }
    else {
        damage = 0;
    }

    hero.reduceHealth(damage);
    //}
}
//void Monster::setMonsterContainer(int level)
//{
//    int const count = level / 3;
//    using MonsterContainer = std::array<Monster, count>;
//}