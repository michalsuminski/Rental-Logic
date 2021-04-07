
#include <iostream>
#include "../../include/model/Client.h"
#include "../../include/model/Address.h"


using namespace std;

//konstruktor

Client::Client(const string &firstName, const string &lastName, const string &personalId, AddressPtr address) : firstName(firstName),
                                                                                            lastName(lastName),
                                                                                            personalID(personalId),
                                                                                            address(address){}
//destruktor (działa tylko dla obiektu powołanego statycznie)
Client::~Client() {
    //delete address;
}


//*getter* dla wszystkich danych
string Client::getClientInfo() const {
    return ""+getFirstName()+" "+getLastName()+" "+getPersonalID()+"\n"+address->getAddressInfo();
}

//gettery
const string &Client::getFirstName() const {
    return firstName;
}
const string &Client::getLastName() const {
    return lastName;
}
const string &Client::getPersonalID() const {
    return personalID;
}

const AddressPtr Client::getAddress() const {
    return address;
}
//koniec getterów

//settery
void Client::setFirstName(const string &newFirstName){
    if(!newFirstName.empty()) Client::firstName = newFirstName;
}
void Client::setLastName(const string &newLastName){
    if(!newLastName.empty()) Client::lastName = newLastName;
}
void Client::setAddress(AddressPtr newAddress) {
    if(newAddress!= nullptr) Client::address=newAddress;
}
//koniec setterów

void Client::addNewRent(RentPtr newRent) {
    if(newRent != nullptr) currentRents.push_back(newRent);
}

const std::vector<RentPtr> &Client::getAllRents() const {
    return currentRents;
}
