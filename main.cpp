#include <iostream>
#include "hero.h"
#include "character.h"
#include "item.h"



int main() {

    Hero hero("Annina", 100, 500);
    Character enemy1("Matthias", 30, 20);
    Character enemy2("Pascal", 40, 30);


    Item sword("Schwert", 100);
    Item shield("Schild", 50);
    enemy1.addInventoryItem(sword);
    enemy2.addInventoryItem(shield);

    if (hero.fight(enemy1)) {
        std::cout << "Annina hat noch " << hero.getHealth() << " Lebenspunkte uebrig." << std::endl;
        Item loot("Der Eine Ring", 10);
        hero.addInventoryItem(loot);
        std::cout << "Neuer Gegenstand im Inventar." << std::endl;
    }

    if (hero.fight(enemy2)) {
        std::cout << "Annina hat noch " << hero.getHealth() << " Lebenspunkte uebrig." << std::endl;
        Item loot("Zauberstab", 100);
        hero.addInventoryItem(loot);
        std::cout << "Neuer Gegenstand im Inventar." << std::endl;
    }

    for (std::vector<Item>::size_type i = 0; i < hero.equipment.size(); i++) {
        hero.sellItem(i);
    }



    return 0;
}











    /*
    srand(time(nullptr));

    Hero_t hero;
    initHero(&hero, "Annina", 300, 100);

    Character_t enemy1, enemy2;
    initCharacter(&enemy1, "Matthias", 50, 20);
    initCharacter(&enemy2, "Pascal", 100, 30);

    if (fight(&hero, &enemy1)) {
        std::cout << "Annina hat noch " << hero.health << " Lebenspunkte uebrig." << std::endl;
        Item_t loot;
        initItem(&loot, "Der Eine Ring", 10);
        hero.inventory[0] = loot;
        std::cout << "Neuer Gegenstand im Inventar." << std::endl;
    }

    if (fight(&hero, &enemy2)) {
        std::cout << "Annina hat noch " << hero.health << " Lebenspunkte uebrig." << std::endl;
        Item_t loot;
        initItem(&loot, "Zauberstab", 100);
        hero.inventory[1] = loot;
        std::cout << "Neuer Gegenstand im Inventar." << std::endl;
    }

    for (int i = 0; i < 10; ++i) {
        if (hero.inventory[i].isValid) {
            sellItem(&hero, i);
        }
    }

    return 0;
}
     */