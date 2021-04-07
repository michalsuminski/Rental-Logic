//
// Created by student on 15.06.2020.
//

#ifndef CARRENTALPROJECT_ITEMREPOSITORY_H
#define CARRENTALPROJECT_ITEMREPOSITORY_H

#include <vector>
#include "model/Item.h"

class ItemRepository {
private:
    std::vector <ItemPtr> items;
public:
    ItemPtr getItem(unsigned int index);
    unsigned int get_items_number();
    void addItem(ItemPtr newItem);
    std::string reportItem();
    ItemPtr find(ItemPredicate &predicate);
    std::vector<ItemPtr> findAll(ItemPredicate &predicate);
    std::vector<ItemPtr> getItems();
    void deleteItem(ItemPtr item);

};


#endif //CARRENTALPROJECT_ITEMREPOSITORY_H
