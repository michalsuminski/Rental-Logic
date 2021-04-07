#include <boost/test/unit_test.hpp>
#include <model/Item.h>

struct ItemInstanceData{

    int basePriceInitial = 1000;
    std::string title = "Film";
};
BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress, ItemInstanceData)

    BOOST_AUTO_TEST_CASE(ItemConstructorTest){
        Item item(title,basePriceInitial);
        BOOST_TEST(item.getTitle()=="Film");
        BOOST_TEST(item.getBasePrice()==1000);
    }
    BOOST_AUTO_TEST_CASE(SetTitlePositiveTest){
        Item item("Music",100);
        item.setTitle("Game");
        BOOST_TEST(item.getTitle()=="Game");
    }
    BOOST_AUTO_TEST_CASE(SetBasePricePositiveTest){
        Item item("Music",100);
        item.setBasePrice(200);
        BOOST_TEST(item.getBasePrice()==200);
    }
    BOOST_AUTO_TEST_CASE(SetTitleNegativeTest){
        Item item("Music",100);
        item.setTitle("");
        BOOST_TEST(item.getTitle() == "Music");
    }
BOOST_AUTO_TEST_SUITE_END()