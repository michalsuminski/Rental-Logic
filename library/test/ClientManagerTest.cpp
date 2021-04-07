#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include <model/Address.h>
#include <model/typedefs.h>
#include <memory>
#include <managers/ClientManager.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(ClientManagerTestSuite)

struct ClientManagerFixture {
    AddressPtr testAddress1;

    ClientPtr testClient1;
    ClientPtr testClient2;

    ClientManagerFixture() {
        testAddress1 = make_shared<Address>("London", "Accacia Avenue", "22");
        testClient1 = make_shared<Client>("Jon", "Arbuckle", "666", testAddress1);
        testClient2 = make_shared<Client>("Anna", "Arbuckle", "777", testAddress1);
    }
};

BOOST_FIXTURE_TEST_CASE(RegisterTest, ClientManagerFixture){
    ClientRepository* repo = new ClientRepository;
    repo->addClient(testClient2);
    ClientManager client(repo);
    //sprawdzenie czy metoda register dodaje obiekty do repozytoriow
    client.registerClient("Jon", "Arbuckle", "666", "London", "Accacia Avenue", "22");
    BOOST_TEST(client.getAllClients()->getClients().size() == 2);
    BOOST_TEST(client.registerClient("Jon", "Arbuckle", "666", "London", "Accacia Avenue", "22")->getClientInfo() == testClient1->getClientInfo());
    //sprawdzenie czy jesli obiekt juz istnieje czy go zwraca
    BOOST_TEST(client.registerClient("Jon", "Arbuckle", "666", "London", "Accacia Avenue", "22") == repo->getClient(1));
    //sprawdzenie metody getClient
    BOOST_TEST(client.getClient("777") == testClient2);
    //sprawdzenie metody unregister
    client.unregisterClient(testClient2);
    BOOST_TEST(client.getAllClients()->getClients().size() == 1);
    delete repo;
}
BOOST_AUTO_TEST_SUITE_END()