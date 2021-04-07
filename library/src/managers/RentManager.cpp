//
// Created by student on 17.06.2020.
//

#include "managers/RentManager.h"

RentPtr RentManager::rentItem(unsigned int id, ClientPtr client, ItemPtr item, pt::ptime beginTime) {
    if(item->isRented()) return nullptr;
    RentPtr rent(new Rent(id, client, item, beginTime));
    rRepo->addRent(rent);
    return rent;
}

void RentManager::returnItem(ItemPtr item) {
for(int i=0; i<rRepo->get_rents_number(); i++){
    //if(rRepo->getRent(i)==rent) rRepo->getRents().erase(rRepo->getRents().begin()+i);
    if(rRepo->getRent(i)->getItem() == item) rRepo->deleteRent(rRepo->getRent(i));
    }
}

std::vector<RentPtr> RentManager::getAllClientRents(ClientPtr client) {
    RentPredicate p = [client](RentPtr r)->bool{
        return r->getClient()==client;
    };
    return rRepo->findAll(p);
}

RentManager::RentManager(RentRepository *rRepo) : rRepo(rRepo) {}

RentRepository *RentManager::getRRepo() const {
    return rRepo;
}
