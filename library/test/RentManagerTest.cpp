#include <boost/test/unit_test.hpp>
#include <model/typedefs.h>
#include <model/Client.h>
#include <model/Address.h>
#include <model/Music.h>
#include <model/Movie.h>
#include <repositories/RentRepository.h>
#include <managers/RentManager.h>
#include <model/Game.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(RentManagerTestSuite)

    struct RentManagerFixture {
        AddressPtr testAddress1;

        ClientPtr testClient1;
        ClientPtr testClient2;

        ItemPtr testItem1;
        ItemPtr testItem2;
        ItemPtr testItem3;

        RentPtr testRent1;

        RentManagerFixture() {
            testAddress1 = make_shared<Address>("London", "Accacia Avenue", "22");
            testClient1 = make_shared<Client>("Jon", "Arbuckle", "666", testAddress1);
            testClient2 = make_shared<Client>("Anna", "Arbuckle", "777", testAddress1);
            testItem1 = make_shared<Movie>("Film", 50, "Director", false);
            testItem2 = make_shared<Music>("Music", 30, "Artist", true);
            testItem3 = make_shared<Game>("Game", 100, "Studio", false);
            testRent1 = make_shared<Rent>(1, testClient1, testItem1);
        }
    };

    BOOST_FIXTURE_TEST_CASE(GeneralTest, RentManagerFixture){
        RentRepository* repo = new RentRepository;
        repo->addRent(testRent1);
        RentManager rent(repo);
        rent.rentItem(2,testClient2, testItem2, pt::second_clock::local_time());
        rent.rentItem(5,testClient2, testItem3, pt::second_clock::local_time());
        //sprawdzenie czy metoda rent dodaje wypozyczenie do repozytorium
        BOOST_TEST(rent.getRRepo()->getRents().size() == 3);
        //sprawdzenie czy metoda rent nie dodaje jesli item jest wypozyczony
        BOOST_TEST(rent.rentItem(5,testClient1, testItem3, pt::second_clock::local_time()) == nullptr);
        BOOST_TEST(rent.getRRepo()->getRents().size() == 3);
        //sprawdzenie metody return
        rent.returnItem(testItem1);
        BOOST_TEST(rent.getRRepo()->getRents().size() == 2);
        //sprawdzenie metody getAllClientRents
        BOOST_TEST(rent.getAllClientRents(testClient2).size() == 2);
        delete repo;
    }
BOOST_AUTO_TEST_SUITE_END()