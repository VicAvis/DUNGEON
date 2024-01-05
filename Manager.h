#pragma once
#ifndef OOP_LAB_MANAGER_H
#define OOP_LAB_MANAGER_H

#include <string>
#include "Field.h"

class Manager {
private:
    std::string PersoneName;

public:
    int CurrentLevel;
    friend void TestLab1(Manager);
    Field* gameField;

    void generationObjects(int obst);
    int getCurrentLevel() const;
    void createField(int fieldWidth, int fieldHeight, int obstacles, Monster* monster);

    Field* getGameField() const;
    Manager();
    ~Manager();

};

#endif // OOP_LAB_MANAGER_H

