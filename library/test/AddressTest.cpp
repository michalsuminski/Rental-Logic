#include <boost/test/unit_test.hpp>
#include <model/Address.h>

//BOOST_AUTO_TEST_SUITE(TestSuiteAddress)
struct AddressInstanceData{

    std::string cityInitial = "Warszawa";
    std::string streetInitial = "Kredytowa";
    std::string numberInitial = "12";
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, AddressInstanceData)

    BOOST_AUTO_TEST_CASE(AddressConstructorTest){
        Address adres(cityInitial, streetInitial, numberInitial);
        BOOST_TEST_CHECK(adres.getAddressInfo().compare("Warszawa Kredytowa 12"));
        BOOST_TEST(adres.getCity()=="Warszawa");
        BOOST_TEST(adres.getStreet()=="Kredytowa");
        BOOST_TEST_CHECK(adres.getNumber()=="12");
    }

BOOST_AUTO_TEST_SUITE_END()

