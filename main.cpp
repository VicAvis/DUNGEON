#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <iomanip>
#include "Field.h"
#include "Monster.h"
#include "Hero.h"
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
         << ", speed: " << character->getSpeed() << endl;
}

void displayHero(const string& title, HeroBase* character) {
    cout << title << ":" << endl;
    cout << "position: (" << character->getX() << ", " << character->getY() << "), health: " << character->getHealth()
         << ", damage: " << character->getDamage() << ", protection: " << character->getProtection()
         << ", speed: " << character->getSpeed();
    if (character->getType() == "Knight") {
        cout << ", sword points: " << character->getSwordPoints()
             << ", armor points: " << character->getArmorPoints() << endl;
    }
    else if (character->getType() == "Archer") {
        cout << ", number of arrows: " << character->getNumberOfArrows() << endl;
    }
}

/*void TestLab1(Manager mainManager) {

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
}*/
/*void TestLab2(Manager mainManager) {
    cout << "\nTest started:\n";
    Hero* archerHero = new Hero();
    cout << "Hero created:\n";
    ArcherDecorator* archerDecorator = new ArcherDecorator(*archerHero);
    cout << "ArcherDecoretor created:\n";
    Monster* OneNewMonster = new Monster();
    cout << "Monster created:\n";
    mainManager.createField(FIELD_SIZE, FIELD_SIZE, 2, OneNewMonster);
    cout << "Field created:\n";
    mainManager.gameField->hero = archerDecorator;
    cout << "Hero changed:\n";
    mainManager.gameField->placeHero();
    cout << "Hero placed:\n";
    cout << "Current level = " << mainManager.CurrentLevel << endl;
    PrintField(mainManager.gameField);

    display("Archer Hero status before dice results", mainManager.gameField->hero);
    cout << " distance: " << mainManager.gameField->hero->getDistance() << endl;

    mainManager.gameField->hero->diceResults();

    display("Archer Hero status after dice results", mainManager.gameField->hero);
    cout << " distance: " << mainManager.gameField->hero->getDistance() << endl;

    Position newPosition = {2, 3};
    mainManager.gameField->hero->move(newPosition.x, newPosition.y, mainManager.gameField);
    PrintField(mainManager.gameField);

    cout << "Archer Hero attacks the monster" << endl;
    display("Monster status", mainManager.gameField->monster);
    cout << ", active: " << (mainManager.gameField->monster->isActive() ? "yes" : "no") << endl << endl;
    mainManager.gameField->hero->attack(*mainManager.gameField->monster, mainManager.gameField);

    display("Monster status after attack", mainManager.gameField->monster);
    cout << ", active: " << (mainManager.gameField->monster->isActive() ? "yes" : "no") << endl << endl;

    mainManager.gameField->monster->state->Move(*mainManager.gameField->hero, mainManager.gameField);
    //mainManager.gameField->monster->MonsterMove(*mainManager.gameField->hero, *mainManager.gameField->monster, mainManager.gameField);
    display("Archer Hero status after monster move", mainManager.gameField->hero);
    cout << " distance: " << mainManager.gameField->hero->getDistance() << endl;
    display("Monster status after monster move", mainManager.gameField->monster);
    cout << ", active: " << (mainManager.gameField->monster->isActive() ? "yes" : "no") << endl << endl;
    PrintField(mainManager.gameField);
    //mainManager.gameField->monster->MonsterAttack(*mainManager.gameField->hero, *mainManager.gameField->monster);
    mainManager.gameField->monster->state->Attack(*mainManager.gameField->hero);

    display("Archer Hero status after counterattack", mainManager.gameField->hero);
    cout << " distance: " << mainManager.gameField->hero->getDistance() << endl;
    PrintField(mainManager.gameField);
    if (!mainManager.gameField->monster->isActive()) {
        cout << "Monster is dead" << endl;
    } else {
        cout << "Monster is still active" << endl;
    }
    //mainManager.gameField->monster->MonsterMove(*mainManager.gameField->hero, *mainManager.gameField->monster, mainManager.gameField);
    mainManager.gameField->monster->state->Move(*mainManager.gameField->hero, mainManager.gameField);
    display("Archer Hero status after monster move", mainManager.gameField->hero);
    cout << " distance: " << mainManager.gameField->hero->getDistance() << endl;
    PrintField(mainManager.gameField);
    //mainManager.gameField->monster->MonsterMove(*mainManager.gameField->hero, *mainManager.gameField->monster, mainManager.gameField);
    mainManager.gameField->monster->state->Move(*mainManager.gameField->hero, mainManager.gameField);
    display("Archer Hero status after monster move", mainManager.gameField->hero);
    cout << " distance: " << mainManager.gameField->hero->getDistance() << endl;
    PrintField(mainManager.gameField);
    delete archerHero;
}*/

