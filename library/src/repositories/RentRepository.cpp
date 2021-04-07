//
// Created by student on 15.06.2020.
//

#include "repositories/RentRepository.h"

RentPtr RentRepository::getRent(unsigned int index) {
    if(index < get_rents_number()) return rents[index];
    else return nullptr;
}

unsigned int RentRepository::get_rents_number() {
    return rents.size();
}

void RentRepository::addRent(RentPtr newRent) {
    rents.push_back(newRent);
}

std::string RentRepository::reportRent() {
    std::ostringstream sout;
    for(RentPtr CollectionElem: rents){    //co tu sie zadzialo?????????
        sout << CollectionElem->getRentInfo();
        sout << std::endl;
    }
    return sout.str();
}

RentPtr RentRepository::find(RentPredicate &predicate) {
    for(int i=0; i<rents.size(); i++){
        if(predicate(rents[i])) return rents[i];
    }
    return nullptr;
}

std::vector<RentPtr> RentRepository::findAll(RentPredicate &predicate) {
    std::vector <RentPtr> rents2;
    for(int i=0; i<rents.size(); i++){
        if(predicate(rents[i])) rents2.push_back(rents[i]);
    }
    return rents2;
}

std::vector<RentPtr> RentRepository::getRents() {
    return rents;
}

void RentRepository::deleteRent(RentPtr rent) {
    for (int i = 0; i < rents.size(); i++) {
        if (rents[i] == rent) {
            rents.erase(rents.begin() + i);
        }
    }
}


