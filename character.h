
#ifndef CHARACTER_H
#define CHARACTER_H

#include "item.h"
#include "hero.h"
#include <string>
#include <vector>


class Character {

public:
    Character();
    Character(const std::string& name, int health, int gold);
    virtual ~Character();

    //Methoden
    virtual void attack(Character& target);
    void receiveItem(const Item& item);
    Item* getItem(int index);
    int addInventoryItem(const Item& item);
    Item removeInventoryItem(int slot);

    //Getter und Setter
    std::string getName() const;
    int getHealth() const;
    int getGold() const;
    void setName(const std::string& name);
    void setHealth(int health);
    void setGold(int gold);
    int getInventorySize() const;

protected:
    std::string name;
    int health;
    int gold;
    std::vector<Item> inventory;

};


#endif //CHARACTER_H









/*
struct Item_t;
struct Hero_t;

struct Character_t {
    char name[50];
    int health;
    int gold;
    Item_t inventory[10];
};

void initCharacter(Character_t* character, const char* name, int health, int gold);
void attack(Character_t* character, Hero_t* hero);

 */

