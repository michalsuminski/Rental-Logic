#include <boost/test/unit_test.hpp>
#include <model/Movie.h>
#include <model/Game.h>
#include <repositories/ItemRepository.h>

BOOST_AUTO_TEST_SUITE(ItemRepositoryTestSuite)
    struct ItemRepositoryFixture{
        ItemPtr testMovie1;
        ItemPtr testGame1;

        ItemRepository ItemRepo;

        ItemRepositoryFixture(){
            testMovie1 = std::make_shared<Movie>("StarWars", 100, "Lucas", false);
            testGame1 = std::make_shared<Game>("HP", 100, "Yates", false);
        }
    };

    BOOST_FIXTURE_TEST_CASE(addNewRent, ItemRepositoryFixture){
        ItemRepo.addItem(testGame1);
        BOOST_TEST(ItemRepo.getItem(0) == testGame1);
    }

    BOOST_FIXTURE_TEST_CASE(getNewRentPositive, ItemRepositoryFixture){
        ItemRepo.addItem(testMovie1);
        BOOST_TEST(ItemRepo.getItem(0) == testMovie1);
    }

    BOOST_FIXTURE_TEST_CASE(getNewRentNegative, ItemRepositoryFixture){
        ItemRepo.addItem(testMovie1);
        BOOST_TEST(ItemRepo.getItem(1) == nullptr);
    }

    BOOST_FIXTURE_TEST_CASE(sizeOfRepo, ItemRepositoryFixture){
        ItemRepo.addItem(testMovie1);
        ItemRepo.addItem(testGame1);
        BOOST_TEST(ItemRepo.get_items_number() == 2);
    }

BOOST_AUTO_TEST_SUITE_END()