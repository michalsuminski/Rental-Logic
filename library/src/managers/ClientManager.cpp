//
// Created by student on 17.06.2020.
//

#include "managers/ClientManager.h"

ClientPtr ClientManager::registerClient(std::string newFname, std::string newLname, std::string nID, std::string newCity,
                                        std::string newStreet, std::string newNumber) {
    AddressPtr address (new Address(newCity, newStreet, newNumber));
    ClientPtr client (new Client(newFname, newLname, nID, address));
    for(int i=0; i<cRepo->get_clients_number(); i++){
        if(cRepo->getClient(i)->getClientInfo() == client->getClientInfo()) return cRepo->getClient(i);
    }
    cRepo->addClient(client);
    return client;
}

void ClientManager::unregisterClient(ClientPtr client) {
    for(int i=0; i<cRepo->get_clients_number(); i++){
        //if(cRepo->getClient(i)->getClientInfo() == client->getClientInfo()) cRepo->getClients().erase(cRepo->getClients().begin()+i);
        if(cRepo->getClient(i)->getClientInfo() == client->getClientInfo()) cRepo->deleteClient(client);
    }
}

ClientPtr ClientManager::getClient(std::string personalID) {
    ClientPredicate p = [personalID](ClientPtr c)->bool{
        return c->getPersonalID() == personalID;
    };
    return cRepo->find(p);
}

ClientRepository *ClientManager::getAllClients() const {
    return cRepo;
}

ClientManager::ClientManager(ClientRepository *cRepo) : cRepo(cRepo) {}



