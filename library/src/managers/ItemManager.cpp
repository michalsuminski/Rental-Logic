//
// Created by student on 17.06.2020.
//

#include <model/Movie.h>
#include <model/Music.h>
#include <model/Game.h>
#include "managers/ItemManager.h"

ItemPtr ItemManager::registerMovie(std::string newTitle, int newBasePrice, std::string newDirector, bool BlueRay) {
    ItemPtr item(new Movie(newTitle, newBasePrice, newDirector, BlueRay));
    for(int i=0; i<iRepo->get_items_number(); i++){
        if(iRepo->getItem(i)->getItemInfo()==item->getItemInfo()) return iRepo->getItem(i);
    }
    iRepo->addItem(item);
    return item;
}

ItemPtr ItemManager::registerMusic(std::string newTitle, int newBasePrice, std::string artist, bool Original) {
    ItemPtr item(new Music(newTitle, newBasePrice, artist, Original));
    for(int i=0; i<iRepo->get_items_number(); i++){
        if(iRepo->getItem(i)->getItemInfo()==item->getItemInfo()) return iRepo->getItem(i);
    }
    iRepo->addItem(item);
    return item;
}

ItemPtr ItemManager::registerGame(std::string newTitle, int newBasePrice, std::string studio, bool Console) {
    ItemPtr item(new Game(newTitle, newBasePrice, studio, Console));
    for(int i=0; i<iRepo->get_items_number(); i++){
        if(iRepo->getItem(i)->getItemInfo()==item->getItemInfo()) return iRepo->getItem(i);
    }
    iRepo->addItem(item);
    return item;
}

void ItemManager::unregisterItem(ItemPtr item) {
    for(int i=0; i<iRepo->get_items_number(); i++){
        //if(iRepo->getItem(i)==item) iRepo->getItems().erase(iRepo->getItems().begin()+i);
        if(iRepo->getItem(i)->getItemInfo()==item->getItemInfo()) iRepo->deleteItem(item);
    }
}

ItemPtr ItemManager::getItem(std::string Title) {
    ItemPredicate p = [Title](ItemPtr i)->bool{
        return i->getTitle()==Title;
    };
    return iRepo->find(p);
}

ItemManager::ItemManager(ItemRepository *iRepo) : iRepo(iRepo) {}

ItemRepository *ItemManager::getIRepo() const {
    return iRepo;
}
