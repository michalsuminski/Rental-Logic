//
// Created by student on 17.06.2020.
//

#ifndef CARRENTALPROJECT_CLIENTMANAGER_H
#define CARRENTALPROJECT_CLIENTMANAGER_H

#include <string>
#include <repositories/ClientRepository.h>
#include "model/typedefs.h"

class ClientManager {
private:
    ClientRepository* cRepo;
public:
    ClientManager(ClientRepository *cRepo);

    ClientPtr registerClient(std::string newFname, std::string newLname, std::string nID, std::string newCity, std::string newStreet, std::string newNumber);

    void unregisterClient(ClientPtr client);

    ClientPtr getClient(std::string personalID);

    ClientRepository *getAllClients() const;
};


#endif //CARRENTALPROJECT_CLIENTMANAGER_H
