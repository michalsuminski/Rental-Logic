//
// Created by student on 17.06.2020.
//

#ifndef CARRENTALPROJECT_RENTMANAGER_H
#define CARRENTALPROJECT_RENTMANAGER_H


#include <repositories/RentRepository.h>

class RentManager {
private:
    RentRepository* rRepo;
public:
    RentManager(RentRepository *rRepo);

    RentPtr rentItem(unsigned int id, ClientPtr client, ItemPtr item, pt::ptime beginTime);

    void returnItem(ItemPtr item);

    std::vector<RentPtr> getAllClientRents(ClientPtr client);

    RentRepository *getRRepo() const;
};


#endif //CARRENTALPROJECT_RENTMANAGER_H
