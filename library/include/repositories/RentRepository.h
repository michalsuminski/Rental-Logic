//
// Created by student on 15.06.2020.
//

#ifndef CARRENTALPROJECT_RENTREPOSITORY_H
#define CARRENTALPROJECT_RENTREPOSITORY_H
#include "model/Rent.h"

class RentRepository {
private:
    std::vector <RentPtr> rents;
public:
    RentPtr getRent(unsigned int index);
    unsigned int get_rents_number();
    void addRent(RentPtr newRent);
    std::string reportRent();
    RentPtr find(RentPredicate &predicate);
    std::vector<RentPtr> findAll(RentPredicate &predicate);
    std::vector<RentPtr> getRents();
    void deleteRent(RentPtr rent);
};


#endif //CARRENTALPROJECT_RENTREPOSITORY_H
