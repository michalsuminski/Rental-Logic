#ifndef CARRENTALPROJECT_TYPEDEFS_H
#define CARRENTALPROJECT_TYPEDEFS_H

#include <memory>
#include <functional>

class Address;
class Client;
class Item;
class Rent;

typedef std::shared_ptr <Client> ClientPtr;
typedef std::shared_ptr <Rent> RentPtr;
typedef std::shared_ptr <Item> ItemPtr;
typedef std::shared_ptr <Address> AddressPtr;

typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(RentPtr)> RentPredicate;  // obojetnie jak zdefiniuje funkcje byle by sie zgadzaly typy przyjmuje RentPtr zwraca bool
typedef std::function<bool(ItemPtr)> ItemPredicate;


#endif //CARRENTALPROJECT_TYPEDEFS_H
