#include "doctest.h"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

#include <set>
using namespace pandemic;

#include <string>
using namespace std; //used to include functions such as memcpy..

set<City> cities = {
    City::Algiers, City::Atlanta, City::Baghdad, City::Bangkok, City::Beijing, City::Bogota, City::BuenosAires, City::Cairo, City::Chennai, City::Chicago, City::Delhi, City::Essen, City::HoChiMinhCity, City::HongKong, City::Istanbul, City::Jakarta, City::Johannesburg, City::Karachi, City::Khartoum, City::Kinshasa, City::Kolkata, City::Lagos, City::Lima, City::London, City::LosAngeles, City::Madrid, City::Manila, City::MexicoCity, City::Miami, City::Milan, City::Montreal, City::Moscow, City::Mumbai, City::NewYork, City::Osaka, City::Paris, City::Riyadh, City::SanFrancisco, City::Santiago, City::SaoPaulo, City::Seoul, City::Shanghai, City::StPetersburg, City::Sydney, City::Taipei, City::Tehran, City::Tokyo, City::Washington};
set<Color> colors = {Color::Black, Color::Yellow, Color::Blue, Color::Red};
//  iterates over each city and initalize sickness to 1
//  checks if sickness was set correctly
void set_sickness_level(Board &board)
{
    //set sickness level 1 to each city
    for (auto city : cities)
    {
        CHECK_NOTHROW(board[city] = 1;);
        board[city] = 1;
    }
    //   make sure sick was set correctly
    for (auto city : cities)
    {
        CHECK_EQ(board[city], 1);
    }
}
void take_five_cards(Player &player)
{
    player.take_card(City::NewYork).take_card(City::London).take_card(City::SanFrancisco).take_card(City::Tokyo).take_card(City::Sydney);
};
void take_five_random_cards(Player &player)
{
    while (player.myCards.size() < 5)
    {
        auto it = cities.begin();
        std::advance(it, (uint)rand() % cities.size());
        player.take_card(*it);
    };
};
void take_n_cards(Player &player, int num)
{
    set<City> my_cities = {City::Sydney, City::Taipei, City::Tokyo, City::Bangkok, City::Beijing};
    while (player.myCards.size() < num)
    {
        auto it = cities.begin();
        std::advance(it, (uint)rand() % cities.size());
        player.take_card(*it);
    };
};
void take_five_cards_red(Player &player)
{
    player.take_card(City::Sydney).take_card(City::Taipei).take_card(City::Tokyo).take_card(City::Bangkok).take_card(City::Beijing);
};
void take_five_cards_blue(Player &player)
{
    player.take_card(City::Atlanta).take_card(City::Chicago).take_card(City::Essen).take_card(City::London).take_card(City::Madrid);
};
void take_five_cards_yellow(Player &player)
{
    player.take_card(City::BuenosAires).take_card(City::Johannesburg).take_card(City::Kinshasa).take_card(City::Lagos).take_card(City::Lima);
};
void take_five_cards_black(Player &player)
{
    player.take_card(City::Algiers).take_card(City::Baghdad).take_card(City::Chennai).take_card(City::Delhi).take_card(City::Karachi);
};
void take_five_cards_each(Player &player)
{
    take_five_cards_black(player);
    take_five_cards_blue(player);
    take_five_cards_yellow(player);
    take_five_cards_red(player);
}
void find_all_cures(Player &player)
{
    player.discover_cure(Color::Black);
    player.discover_cure(Color::Blue);
    player.discover_cure(Color::Yellow);
    player.discover_cure(Color::Red);
}
void find_all_cures_nothrow(Player &player)
{
    CHECK_NOTHROW(player.discover_cure(Color::Black));
    CHECK_NOTHROW(player.discover_cure(Color::Blue));
    CHECK_NOTHROW(player.discover_cure(Color::Yellow));
    CHECK_NOTHROW(player.discover_cure(Color::Red));
}
void find_all_cures_throw(Player &player)
{
    CHECK_THROWS(player.discover_cure(Color::Black));
    CHECK_THROWS(player.discover_cure(Color::Blue));
    CHECK_THROWS(player.discover_cure(Color::Yellow));
    CHECK_THROWS(player.discover_cure(Color::Red));
}

set<City> _five_cities = {City::NewYork,
                          City::London,
                          City::SanFrancisco,
                          City::Tokyo,
                          City::Sydney};

