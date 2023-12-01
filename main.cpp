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
    hero.diceResults();
    cout << "Hero status:" << endl;
    cout << "Position: (" << MainM.gameField->hero->getX() << ", " << MainM.gameField->hero->getY() << "), Health: " << MainM.gameField->hero->getHealth()
         << ", Damage: " << MainM.gameField->hero->getDamage() << ", Protection: " << MainM.gameField->hero->getProtection()
         << ", Speed: " << MainM.gameField->hero->getSpeed() << ", Distance: " << MainM.gameField->hero->getDistance() << std::endl;
    cout << endl;

    cout << "Monster status:" << endl;
    cout << "Position: (" << monster.getX() << ", " << monster.getY() << "), Health: " << monster.getHealth()
         << ", Damage: " << monster.getDamage() << ", Protection: " << monster.getProtection()
         << ", Speed: " << monster.getSpeed() << ", Active: " << (monster.isActive() ? "Yes" : "No") << std::endl;
    cout << endl;

    cout << "Hero attacks the monster" << endl;
    hero.attack(monster, MainM.gameField);

    // Print the status after the attack
    cout << "Monster status after attack:" << endl;
    cout << "Position: (" << monster.getX() << ", " << monster.getY() << "), Health: " << monster.getHealth()
         << ", Damage: " << monster.getDamage() << ", Protection: " << monster.getProtection()
         << ", Speed: " << monster.getSpeed() << ", Active: " << (monster.isActive() ? "Yes" : "No") << std::endl;
    cout << endl;

    cout << "Monster counterattacks" << endl;
    Monster::MonsterContainer monsters = {monster};
    monster.calculateMonsterAttack(hero, monsters);

// Print the status after the monster's attack
    cout << "Hero status after attack:" << endl;
    cout << "Position: (" << MainM.gameField->hero->getX() << ", " << MainM.gameField->hero->getY() << "), Health: " << MainM.gameField->hero->getHealth()
         << ", Damage: " << MainM.gameField->hero->getDamage() << ", Protection: " << MainM.gameField->hero->getProtection()
         << ", Speed: " << MainM.gameField->hero->getSpeed() << ", Distance: " << MainM.gameField->hero->getDistance() << std::endl;
    cout << endl;

    if (!monster.isActive()) {
        cout << "Monster defeated!" << endl;
    } else {
        cout << "Monster still active." << endl;
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