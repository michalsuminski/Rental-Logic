//
// Created by student on 16.06.2020.
//

#include "model/Game.h"

Game::Game(const std::string &title, int basePrice, const std::string &studio, bool console) : Item(title, basePrice),
                                                                                               studio(studio),
                                                                                               Console(console) {}

Game::~Game() {

}

const std::string &Game::getStudio() const {
    return studio;
}

bool Game::isConsole() {
    return Console;
}

double Game::getActualRentalPrice(){
    if(isConsole()){
        return Item::getActualRentalPrice()*1.3;
    }
    return Item::getActualRentalPrice();
}
