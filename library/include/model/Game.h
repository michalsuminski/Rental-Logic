//
// Created by student on 16.06.2020.
//

#ifndef CARRENTALPROJECT_GAME_H
#define CARRENTALPROJECT_GAME_H


#include "Item.h"
#include <string>

class Game : public Item{
private:
    std::string studio;
    bool Console;
public:
    Game(const std::string &title, int basePrice, const std::string &studio, bool console);

    virtual ~Game();

    const std::string &getStudio() const;

    bool isConsole();

    double getActualRentalPrice() override;
};


#endif //CARRENTALPROJECT_GAME_H
