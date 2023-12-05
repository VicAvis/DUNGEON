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

const int N = 5;

void PrintField(Field* MainF) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (MainF->cells[i][j].hasObstacle())
                cout << setw(3) << 'x';
            else if (MainF->cells[i][j].hasUnitPresent())
                cout << setw(3) << 'u';
            else
                cout << setw(3) << 0;
        }
        cout << endl;
    }
}

void TestLab1(Manager MainM){
    Monster monster;
    Hero hero;
    MainM.createField(N, N, 2, 1);
    cout << "Current level=" << MainM.CurrentLevel << endl;
    PrintField(MainM.gameField);
    cout << "Hero status:" << endl;
    cout << "position: (" << MainM.gameField->hero->getX() << ", " << MainM.gameField->hero->getY() << "), health: " << MainM.gameField->hero->getHealth()
         << ", damage: " << MainM.gameField->hero->getDamage() << ", protection: " << MainM.gameField->hero->getProtection()
         << ", speed: " << MainM.gameField->hero->getSpeed() << ", distance: " << MainM.gameField->hero->getDistance() << std::endl;
    cout << endl;

    MainM.gameField->hero->diceResults();
    cout << "Hero status:" << endl;
    cout << "position: (" << MainM.gameField->hero->getX() << ", " << MainM.gameField->hero->getY() << "), health: " << MainM.gameField->hero->getHealth()
         << ", damage: " << MainM.gameField->hero->getDamage() << ", protection: " << MainM.gameField->hero->getProtection()
         << ", speed: " << MainM.gameField->hero->getSpeed() << ", distance: " << MainM.gameField->hero->getDistance() << std::endl;
    cout << endl;

    cout << "Monster status:" << endl;
    cout << "position: (" << MainM.gameField->monster->getX() << ", " << MainM.gameField->monster->getY() << "), health: " << MainM.gameField->monster->getHealth()
         << ", damage: " << MainM.gameField->monster->getDamage() << ", protection: " << MainM.gameField->monster->getProtection()
         << ", speed: " << MainM.gameField->monster->getSpeed() << ", active: " << (MainM.gameField->monster->isActive() ? "yes" : "no") << std::endl;
    cout << endl;

    cout << "Hero attacks the monster" << endl;
    MainM.gameField->hero->attack(*MainM.gameField->monster, MainM.gameField);

    cout << "Monster status after attack:" << endl;
    cout << "position: (" << MainM.gameField->monster->getX() << ", " << MainM.gameField->monster->getY() << "), health: " << MainM.gameField->monster->getHealth()
         << ", damage: " << MainM.gameField->monster->getDamage() << ", protection: " << MainM.gameField->monster->getProtection()
         << ", speed: " << MainM.gameField->monster->getSpeed() << ", active: " << (MainM.gameField->monster->isActive() ? "yes" : "no") << std::endl;
    cout << endl;

    cout << "Monster counterattacks" << endl;
    Monster::MonsterContainer monsters = {*MainM.gameField->monster};
    MainM.gameField->monster->calculateMonsterAttack(*MainM.gameField->hero, monsters);

    cout << "Hero status after attack:" << endl;
    cout << "position: (" << MainM.gameField->hero->getX() << ", " << MainM.gameField->hero->getY() << "), health: " << MainM.gameField->hero->getHealth()
         << ", damage: " << MainM.gameField->hero->getDamage() << ", protection: " << MainM.gameField->hero->getProtection()
         << ", speed: " << MainM.gameField->hero->getSpeed() << ", distance: " << MainM.gameField->hero->getDistance() << std::endl;
    cout << endl;

    if (!monster.isActive()) {
        cout << "Monster is dead" << endl;
    } else {
        cout << "Monster is still active" << endl;
    }
}

int main(){
    srand(static_cast<unsigned int>(time(NULL)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Manager MainManager;
    TestLab1(MainManager);
    return 0;
}