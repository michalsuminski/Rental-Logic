//
// Created by student on 07.06.2020.
//

#include <sstream>
#include <model/Item.h>

Item::Item(std::string title, int basePrice) : title(title), basePrice(basePrice) {}

Item::~Item() = default;

std::string Item::getItemInfo() {
    std::stringstream napis;
    napis << getTitle() << getActualRentalPrice();
    return napis.str();
}

double Item::getActualRentalPrice() {
    return basePrice;
}

std::string Item::getTitle() {
    return title;
}

bool Item::isRented() {
    return rented;
}

void Item::setBasePrice(int newBasePrice) {
    Item::basePrice = newBasePrice;
}

void Item::setRented(bool newRented) {
    Item::rented = newRented;
}

int Item::getBasePrice() {
    return basePrice;
}

void Item::setTitle(const std::string &newTitle) {
    if(!newTitle.empty()) title = newTitle;
}