TEST_CASE("BASIC TESTS")
{
    SUBCASE("Board")
    {
        CHECK_NOTHROW(Board b);
        Board board;
        CHECK(board.is_clean());
        set_sickness_level(board);
        board[City::Algiers] = 1;
        CHECK_FALSE(board.is_clean());
    }

    SUBCASE("Init Players")
    {
        Board board;
        CHECK_NOTHROW(Dispatcher dispatcher(board, City::NewYork););
        CHECK_NOTHROW(FieldDoctor fieldDoctor(board, City::NewYork););
        CHECK_NOTHROW(GeneSplicer geneSplicer(board, City::NewYork););
        CHECK_NOTHROW(Medic medic(board, City::NewYork););
        CHECK_NOTHROW(OperationsExpert operationsExpert(board, City::NewYork););
        CHECK_NOTHROW(Virologist virologist(board, City::NewYork););
        CHECK_NOTHROW(Researcher researcher(board, City::NewYork););
        CHECK_NOTHROW(Scientist scientist(board, City::NewYork, 5););
    }
    //////////////////////////////////////////////
    Board board;
    set<Player> players = {
        OperationsExpert(board, City::NewYork),
        Dispatcher(board, City::NewYork),
        FieldDoctor(board, City::NewYork),
        GeneSplicer(board, City::NewYork),
        Virologist(board, City::NewYork),
        Researcher(board, City::NewYork),
        Scientist(board, City::NewYork, 5),
        Medic(board, City::NewYork)};
    //////////////////////////////////////////////
    SUBCASE("Take Cards")
    {
        int counter = 0;
        //each player takes 5 cards
        for (auto player : players)
        {
            CHECK_EQ(player.myCards.size(), 0); //player currently dont have any cards
            for (auto city : cities)
            {
                CHECK_NOTHROW(player.take_card(city));
                counter++;
                if (counter == 5)
                {
                    CHECK_EQ(player.myCards.size(), counter); // make sure player took 5 cards
                    break;
                }
            }
        }
    }
    SUBCASE("Drive")
    {
        set<City> NY_neighbors = {City::Montreal, City::Washington, City::London, City::Madrid};
        //reach from newYork to every nearby city
        for (auto player : players)
        {
            CHECK_THROWS(player.drive(City::NewYork)); //can't drive from city to itself
            CHECK_THROWS(player.drive(City::Paris));   //Paris is not a neighbor
            for (auto city : NY_neighbors)
                CHECK_NOTHROW(player.drive(city));
        };
    }

    SUBCASE("Fly Direct")
    {
        //each player takes 5 cards from the deck
        for (auto player : players)
        {
            take_five_cards(player);
            /*NewYork
            London
            SanFrancisco
            Tokyo
            Sydney*/
            CHECK_THROWS(player.fly_direct(City::NewYork));  //can't fly from city to itself
            CHECK_THROWS(player.fly_direct(City::Shanghai)); //dont have the right card
            CHECK_NOTHROW(player.fly_direct(City::London));
            CHECK_NOTHROW(player.fly_direct(City::SanFrancisco));
            CHECK_NOTHROW(player.fly_direct(City::Tokyo));
            CHECK_NOTHROW(player.fly_direct(City::Sydney));
        };
    }
    SUBCASE("Fly Charter")
    {
        //each player takes 5 cards from the deck
        for (auto player : players)
        {
            take_five_cards(player);
            /*NewYork
            London
            SanFrancisco
            Tokyo
            Sydney*/
            CHECK_THROWS(player.fly_direct(City::NewYork));      //can't fly from city to itself
            CHECK_NOTHROW(player.fly_direct(City::London));      //dropped NewYork card
            CHECK_NOTHROW(player.fly_direct(City::NewYork));     // dropped London card
            CHECK_THROWS(player.fly_direct(City::SanFrancisco)); // don't have NewYork card anymore
        };
    }

    SUBCASE("Build")
    {
        players.erase(players.begin()); // remove operationsExpert
        for (auto player : players)
        {
            player.take_card(City::NewYork);
            CHECK_NOTHROW(player.build());
            CHECK_NOTHROW(player.build()); // do nothing, just return;
            player.drive(City::London);
            CHECK_THROWS(player.build()); // dont have the correct card
        }
    };

    SUBCASE("Fly Shuttle")
    {
        OperationsExpert temp{board, City::NewYork};
        temp.build(); //build research facility in newYork
        temp.take_card(City::Tokyo);
        temp.fly_direct(City::Tokyo); //going to Tokyo
        temp.build();                 // research facility in Tokyo

        for (auto player : players)
        {
            take_five_cards(player);
            /*NewYork
            London
            SanFrancisco
            Tokyo
            Sydney*/
            CHECK_THROWS(player.fly_shuttle(City::NewYork));      // cant fly from city to itself
            CHECK_NOTHROW(player.fly_shuttle(City::Tokyo));       //research facilities exist
            CHECK_THROWS(player.fly_shuttle(City::SanFrancisco)); // SanFrancisco doesn't have a research facility
        }
    };

    SUBCASE("Treat")
    {
        players.erase(--players.end()); //removing medic
        for (auto player : players)
        {
            CHECK_THROWS(player.treat(City::NewYork)); //Sickness level is set to 0
            board[City::NewYork] = 2;
            CHECK_NOTHROW(player.treat(City::NewYork));
            CHECK_EQ(board[City::NewYork], 1); //Cure is not found, decremenet by 1
        }
    }

    SUBCASE("Discover Cure")
    {
        set<Player> players_find_cure = {
            OperationsExpert(board, City::NewYork),
            Dispatcher(board, City::NewYork),
            FieldDoctor(board, City::NewYork),
            GeneSplicer(board, City::NewYork),
            Virologist(board, City::NewYork),
            // Researcher(board, City::NewYork),
            Scientist(board, City::NewYork, 5),
            Medic(board, City::NewYork)};

        for (auto player : players_find_cure)
        {
            player.take_card(City::NewYork);
            player.build(); // build research city

            take_five_cards_each(player);   // takes 5 cards from each color, total of 20
            find_all_cures_nothrow(player); //try to find cure for each color --> WILL WORK

            player.remove_cards();        //no cards left in hand
            find_all_cures_throw(player); //try to find cure for each color --> WONT WORK

            //not in a research city!
            player.take_card(City::MexicoCity).fly_direct(City::MexicoCity); //flying to Mexico
            take_five_cards_each(player);
            //ALL SHOULD THROW
            find_all_cures_throw(player);

            //FIND ALL THE CURES
            player.take_card(City::MexicoCity).build(); //flying to Mexico
            find_all_cures(player);

            //take another 5 cards each
            player.remove_cards();
            //even though player doesnt have cards, a cure already exists, throw nothing.
            CHECK_NOTHROW(find_all_cures(player));

            player.remove_cards();
        }
        board.remove_cures();
        board.remove_stations();
    }
}
TEST_CASE("Operations Expert")
{
    Board board;
    OperationsExpert oe{board, City::NewYork};
    //operation expert can build a research facility without throwing a card
    for (auto city : cities)
    {
        oe.take_card(city).fly_direct(city); //flying to each city
        CHECK_NOTHROW(oe.build());           //should not throw!
    }
}
TEST_CASE("Dispatcher")
{
    //if Dispatcher is in research city , he can fly_direct to any other research city
    Board board;
    Dispatcher dispatcher{board, City::NewYork};
    dispatcher.take_card(City::NewYork).build();

    for (auto city : cities)
    {
        OperationsExpert oe{board, city};
        oe.build(); //operation builder builds a research facility in each city
        CHECK_NOTHROW(dispatcher.fly_direct(city));
    }
    board.remove_stations();
    for (auto city : cities)
    {
        //doesn't have the correct card
        CHECK_THROWS(dispatcher.fly_direct(city));
        //there are no facility cities, should use regular fly_direct
        dispatcher.take_card(city);
        CHECK_EQ(dispatcher.myCards.size(), 1);
        CHECK_NOTHROW(dispatcher.fly_direct(city)); //should be able to use regular fly_direct
        CHECK_EQ(dispatcher.myCards.size(), 0);     //should have removed a card
    }
    dispatcher.remove_cards();
    board.remove_stations();
}
TEST_CASE("Scientist")
{
    Board board;
    CHECK_THROWS((Scientist{board, City::NewYork, -1})); //CANNOT BE INITIALIZED WITH NEGATIVE VALUES

    for (size_t i = 1; i <= 5; i++)
    {
        CHECK_NOTHROW((Scientist{board, City::NewYork, i})); //check it could be initialized
        Scientist scientist{board, City::NewYork, i};
        scientist.take_card(City::NewYork).build(); //build research facility
        take_n_cards(scientist, i);                 //take N RED cards
        CHECK_NOTHROW(scientist.discover_cure(Color::Red));
        board.remove_cures();
        CHECK_THROWS(scientist.discover_cure(Color::Red)); // no cards in hand
    }
}
TEST_CASE("Researcher")
{
    //can perform Discover-cure in ANY city (doesn't have to be a research city)
    Board board;
    Scientist researcher{board, City::NewYork};

    for (auto city : cities)
    {
        //fly to curr city with NO RESEARCH FACILITY
        researcher.take_card(city).fly_direct(city);
        take_five_cards_each(researcher);   //collecting 5 cards of each color
        find_all_cures_nothrow(researcher); //SHOULD NOT THROW AT ALL

        //BUILD RESEARCH FACILITY
        researcher.take_card(city).build(); //build research facility
        board.remove_cures();               //remove all cures
        take_five_cards_each(researcher);   //collecting 5 cards of each color
        find_all_cures_nothrow(researcher); //SHOULD NOT THROW AT ALL
    }
}
TEST_CASE("Medic")
{
    Board board;
    Medic medic{board, City::NewYork};

    //regular treat(), no cures found
    for (auto city : cities)
    {
        board[city] = 3;                                       //setting sickness
        CHECK_EQ(board[city], 3);                              //checking sickness level
        CHECK_NOTHROW(medic.take_card(city).fly_direct(city)); //flying to the city
        CHECK_EQ(board[city], 3);                              // no change should have been made, no cures yet
        CHECK_NOTHROW(medic.treat(city));
        CHECK_EQ(board[city], 0); // treat should zero sickness level
    }

    //automatic treat, all cures found
    medic.take_card(City::NewYork).build();
    take_five_cards_each(medic);
    find_all_cures_nothrow(medic);
    //flying direct
    for (auto city : cities)
    {
        board[city] = 3;
        CHECK_EQ(board[city], 3); //make sure sickness level was set correctly
        CHECK_NOTHROW(medic.take_card(city).fly_direct(city));
        CHECK_EQ(board[city], 0);        //cure is found, needs to pure city
        CHECK_THROWS(medic.treat(city)); // cure level is 0 , should throw
    }
    //flying charter
    for (auto city : cities)
    {
        board[city] = 3;
        CHECK_EQ(board[city], 3); //make sure sickness level was set correctly
        CHECK_NOTHROW(medic.take_card(medic.get_cur_city()).fly_direct(city));
        CHECK_EQ(board[city], 0);        //cure is found, needs to pure city
        CHECK_THROWS(medic.treat(city)); // cure level is 0 , should throw
    }
    //driving
    for (auto city : cities)
    {
        for (auto neighbor : board.cities.at(city).neighbors)
        {
            board[neighbor] = 3;
            CHECK_EQ(board[neighbor], 3);         //make sure sickness level was set correctly
            CHECK_NOTHROW(medic.drive(neighbor)); // should be able to drive
            CHECK_EQ(board[neighbor], 0);         //cure is found, needs to pure city
            CHECK_THROWS(medic.treat(city));      // cure level is 0 , should throw
            medic.drive(city); //go back to the original node
        }
    }
}
TEST_CASE("Virologist")
{
    //can treat any city as long as she has the city's card
    Board board;
    Virologist virologist{board, City::NewYork};
    for (auto city : cities)
    {
        virologist.take_card(city);            //make sure she has the card
        board[city] = 1;                       //set sickness to 1
        CHECK_NOTHROW(virologist.treat(city)); //shouldn't throw, she has the card
        CHECK_EQ(board[city], 0);              //should be able to treat
        if (city != City::NewYork)
        {
            board[city] = 1;                      //set sickness again
            CHECK_THROWS(virologist.treat(city)); // can't treat, already lost the card
        }
    }
}
TEST_CASE("Gene Splicer")
{
    Board board;
    GeneSplicer geneSplicer{board, City::NewYork};
    geneSplicer.take_card(City::NewYork).build(); // make sure a research facility exists

    for (auto color : colors)
    {
        take_five_random_cards(geneSplicer); //takes 5 different colored cards
        CHECK_NOTHROW(geneSplicer.discover_cure(color));
        board.remove_cures();
        take_five_cards_each(geneSplicer);
        find_all_cures_nothrow(geneSplicer);
        board.remove_cures();
    }
}
TEST_CASE("Field Doctor")
{
    Board board;
    FieldDoctor fieldDoctor{board, City::NewYork};

    //loop over each city
    for (auto city : cities)
    {
        fieldDoctor.take_card(city).fly_direct(city); //get to the center city

        //iterate over its neighbors and perform TREAT
        for (auto neighbor_ : board.cities.at(city).neighbors)
        {
            board[neighbor_] = 1;                        //set sickness level in each neighbor city
            CHECK_EQ(board[neighbor_], 1);               // make sure was correctly inserted
            CHECK_NOTHROW(fieldDoctor.treat(neighbor_)); //SHOULD NOT THROW
            CHECK_EQ(board[neighbor_], 0);
            CHECK_THROWS(fieldDoctor.treat(neighbor_)); //city already clean, should THROW
        }
    }
}
