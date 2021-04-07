#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include <model/Address.h>
#include <model/typedefs.h>
#include <memory>
#include <model/Movie.h>


using namespace std;

BOOST_AUTO_TEST_SUITE(RentTestSuite)

struct RentFixture {
    AddressPtr testAddress1;

    ClientPtr testClient1;

    ItemPtr testItem1;
    ItemPtr testItem2;
    ItemPtr testItem3;

    RentPtr testRent1;
    RentPtr testRent2;

    RentFixture() {
        testAddress1 = std::make_shared<Address>("Radom", "Chrobrego", "99");
        testClient1 = std::make_shared<Client>("Daniel", "Malicki", "444", testAddress1);

        testItem1 = std::make_shared<Movie>("StarWars", 50, "Lucas", false);
        testItem2 = std::make_shared<Movie>("Got", 100, "Martin", false);
        testItem3 = std::make_shared<Movie>("HP", 30, "Yates", false);

        testRent1 = std::make_shared<Rent>(1, testClient1, testItem1);
        testRent2 = std::make_shared<Rent>(1, testClient1, testItem2);
    }
};

BOOST_FIXTURE_TEST_CASE(RentConstructorTest, RentFixture){
        AddressPtr testAddress1 (new Address("Chicago", "GreenPoint","110"));
        ClientPtr testClient1 (new Client("Jon", "Arbucle", "123", testAddress1));
        ItemPtr testItem (new Movie("StarWars",50,"Lucas",false));
        RentPtr testRent(new Rent(10, testClient1, testItem));
        pt::ptime currentTime = pt::second_clock::local_time();
        //sprawdzenie czy begin time jest dobrze ustawiony
        BOOST_TEST_REQUIRE(testRent->getBeginTime() != pt::not_a_date_time);
        BOOST_TEST(pt::time_period(testRent->getBeginTime(), currentTime).length() < pt::seconds(10));
}

BOOST_FIXTURE_TEST_CASE(RentGetRentDaysNotEndedRent, RentFixture) {
        BOOST_TEST(testRent1->getRentDays() == 0);
}

BOOST_FIXTURE_TEST_CASE(RentGetRentDaysRentEndedAfterAboutMinute, RentFixture) {
        //koniec wypozyczenia po 59sek
        AddressPtr testAddress1 (new Address("Chicago", "GreenPoint","110"));
        ClientPtr testClient1 (new Client("Jon", "Arbucle", "123", testAddress1));
        ItemPtr testItem (new Movie("StarWars",50,"Lucas",false));
        RentPtr testRent(new Rent(10, testClient1, testItem));
        testRent->endRent(pt::second_clock::local_time() + pt::seconds(59));
        BOOST_TEST(testRent->getRentDays() == 0);
}

BOOST_FIXTURE_TEST_CASE(RentGetRentDaysRentEndedAfterAboutDay, RentFixture) {
        //koniec wypozyczenia po 23h 59 min 59sek
        testRent1->endRent(pt::second_clock::local_time() + pt::hours(23) + pt::minutes(59) + pt::seconds(59));
        BOOST_TEST(testRent1->getRentDays() == 1);
        ///koniec wypozyczenia po 24h
        testRent2->endRent(pt::second_clock::local_time() + pt::hours(24));
        BOOST_TEST(testRent2->getRentDays() == 2);
}

    BOOST_FIXTURE_TEST_CASE(RentEndRentGetRentCost, RentFixture) {
        testRent1->endRent(pt::second_clock::local_time());
        BOOST_TEST(testRent1->getRentCost() == 0);
        testRent2->endRent(testRent2->getBeginTime() + pt::hours(2));
        BOOST_TEST(testRent2->getRentCost() > 1);
        testRent1->endRent(pt::second_clock::local_time());
        AddressPtr testAddress1 (new Address("Chicago", "GreenPoint","110"));
        ClientPtr testClient1 (new Client("Jon", "Arbucle", "123", testAddress1));
        ItemPtr testItem (new Movie("StarWars",50,"Lucas",false));
        RentPtr testRent(new Rent(10, testClient1, testItem));
        testRent->endRent(testRent->getBeginTime() + pt::hours(23));
        BOOST_TEST(testRent->getRentCost() == 50);
    }

BOOST_AUTO_TEST_SUITE_END()
