#include <boost/test/unit_test.hpp>
#include <repositories/ItemRepository.h>
#include <model/Address.h>
#include <repositories/ClientRepository.h>
#include <model/Client.h>

    BOOST_AUTO_TEST_SUITE(ClientRepositoryTestSuite)
    struct ClientRepositoryFixture{
        AddressPtr testAddress1;
        AddressPtr testAddress2;

        ClientPtr testClient1;
        ClientPtr testClient2;
        ClientRepository ClientRepo;

        ClientRepositoryFixture(){
            testAddress1 = std::make_shared<Address>("Łódź", "Chmielowa", "10");
            testAddress2 = std::make_shared<Address>("Lodz", "Mickiewicza", "14");

            testClient1 = std::make_shared<Client>("Ian", "Franz", "1234", testAddress1);
            testClient2 = std::make_shared<Client>("Michael", "Komputer", "4567", testAddress2);
        }
    };
    BOOST_FIXTURE_TEST_CASE(addNewRent, ClientRepositoryFixture){
        ClientRepo.addClient(testClient1);
        BOOST_TEST(ClientRepo.getClient(0) == testClient1);
    }

    BOOST_FIXTURE_TEST_CASE(getNewRentPositive, ClientRepositoryFixture){
        ClientRepo.addClient(testClient1);
        BOOST_TEST(ClientRepo.getClient(0) == testClient1);
    }
    BOOST_FIXTURE_TEST_CASE(getNewRentNegative, ClientRepositoryFixture){
        ClientRepo.addClient(testClient1);
        BOOST_TEST(ClientRepo.getClient(1) == nullptr);
    }

    BOOST_FIXTURE_TEST_CASE(sizeOfRepo, ClientRepositoryFixture){
        ClientRepo.addClient(testClient1);
        ClientRepo.addClient(testClient2);
        BOOST_TEST(ClientRepo.get_clients_number() == 2);
    }

BOOST_AUTO_TEST_SUITE_END()