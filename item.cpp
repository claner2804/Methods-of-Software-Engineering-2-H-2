#include <cstring>
#include "item.h"


//Konstruktoren und Destruktor
Item::Item() : value(0), isValid(false) {}

Item::Item(const std::string &name, int value) : name(name), value(value),isValid(true) {}

Item::~Item() = default;



//Getter und Setter
std::string Item::getName() const {
    return name;
}

int Item::getValue() const {
    return value;
}

bool Item::getIsValid() const {
    return isValid;
}

void Item::setName(const std::string &name) {
    this->name = name;
}

void Item::setValue(int value) {
    this->value = value;
}

void Item::setIsValid(bool isValid) {
    this->isValid = isValid;
}

void Item::invalidateItem() {
    isValid = false;
}








/*
void initItem(Item_t* item, const char* name, int value) {
    strncpy(item->name, name, sizeof (item->name) - 1);
    item->name[sizeof (item->name) - 1] = '\0';
    item->value = value;
    item->isValid = true;
}

void invalidateItem(Item_t* item) {
    item->isValid = false;
}
 */