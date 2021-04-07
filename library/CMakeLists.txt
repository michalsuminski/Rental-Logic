cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/model/Client.h
        src/model/Client.cpp
        src/model/Address.cpp include/model/Address.h src/model/Game.cpp include/model/Game.h include/model/Movie.h
        src/model/Music.cpp include/model/Music.h src/model/Rent.cpp  src/model/Movie.cpp  include/model/Rent.h include/model/typedefs.h src/model/Item.cpp include/model/Item.h src/repositories/ClientRepository.cpp include/repositories/ClientRepository.h src/repositories/RentRepository.cpp include/repositories/RentRepository.h src/repositories/ItemRepository.cpp include/repositories/ItemRepository.h include/utils/Generators.h src/utils/Generators.cpp src/managers/ClientManager.cpp include/managers/ClientManager.h src/managers/ItemManager.cpp include/managers/ItemManager.h src/managers/RentManager.cpp include/managers/RentManager.h)

#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)
enable_testing()
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/master.cpp
        test/ClientTest.cpp test/AddressTest.cpp test/ItemTest.cpp test/RentTest.cpp test/ClientManagerTest.cpp test/ItemManagerTest.cpp test/RentManagerTest.cpp test/ClientRepositoryTest.cpp test/RentRepositoryTest.cpp test/ItemRepositoryTest.cpp)

add_executable (LibraryTest ${SOURCE_TEST_FILES}) #plik wykonywalny o nazwie LibraryTest

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTest
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