void TestLab3(Manager& mainManager) {
    cout << "\nTest has started:\n";
    HeroBase* baseHero = new Hero();
    HeroBase* archerHero = new ArcherDecorator(baseHero);
    Monster* OneNewMonster = new Monster();
    cout << "Monster is created:\n";
    mainManager.createField(FIELD_SIZE, FIELD_SIZE, 2, OneNewMonster);
    mainManager.gameField->hero = archerHero;
    mainManager.gameField->placeHero();
    cout << "Current level = " << mainManager.CurrentLevel << endl;

    PrintField(mainManager.gameField);
    cout << endl;
    cout << endl;
    displayHero("Hero", mainManager.gameField->hero);
    mainManager.gameField->hero->diceResults();
    displayHero("Hero status after dice results", mainManager.gameField->hero);
    display("Monster", mainManager.gameField->monster);

    cout << "Monster state - " << mainManager.gameField->monster->state->StateName << endl;
    mainManager.gameField->monster->Move(*mainManager.gameField->hero,  mainManager.gameField, *mainManager.gameField->monster);
    cout << "Monster state - " << mainManager.gameField->monster->state->StateName << endl;
    mainManager.gameField->monster->Attack(*mainManager.gameField->hero, *mainManager.gameField->monster);
    cout << "Monster state - " << mainManager.gameField->monster->state->StateName << endl;

    PrintField(mainManager.gameField);
    cout << endl;
    displayHero("Hero", mainManager.gameField->hero);
    display("Monster", mainManager.gameField->monster);
    mainManager.gameField->monster->Move(*mainManager.gameField->hero, mainManager.gameField, *mainManager.gameField->monster);
    cout << "Monster state - " << mainManager.gameField->monster->state->StateName << endl;
    mainManager.gameField->monster->Attack(*mainManager.gameField->hero, *mainManager.gameField->monster);
    cout << "Monster state - " << mainManager.gameField->monster->state->StateName << endl;

    PrintField(mainManager.gameField);
    cout << endl;
    display("Hero: ", mainManager.gameField->hero);
    display("Monster:", mainManager.gameField->monster);

    mainManager.gameField->monster->Move(*mainManager.gameField->hero, mainManager.gameField, *mainManager.gameField->monster);
    cout << "Monster state - " << mainManager.gameField->monster->state->StateName << endl;
    mainManager.gameField->monster->Attack(*mainManager.gameField->hero, *mainManager.gameField->monster);
    cout << "Monster state - " << mainManager.gameField->monster->state->StateName << endl;

    PrintField(mainManager.gameField);
    cout << endl;
    displayHero("Hero", mainManager.gameField->hero);
    display("Monster", mainManager.gameField->monster);
    // added
    cout << "\n\nHero attacks the monster" << endl;
    PrintField(mainManager.gameField);
    mainManager.gameField->hero->attack(*mainManager.gameField->monster, mainManager.gameField, 0,1);
    displayHero("Hero", mainManager.gameField->hero);
    display("Monster", mainManager.gameField->monster);
    PrintField(mainManager.gameField);
    cout << "\n\n\n\n" << endl;
}

void TestLab3_part2(Manager& mainManager){
    cout << "Now we will test the knight!" << endl;
    HeroBase* baseHero = new Hero();
    HeroBase* knightHero = new KnightDecorator(baseHero);
    Monster* OneNewMonster = new Monster();
    mainManager.createField(FIELD_SIZE, FIELD_SIZE, 2, OneNewMonster);
    mainManager.gameField->hero = knightHero;
    mainManager.gameField->placeHero();
    PrintField(mainManager.gameField);
    mainManager.gameField->hero->diceResults();
    displayHero("Hero", mainManager.gameField->hero);
    cout << "\n\nCurrent level = " << mainManager.CurrentLevel << endl;
    PrintField(mainManager.gameField);
    displayHero("Hero", mainManager.gameField->hero);
    mainManager.gameField->hero->diceResults();
    displayHero("Hero status after dice results", mainManager.gameField->hero);
    display("Monster", mainManager.gameField->monster);

    PrintField(mainManager.gameField);
    mainManager.gameField->hero->move(3,1,mainManager.gameField,0);
    cout << "\n\nHero moved" << endl;
    PrintField(mainManager.gameField);
    cout << "Hero attacks the monster" << endl;
    mainManager.gameField->hero->attack(*mainManager.gameField->monster, mainManager.gameField, 0, 0);
    displayHero("Hero", mainManager.gameField->hero);
    display("Monster", mainManager.gameField->monster);
    PrintField(mainManager.gameField);

}

int main() {
    srand(static_cast<unsigned int>(time(NULL)));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Manager mainManager;

//    cout << "\nRunning TestLab1:" << endl;
//    TestLab1(mainManager);

//    cout << "\nRunning TestLab2:" << endl;
//    TestLab2(mainManager);

    cout << "\nRunning TestLab3:" << endl;
    TestLab3(mainManager);

    cout << "\nRunning TestLab3_part2:" << endl;
    TestLab3_part2(mainManager);

    return 0;
}
