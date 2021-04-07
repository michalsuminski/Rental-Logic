#ifndef CARRENTALPROJECT_CLIENT_H
#define CARRENTALPROJECT_CLIENT_H

#include <string>
#include <iostream>
#include "Address.h"
#include "Rent.h"
#include <vector>
#include "typedefs.h"

class Rent;

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr address;
    std::vector<RentPtr> currentRents;

public:
//konstruktory
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId, AddressPtr address);

//destruktor
    virtual ~Client();

    std::string getClientInfo() const;
//gettery
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalID() const;
    const AddressPtr getAddress() const;
//settery
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setAddress(AddressPtr address);
//
    void addNewRent(RentPtr newRent);
    const std::vector <RentPtr> &getAllRents() const;
};


#endif //CARRENTALPROJECT_CLIENT_H
