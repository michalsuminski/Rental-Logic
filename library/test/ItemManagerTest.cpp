#include <boost/test/unit_test.hpp>
#include <model/typedefs.h>
#include <model/Movie.h>
#include <model/Game.h>
#include <model/Music.h>
#include <repositories/ItemRepository.h>
#include <managers/ItemManager.h>

using namespace std;

BOOST_AUTO_TEST_SUITE(ItemManagerTestSuite)

struct ItemManagerFixture {
    ItemPtr testItem1;
    ItemPtr testItem2;
    ItemPtr testItem3;

    ItemManagerFixture() {
        testItem1 = make_shared<Movie>("Film", 50, "Director", false);
        testItem2 = make_shared<Music>("Music", 30, "Artist", true);
        testItem3 = make_shared<Game>("Game", 100, "Studio", false);
    }
};

BOOST_FIXTURE_TEST_CASE(RegisterTest, ItemManagerFixture){
    ItemRepository* repo = new ItemRepository;
    repo->addItem(testItem3);
    ItemManager item(repo);
    item.registerMovie("Film", 50, "Director", false);
    item.registerMusic("Music", 30, "Artist", true);
    //sprawdzenie czy metoda register dodaje
    BOOST_TEST(item.getIRepo()->getItems().size() == 3);
    //sprawdzenie czy jesyli taki item juz istnieje to zwroci ten item i nie doda go do repozytorium
    BOOST_TEST(item.registerMusic("Music", 30, "Artist", true) == repo->getItem(2));
    //sprawdzenie metody getItem
    BOOST_TEST(item.getItem("Game") == testItem3);
    //sprawdzenie metody unregister
    item.unregisterItem(testItem3);
    BOOST_TEST(item.getIRepo()->getItems().size() == 2);
    delete repo;
}
BOOST_AUTO_TEST_SUITE_END()