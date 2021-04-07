//
// Created by student on 07.06.2020.
//

#ifndef CARRENTALPROJECT_ITEM_H
#define CARRENTALPROJECT_ITEM_H


#include <string>
#include "typedefs.h"

class Item {
private:
    int basePrice; // czy nie powinnismy tu zrobic unsigned int?
    std::string title;
    bool rented = false;
public:
    //konstruktor
    Item(std::string title, int basePrice);
    //destruktor
    virtual ~Item();
    //gettery
    std::string getItemInfo();
    virtual double getActualRentalPrice();
    std::string getTitle();
    bool isRented();
    int getBasePrice();
    //settery
    void setBasePrice(int newBasePrice);
    void setRented(bool newRented);
    void setTitle(const std::string &newTitle);
};


#endif //CARRENTALPROJECT_ITEM_H
