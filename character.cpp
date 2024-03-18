#include <cstring>
#include <iostream>
#include "character.h"


//Konstruktoren und Destruktor

Character::Character(const std::string &name, int health, int gold) : name(name), health(health), gold(gold) {}

Character::~Character() {}



//Methoden

void Character::attack(Character &target) {
    int damage = rand() % 11 + 5;
    //von Lebenspunkten des Heros abziehen
    target.setHealth(target.getHealth() - damage);
    std::cout << name << " trifft " << target.getName() << " fuer " << damage << " Lebenspunkte!" << std::endl;
}

void Character::receiveItem(const Item &item) {
    inventory.push_back(item); //Item in das Inventar legen
}

Item *Character::getItem(int index) {
    if (index >= 0 && static_cast<std::vector<Item>::size_type>(index) < inventory.size()) {
        return &inventory[index];
    }
    return nullptr;
}

//neue Methode
int Character::addInventoryItem(const Item &item) {
    if (inventory.size() < 10) {
        inventory.push_back(item);
        return inventory.size() - 1; //Index des hinzugefügten Items
    }
    return -1; //Fehler: Inventar voll
}

//neue Methode
Item Character::removeInventoryItem(int slot) {
    if (slot >= 0 && static_cast<std::vector<Item>::size_type>(slot) < inventory.size()) {
        Item item = inventory[slot];
        inventory.erase(inventory.begin() + slot); //Item an der Stelle slot löschen
        return item;
    }
    return Item(); //Fehler: kein Item an diesem Slot
}





//Getter und Setter

std::string Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

int Character::getGold() const {
    return gold;
}

void Character::setName(const std::string &name) {
    this->name = name;
}

void Character::setHealth(int health) {
    this->health = health;
}

void Character::setGold(int gold) {
    this->gold = gold;
}

int Character::getInventorySize() const {
    return inventory.size();
}







/*
void initCharacter(Character_t* character, const char* name, int health, int gold) {
    strncpy(character->name, name, sizeof(character->name) - 1);
    character->name[sizeof(character->name) - 1] = '\0';
    character->health = health;
    character->gold = gold;

    for (int i = 0; i < 10; ++i) {
        invalidateItem(&(character->inventory[i]));
    }
}

void attack(Character_t* character, Hero_t* hero) {
    int damage = rand() % 11 + 5;
    hero->health -= damage;
    std::cout << character->name << " trifft" << hero->name << " fuer" << damage << " Lebenspunke!" <<std::endl;
}
 */