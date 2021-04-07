//
// Created by student on 15.06.2020.
//

#include "repositories/ClientRepository.h"

ClientPtr ClientRepository::getClient(unsigned int index) {
    if (index < clients.size()) return clients[index];
    else return nullptr;
}

unsigned int ClientRepository::get_clients_number() {
    return clients.size();
}

void ClientRepository::addClient(ClientPtr newClient) {
    clients.push_back(newClient);
}

std::string ClientRepository::reportClient() {
    std::ostringstream sout;
    for(ClientPtr CollectionElem: clients){    //co tu sie zadzialo?????????
        sout << CollectionElem->getClientInfo();
        sout << std::endl;
    }
    return sout.str();
}

ClientPtr ClientRepository::find(ClientPredicate &predicate) {
    for(int i=0; i<clients.size(); i++){
        if(predicate(clients[i])) return clients[i];
    }
    return nullptr;
}

std::vector<ClientPtr> ClientRepository::findAll(ClientPredicate &predicate) {
    std::vector <ClientPtr> clients2;
    for(int i=0; i<clients.size(); i++){
        if(predicate(clients[i])) clients2.push_back(clients[i]);
    }
    return clients2;
}

std::vector<ClientPtr> ClientRepository::getClients() {
    return clients;
}

void ClientRepository::deleteClient(ClientPtr client) {
    for(int i=0;i<clients.size();i++)
    {
        if(clients[i] == client)
        {
            clients.erase(clients.begin()+i);
        }
    }
}
//findAll dodaje obiekt do wektora i zamiast jednego obiektu zwracam caly wektor obiektow