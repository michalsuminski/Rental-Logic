#include <boost/test/unit_test.hpp>
#include <model/Game.h>
#include <model/Movie.h>
#include <model/Music.h>
#include <model/typedefs.h>
#include "repositories/RentRepository.h"

BOOST_AUTO_TEST_SUITE(RentRepositoryTestSuite)
    struct RentRepositoryFixture{
        AddressPtr testAddress1;
        AddressPtr testAddress2;

        ClientPtr testClient1;
        ClientPtr testClient2;

        ItemPtr testMovie1;
        ItemPtr testGame1;
        RentPtr testRent1;
        RentPtr testRent2;

        RentRepository rentRepo;

        RentRepositoryFixture(){
            testAddress1 = std::make_shared<Address>("Łódź", "Chmielowa", "10");
            testAddress1 = std::make_shared<Address>("Lodz", "Mickiewicza", "14");

            testClient1 = std::make_shared<Client>("Ian", "Franz", "1234", testAddress1);
            testClient2 = std::make_shared<Client>("Michael", "Komputer", "4567", testAddress2);

            testMovie1 = std::make_shared<Movie>("StarWars", 50, "Lucas", false);
            testGame1 = std::make_shared<Game>("HP", 30, "Yates", false);

            testRent1 = std::make_shared<Rent>(1, testClient2, testMovie1);
            testRent2 = std::make_shared<Rent>(1, testClient2, testGame1);
        }
    };

    BOOST_FIXTURE_TEST_CASE(addNewRent, RentRepositoryFixture){
        rentRepo.addRent(testRent1);
        BOOST_TEST(rentRepo.getRent(0).get() == testRent1.get());

        std::cout << std::endl << testRent1.use_count() << std::endl;
    }

    BOOST_FIXTURE_TEST_CASE(getNewRentPositive, RentRepositoryFixture){
        rentRepo.addRent(testRent1);
        BOOST_TEST(rentRepo.getRent(0) == testRent1);
    }

    BOOST_FIXTURE_TEST_CASE(getNewRentNegative, RentRepositoryFixture){
        rentRepo.addRent(testRent1);
        BOOST_TEST(rentRepo.getRent(1) == nullptr);
    }

    BOOST_FIXTURE_TEST_CASE(sizeOfRepo, RentRepositoryFixture){
        rentRepo.addRent(testRent1);
        rentRepo.addRent(testRent2);
        BOOST_TEST(rentRepo.get_rents_number() == 2);
    }
BOOST_AUTO_TEST_SUITE_END()