#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include "Manager.h"

using std::string;
using std::cout;
using std::endl;
using std::setw;

const int FIELD_SIZE = 5;

struct Position {
    int x;
    int y;
};

void PrintField(Field* field) {
    for (int i = 0; i < FIELD_SIZE; i++) {
        for (int j = 0; j < FIELD_SIZE; j++) {
            if (field->cells[i][j].hasObstacle())
                cout << setw(3) << 'x';
            else if (field->cells[i][j].hasUnitPresent())
                cout << setw(3) << 'u';
            else
                cout << setw(3) << 0;
        }
        cout << endl;
    }
}

void display(const string& title, Character* character) {
    cout << title << ":" << endl;
    cout << "position: (" << character->getX() << ", " << character->getY() << "), health: " << character->getHealth()
         << ", damage: " << character->getDamage() << ", protection: " << character->getProtection()
         << ", speed: " << character->getSpeed();
}

void TestLab1(Manager mainManager) {

    mainManager.createField(FIELD_SIZE, FIELD_SIZE, 2, 1);

    cout << "Current level = " << mainManager.CurrentLevel << endl;
    PrintField(mainManager.gameField);

    display("Hero status before dice results", mainManager.gameField->hero);
    cout << endl;

    mainManager.gameField->hero->diceResults();

    display("Hero status after dice results", mainManager.gameField->hero);
    cout << endl;

    display("Monster status", mainManager.gameField->monster);
    cout << ", active: " << (mainManager.gameField->monster->isActive() ? "yes" : "no") << endl << endl;

    Position newPosition = {2, 3};
    mainManager.gameField->hero->move(newPosition.x, newPosition.y, mainManager.gameField);
    PrintField(mainManager.gameField);

    cout << "Hero attacks the monster" << endl;
    mainManager.gameField->hero->attack(*mainManager.gameField->monster, mainManager.gameField);

    display("Monster status after attack", mainManager.gameField->monster);
    cout << ", active: " << (mainManager.gameField->monster->isActive() ? "yes" : "no") << endl << endl;

   // Monster::MonsterContainer monsters = { *mainManager.gameField->monster };
    mainManager.gameField->monster->MonsterAttack(*mainManager.gameField->hero, *mainManager.gameField->monster);

    display("Hero status after counterattack", mainManager.gameField->hero);
    cout << endl;

    if (!mainManager.gameField->monster->isActive()) {
        cout << "Monster is dead" << endl;
    } else {
        cout << "Monster is still active" << endl;
    }
}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Manager mainManager;
    TestLab1(mainManager);
    return 0;
}
