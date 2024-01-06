#pragma once
#ifndef HERO_H
#define HERO_H
#include "Character.h"
class Monster;

class HeroBase : public Character {
private:
    int distance{};
protected:
    int moveCost{};

public:

    using Character::Character;
    HeroBase() noexcept;

    void setDistance(int value);
    void setMoveCost(int value);
    int getDistance() const;
    void diceResults();

    void increaseDistance(int amount);
    virtual int move(int new_x, int new_y, Field* gameField, int movementCost) = 0;
    virtual void attack(Character& target, Field* gameField, int damageDealt, bool fromDistance) = 0;
    virtual int getMoveCost() const = 0;
    virtual std::string getType() const = 0;
    virtual int getNumberOfArrows() const = 0;
    virtual int getSwordPoints() const = 0;
    virtual int getArmorPoints() const = 0;

    void restoreHealth();
};

class Hero: public HeroBase{
public:
    using HeroBase::HeroBase;
    int move(int new_x, int new_y, Field* gameField, int movementCost) override;
    void attack(Character& target, Field* gameField, int damageDealt, bool fromDistance) override;
    int getMoveCost() const override;
    std::string getType() const override;
    int getNumberOfArrows() const override;
    int getSwordPoints() const override;
    int getArmorPoints() const override;
};

class Decorator: public Hero{
public:
    virtual void attack(Character& target, Field* gameField, int damageDealt, bool fromDistance) = 0;
    virtual int move(int new_x, int new_y, Field* gameField, int movementCost) = 0;
    int getMoveCost() const = 0;
    virtual int getNumberOfArrows() const = 0;
    virtual int getSwordPoints() const = 0;
    virtual int getArmorPoints() const = 0;
};

class ArcherDecorator: public Decorator{
private:
    Hero* character;
    int numberOfArrows{};

public:
    explicit ArcherDecorator(Hero* unit);
    int getNumberOfArrows() const override;
    int getSwordPoints() const override;
    int getArmorPoints() const override;
    void setNumberOfArrows(int arrows);
    int getMoveCost() const override;
    std::string getType() const override;
    int move(int new_x, int new_y, Field* gameField, int movementCost) override;
    void attack(Character &target, Field *gameField, int damageDealt, bool fromDistance) override;
};

class KnightDecorator: public Decorator{
private:
    Hero* character;
    int swordPoints;
    int armorPoints;

public:
    explicit KnightDecorator(Hero* unit);
    int getNumberOfArrows() const override;
    int getSwordPoints() const  override;
    void setSwordPoints(int points);
    int getArmorPoints() const override;
    void setArmorPoints(int points);
    int getMoveCost() const override;
    std::string getType() const override;
    int move(int new_x, int new_y, Field *gameField, int movementCost) override;
    void attack(Character &target, Field *gameField, int damageDealt, bool fromDistance) override;
};

#endif //HERO_H