#ifndef CARRENTALPROJECT_ADDRESS_H
#define CARRENTALPROJECT_ADDRESS_H

#include <iostream>

class Address {
private:
    std::string city;
    std::string street;
    std::string number;
public:
    Address(const std::string &city, const std::string &street, const std::string &number);

    virtual ~Address();

    std::string getAddressInfo() const;

//gettery
    const std::string &getCity() const;
    const std::string &getStreet() const;
    const std::string &getNumber() const;
};


#endif //CARRENTALPROJECT_ADDRESS_H
