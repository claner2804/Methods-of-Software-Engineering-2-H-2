
#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:

    //Konstruktoren
    Item(); //konstruktor
    Item(const std::string& name, int value);
    ~Item(); // dekonstruktor

    //Getter
    std::string getName() const;
    int getValue() const;
    bool getIsValid() const;

    //Setter
    void setName(const std::string& name);
    void setValue(int value);
    void setIsValid(bool isValid);
    void invalidateItem();

private:
    std::string name;
    int value;
    bool isValid;


};












/*
struct Item_t {
    char name[50];
    int value;
    bool isValid;
};

void initItem(Item_t* item, const char* name, int value);
void invalidateItem(Item_t* item);
*/

#endif