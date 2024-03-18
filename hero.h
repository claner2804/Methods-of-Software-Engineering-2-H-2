
#ifndef HERO_H
#define HERO_H

#include "item.h"
#include "character.h"
#include <string>
#include <vector>

class Hero : public Character {

    public:
    Hero(const std::string& name, int health, int gold);
    ~Hero();

    //zusätzliche Methoden für den Helden
    //attribute für die Ausrüstung
    std::vector<Item> equipment;

    //Methoden
    int addEquipmentItem(const Item& item);
    Item removeEquipmentItem(int slot);
    bool fight(Character& enemy);
    void sellItem(int index);

    //Erweiterung der vorhandenen Methoden
    void attack(Character& target) override;
};

#endif














/*
struct Item_t;
struct Character_t;

struct Hero_t {
    char name[50];
    int health;
    int gold;
    Item_t inventory[10];
    Item_t equipment[2];
};

void initHero(Hero_t* hero, const char* name, int health, int gold);
void attack(Hero_t* hero, Character_t* enemy);
bool fight(Hero_t* hero, Character_t* enemy);
void sellItem(Hero_t* hero, int index);
*/

