//
// Created by student on 15.06.2020.
//

#ifndef CARRENTALPROJECT_GENERATORS_H
#define CARRENTALPROJECT_GENERATORS_H

#include <repositories/ClientRepository.h>
#include <repositories/ItemRepository.h>
#include <repositories/RentRepository.h>
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

void clientRepositoryGenerator (ClientRepository* cRepoPtr, int amount);
void itemRepositoryGenerator (ItemRepository* vRepoPtr, int amount);
void rentRepositoryGenerator (RentRepository* rRepoPtr, ClientRepository* cRepoPtr, ItemRepository* iRepoPtr, int amount);
#endif //CARRENTALPROJECT_GENERATORS_H
