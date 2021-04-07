//
// Created by student on 17.06.2020.
//

#ifndef CARRENTALPROJECT_ITEMMANAGER_H
#define CARRENTALPROJECT_ITEMMANAGER_H


#include <repositories/ItemRepository.h>

class ItemManager {
private:
    ItemRepository* iRepo;
public:
    ItemManager(ItemRepository *iRepo);

    ItemPtr registerMovie(std::string newTitle, int newBasePrice, std::string newDirector, bool BlueRay);
    ItemPtr registerMusic(std::string newTitle, int newBasePrice, std::string artist, bool Original);
    ItemPtr registerGame(std::string newTitle, int newBasePrice, std::string studio, bool Console);

    void unregisterItem(ItemPtr item);

    ItemPtr getItem(std::string Title);

    ItemRepository *getIRepo() const;

};


#endif //CARRENTALPROJECT_ITEMMANAGER_H
