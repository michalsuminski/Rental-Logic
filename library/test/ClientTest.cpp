#include <boost/test/unit_test.hpp>
#include <model/Client.h>
#include <model/Address.h>
#include <model/typedefs.h>
#include <memory>

using namespace std;

struct TestSuiteClientFixture {
    const std::string testFirstName = "Jon";
    const std::string testLastName = "Arbuckle";
    const std::string testPersonalID = "0123456789";
    AddressPtr testaddress1;
    AddressPtr testaddress2;

            TestSuiteClientFixture() {
                testaddress1 = make_shared<Address>("London", "Accacia Avenue", "22");
                testaddress2 = make_shared<Address>("London", "Rue Morgue", "13");
    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstructorTest) {

        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        BOOST_TEST(testFirstName == c.getFirstName());
        BOOST_TEST(testLastName == c.getLastName());
        BOOST_TEST(testPersonalID == c.getPersonalID());
        BOOST_TEST(testaddress1 == c.getAddress());
    }
    BOOST_AUTO_TEST_CASE(SetFirstNamePositiveTest){
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setFirstName("Janusz");
        BOOST_TEST_CHECK(c.getFirstName()=="Janusz");
    }
    BOOST_AUTO_TEST_CASE(SetLastNamePositiveTest){
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setLastName("Kozacki");
        BOOST_TEST_CHECK(c.getLastName()=="Kozacki");
    }
    BOOST_AUTO_TEST_CASE(SetAddressPositiveTest){
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setAddress(testaddress2);
        BOOST_TEST_CHECK(testaddress2 == c.getAddress());
    }
    BOOST_AUTO_TEST_CASE(SetFirstNameNegativeTest){
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setFirstName("");
        BOOST_TEST_CHECK(c.getFirstName()==testFirstName);
    }
    BOOST_AUTO_TEST_CASE(SetLastNameNegativeTest){
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setLastName("");
        BOOST_TEST_CHECK(c.getLastName()==testLastName);
    }
    BOOST_AUTO_TEST_CASE(SetAddressNegativeTest){
        Client c(testFirstName, testLastName, testPersonalID, testaddress1);
        c.setAddress(nullptr);
        BOOST_TEST_CHECK(testaddress1 == c.getAddress());
    }
BOOST_AUTO_TEST_SUITE_END()