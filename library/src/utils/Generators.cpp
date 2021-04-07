//
// Created by student on 15.06.2020.
//

#include "utils/Generators.h"

void clientRepositoryGenerator (ClientRepository* cRepoPtr, int amount){
    for (int i=0; i<amount; i++){
        AddressPtr address (new Address("city" ""+std::to_string(i)+"", "street" ""+std::to_string(i)+"", "number" ""+std::to_string(i)+""));
        ClientPtr client (new Client("firstname" ""+std::to_string(i)+"", "lastname" ""+std::to_string(i)+"", "personalID" ""+std::to_string(i)+"", address));
        cRepoPtr->addClient(client);
    }
}

void itemeRepositoryGenerator (ItemRepository* iRepoPtr, int amount){
    for (int i=0; i<amount; i++){
        ItemPtr item (new Item("title" ""+std::to_string(i)+"", i));
        iRepoPtr->addItem(item);
    }
}