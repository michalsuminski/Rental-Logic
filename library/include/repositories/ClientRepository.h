//
// Created by student on 15.06.2020.
//

#ifndef CARRENTALPROJECT_CLIENTREPOSITORY_H
#define CARRENTALPROJECT_CLIENTREPOSITORY_H
#include "model/Client.h"

class ClientRepository {
private:
    std::vector <ClientPtr> clients;
public:
    ClientPtr getClient(unsigned int index);
    unsigned int get_clients_number();
    void addClient(ClientPtr newClient);
    std::string reportClient();
    ClientPtr find(ClientPredicate &predicate);
    std::vector<ClientPtr> findAll(ClientPredicate &predicate);
    std::vector<ClientPtr> getClients();
    void deleteClient(ClientPtr client);
};


#endif //CARRENTALPROJECT_CLIENTREPOSITORY_H
