#include <iostream>
#include <cstring>
#include "hero.h"
#include "character.h"



Hero::Hero(const std::string &name, int health, int gold) : Character(name, health, gold) {}

Hero::~Hero() {};

void Hero::attack(Character &target) {
    Character::attack(target); //Verwendung der Methode aus der Basisklasse
}

//neue Methode
int Hero::addEquipmentItem(const Item &item) {
    if (equipment.size() < 2) { //Ausrüstung hat nur 2 Plätze
        equipment.push_back(item); //wenn noch Platz ist, Item hinzufügen
        return equipment.size() - 1; //Index des hinzugefügten Items
    }
    return -1; //Fehler: Ausrüstung voll
}

bool Hero::fight(Character &enemy) {
    while (health > 0 && enemy.getHealth() > 0) {
        //durch vererbung kann die Methode attack target aus der Basisklasse verwendet werden
        attack(enemy);
        if (enemy.getHealth() <= 0) {
            std::cout << enemy.getName() << " fiel in Ohnmacht!" << std::endl;
            return true;
        }
        if (enemy.getInventorySize() >0) {
            //zufälligen Gegenstand aus dem Inventar des Gegners stehlen
            int slot = rand() % enemy.getInventorySize();
            Item stolenItem = enemy.removeInventoryItem(slot);
            if (addInventoryItem(stolenItem) == -1) {
                std::cout << "Das Inventar von " << name << " ist voll. Kein Platz mehr vorhanden! Der Gegenstand " << stolenItem.getName()
                          << " wurde fallen gelassen." << std::endl;
            } else {
                std::cout << name << " hat " << stolenItem.getName() << " gestohlen." << std::endl;
            }
            //wenn Held gewonnen hat return true
            return true;
        }

        //*this weil die Methode attack in der Basisklasse Character ist
        enemy.attack(*this);
        if (health <= 0) {
            std::cout << name << " fiel in Ohnmacht!" << std::endl;
            return false;
        }
    }
    //wenn der Kampf unentschieden ist
    return false;
}

void Hero::sellItem(int index) {
    Item* item = getItem(index);
    if (item && item->getIsValid()) {
        gold += item->getValue();
        std::cout << "Gegenstand " << item->getName() << " wurde verkauft. "
                  << name << " besitz nun " << gold << " Gold." << std::endl;
        removeInventoryItem(index);
    }
}

//neue Methode
Item Hero::removeEquipmentItem(int slot) {
    //wenn der Slot gültig ist, Item entfernen und zurückgeben
    //static_cast<std::vector<Item>::size_type>(slot) wandelt slot in den Typ size_type um
    if (slot >= 0 && static_cast<std::vector<Item>::size_type>(slot) < equipment.size()) {
        Item item = equipment[slot];
        equipment.erase(equipment.begin() + slot); //Item an der Stelle slot löschen
        return item;
    }
    return Item();
}









/*
void initHero(Hero_t* hero, const char* name, int health, int gold) {
    strncpy(hero->name, name, sizeof(hero->name) - 1);
    hero->name[sizeof(hero->name) - 1] = '\0';
    hero->health = health;
    hero->gold = gold;

    for (int i = 0; i < 10; ++i) {
        invalidateItem(&(hero->inventory[i]));
    }
    for (int i = 0; i < 2; ++i) {
        invalidateItem(&(hero->equipment[i]));
    }
}

void attack(Hero_t* hero, Character_t* enemy) {
    int damage = rand() % 11 + 15;
    enemy->health -= damage;
    std::cout << hero->name << " trifft" << enemy->name << " fuer" << damage << " Lebenspunke!" <<std::endl;
}


bool fight(Hero_t* hero, Character_t* enemy) {
    while (hero->health > 0 && enemy->health >0) {
        attack(hero, enemy);
        if (enemy->health <= 0) {
            std::cout << enemy->name << " fiel in Ohnmacht!" <<std::endl;
            return true;
        }
        attack(enemy, hero);
        if (hero->health <= 0) {
            std::cout << hero->name << " fiel in Ohnmacht!" <<std::endl;
            return false;
        }
    }
    return false;
}

void sellItem(Hero_t* hero, int index) {
    if (hero->inventory[index].isValid) {
        hero->gold += hero->inventory[index].value;
        std::cout << "Gegenstand " << hero->inventory[index].name << " wurde verkauft. "
                  << hero->name << " besitz nun " << hero->gold << " Gold." << std::endl;
        invalidateItem(&hero->inventory[index]);
    }
}
 */