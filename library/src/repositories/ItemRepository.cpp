//
// Created by student on 15.06.2020.
//

#include <sstream>
#include "repositories/ItemRepository.h"

ItemPtr ItemRepository::getItem(unsigned int index) {
    if (index < items.size()) return items[index];
    else return nullptr;
}

unsigned int ItemRepository::get_items_number() {
    return items.size();
}

void ItemRepository::addItem(ItemPtr newItem) {
    items.push_back(newItem);
}

std::string ItemRepository::reportItem() {
    std::ostringstream sout;
    for(ItemPtr CollectionElem: items){    //co tu sie zadzialo?????????
        sout << CollectionElem->getItemInfo();
        sout << std::endl;
    }
    return sout.str();
}

ItemPtr ItemRepository::find(ItemPredicate &predicate) {
    for(int i=0; i < items.size(); i++){
        if(predicate(items[i])) return items[i];
    }
    return nullptr;
}

std::vector<ItemPtr> ItemRepository::findAll(ItemPredicate &predicate) {
    std::vector <ItemPtr> items2;
    for(int i=0; i < items.size(); i++){
        if(predicate(items[i])) items2.push_back(items[i]);
    }
    return items2;
}

std::vector<ItemPtr> ItemRepository::getItems() {
    return items;
}

void ItemRepository::deleteItem(ItemPtr item) {
    for(int i=0;i<items.size();i++)
    {
        if(items[i] == item)
        {
            items.erase(items.begin()+i);
        }
    }
}
