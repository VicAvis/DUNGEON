#include <algorithm>
#include "Monster.h"
#include "Manager.h"

bool Monster::isActive() const { return getHealth() != 0; }

Monster::Monster() noexcept {
    Manager main;
    //state = new FarFromHeroState();
    setSpeed(6);
    setProtection(1);
    setDamage(12);
    setHealth(10);
    setX(0);
    setY(0);
}

void Monster::MonsterAttack(Hero& hero, Monster& monsters) {
    /*//for (auto& monster : monsters) {
    int monsterDistance = std::max(std::abs(hero.getX() - getX()), std::abs(hero.getY() - getY()));

    int totalAttack;
    // порахувати загальну атаку тих монстрів, які знаходяться на 1 клітинку від героя
    if(isActive()){
        if (monsterDistance <= hero.getDistance()) {
            totalAttack = getDamage();
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
    //}*/
}

void Monster::MonsterMove(Hero& hero, Monster& monsters, Field* gameField) {

}
void Monster::attack(Character &target, Field *gameField) {
}

int Monster::move(int new_x, int new_y, Field *gameField) {
    return 0;
}

int Monster::getMoveCost() const {
    return 0;
}

void Hydra::MonsterAttack(Hero& hero, Monster& monsters) {
    //for (auto& monster : monsters) {
    int totalAttack;
    // порахувати загальну атаку тих монстрів, які знаходяться на 1 клітинку від героя
    if (isActive()) {
        if ((getX() == hero.getX() - 1 || getX() == hero.getX() + 1) && (getY() == hero.getY() - 1 || getY() == hero.getY() + 1)) {
            totalAttack = getDamage();
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
    hero.setProtection(hero.getProtection() - 1);
}
void Hydra::MonsterMove(Hero& hero, Monster& monsters, Field* gameField) {
    int mX = getX(), mY = getY();
    int hX = hero.getX(), hY = hero.getY();
    
    if (hX == mX && hY == mY) return; //error - monstr = hero

    // перевірка на зону атаки - старт
    if ((mX == hX - 1 || mX == hX + 1) && (mY == hY - 1 || mY == hY + 1)) {
        MonsterAttack(hero, monsters);
        return;
    }
    // перевірка на зону атаки - фініш
     
    // перевірка на розміщення поряд з героєм - старт
    if (mX == hX && (mY == hY - 1 || mY == hY + 1)) {
        gameField->moveUnit(*this, getX(), getY()+1);
        return;
    }
    else if (mY == hY && (mX == hX - 1 || mX == hX + 1)) {
        gameField->moveUnit(*this, getX()+1, getY());
        return;
    }
    // перевірка на розміщення порід з героєм - фініш
    
    // всі інші випадки - старт
    int delX = hX - mX, delY = hY - mY;
    if (std::abs(delX) > std::abs(delY)) {
        int newX = getX() + (delX > 0 ? 1 : (delX < 0 ? -1 : 0));
        if (gameField->isCellHasObstacle(newX, mY)) {
            return;
        }
        gameField->moveUnit(*this, newX, mY);
    }
    else {
        gameField->moveUnit(*this, getX(), getY()+ (delY > 0 ? 1 : (delY < 0 ? -1 : 0)));
    }
    // всі інші випадки - фініш
}
void Goblin::MonsterAttack(Hero& hero, Monster& monsters) {
    //for (auto& monster : monsters) {
    int totalAttack;
    // порахувати загальну атаку тих монстрів, які знаходяться на 1 клітинку від героя
    if (isActive()) {
        if ((getX() == hero.getX() && (getY() == hero.getY() - 1 || getY() == hero.getY() + 1)) || (getY() == hero.getY() && (getX() == hero.getX() - 1 || getX() == hero.getX() + 1))) {
            totalAttack = getDamage();
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

/*
void FarFromHeroState::Attack(Hero& hero, Monster& monsters) {
}
void AttackState::Attack(Hero& hero, Monster& monsters){
}
*/
