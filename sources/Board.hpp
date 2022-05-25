#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>

#include <map>
#include <set>
#include "City.hpp"
#include "Color.hpp"
using namespace std;


namespace pandemic
{
    class town
    {
        public:
        Color color;
        vector<City> neighbors;
        bool research_facility;
        bool cure_found;
        int level;
    };

    class Board
    {
    public:
        Board()
        {
            cities.insert(pair<City,town>(City::NewYork,{Color::Blue,{City::Montreal,City::Washington,City::London,City::Madrid},false,false,0}));
            cities.insert(pair<City,town>(City::Algiers,{Color::Black,{City::Madrid,City::Paris,City::Istanbul,City::Cairo},false,false,0}));
            cities.insert(pair<City,town>(City::Atlanta,{Color::Blue,{City::Chicago,City::Miami,City::Washington},false,false,0}));
            cities.insert(pair<City,town>(City::Baghdad,{Color::Black,{City::Tehran,City::Istanbul,City::Cairo,City::Riyadh,City::Karachi},false,false,0}));
            cities.insert(pair<City,town>(City::Bangkok,{Color::Red,{City::Kolkata,City::Chennai,City::Jakarta,City::HoChiMinhCity,City::HongKong},false,false,0}));
            cities.insert(pair<City,town>(City::Beijing,{Color::Red ,{City::Shanghai,City::Seoul},false,false,0}));
            cities.insert(pair<City,town>(City::Bogota,{Color::Yellow,{City::MexicoCity,City::Lima,City::Miami,City::SaoPaulo,City::BuenosAires},false,false,0}));
            cities.insert(pair<City,town>(City::BuenosAires,{Color::Yellow,{City::Bogota,City::SaoPaulo},false,false,0}));
            cities.insert(pair<City,town>(City::Cairo,{Color::Black,{City::Algiers,City::Istanbul,City::Baghdad,City::Khartoum,City::Riyadh},false,false,0}));
            cities.insert(pair<City,town>(City::Chennai,{Color::Black,{City::Mumbai, City::Delhi ,City::Kolkata,City::Bangkok,City::Jakarta},false,false,0}));
            cities.insert(pair<City,town>(City::Chicago,{Color::Blue,{City::SanFrancisco,City::LosAngeles,City::MexicoCity,City::Atlanta,City::Montreal},false,false,0}));
            cities.insert(pair<City,town>(City::Delhi,{Color::Black,{City::Tehran,City::Karachi,City::Mumbai,City::Chennai,City::Kolkata},false,false,0}));
            cities.insert(pair<City,town>(City::Essen,{Color::Blue,{City::London,City::Paris,City::Milan,City::StPetersburg},false,false,0}));
            cities.insert(pair<City,town>(City::HoChiMinhCity,{Color::Red ,{City::Jakarta,City::Bangkok,City::HongKong,City::Manila},false,false,0}));
            cities.insert(pair<City,town>(City::HongKong,{Color::Red ,{City::Bangkok,City::Kolkata,City::HoChiMinhCity,City::Shanghai,City::Manila,City::Taipei},false,false,0})); 
            cities.insert(pair<City,town>(City::Istanbul,{Color::Black,{City::Milan,City::Algiers,City::StPetersburg,City::Cairo,City::Baghdad,City::Moscow},false,false,0}));
            cities.insert(pair<City,town>(City::Jakarta,{Color::Red ,{City::Chennai,City::Bangkok,City::HoChiMinhCity,City::Sydney},false,false,0}));
            cities.insert(pair<City,town>(City::Johannesburg,{Color::Yellow,{City::Kinshasa,City::Khartoum},false,false,0}));
            cities.insert(pair<City,town>(City::Karachi,{Color::Black,{City::Tehran,City::Baghdad,City::Riyadh,City::Mumbai,City::Delhi},false,false,0}));
            cities.insert(pair<City,town>(City::Khartoum,{Color::Yellow,{City::Cairo,City::Lagos,City::Kinshasa,City::Johannesburg},false,false,0}));
            cities.insert(pair<City,town>(City::Kinshasa,{Color::Yellow,{City::Lagos,City::Khartoum,City::Johannesburg},false,false,0}));
            cities.insert(pair<City,town>(City::Kolkata,{Color::Black,{City::Delhi,City::Chennai,City::Bangkok,City::HongKong},false,false,0}));
            cities.insert(pair<City,town>(City::Lagos,{Color::Yellow,{City::SaoPaulo,City::Khartoum,City::Kinshasa},false,false,0}));
            cities.insert(pair<City,town>(City::Lima,{Color::Yellow,{City::MexicoCity,City::Bogota,City::Santiago},false,false,0}));
            cities.insert(pair<City,town>(City::London,{Color::Blue,{City::NewYork,City::Madrid,City::Essen,City::Paris},false,false,0}));
            cities.insert(pair<City,town>(City::LosAngeles,{Color::Yellow,{City::SanFrancisco,City::Chicago,City::MexicoCity,City::Sydney},false,false,0}));
            cities.insert(pair<City,town>(City::Madrid,{Color::Blue,{City::London,City::NewYork,City::Paris,City::SaoPaulo,City::Algiers},false,false,0}));
            cities.insert(pair<City,town>(City::Manila,{Color::Red ,{City::Taipei,City::SanFrancisco,City::HoChiMinhCity,City::Sydney,City::HongKong},false,false,0}));
            cities.insert(pair<City,town>(City::MexicoCity,{Color::Yellow,{City::LosAngeles,City::Chicago,City::Miami,City::Lima,City::Bogota},false,false,0}));
            cities.insert(pair<City,town>(City::Miami,{Color::Yellow,{City::Atlanta,City::MexicoCity,City::Washington,City::Bogota},false,false,0}));
            cities.insert(pair<City,town>(City::Milan,{Color::Blue,{City::Essen,City::Paris,City::Istanbul},false,false,0}));
            cities.insert(pair<City,town>(City::Montreal,{Color::Blue,{City::Chicago,City::Washington,City::NewYork},false,false,0}));
            cities.insert(pair<City,town>(City::Moscow,{Color::Black,{City::StPetersburg,City::Istanbul,City::Tehran},false,false,0}));
            cities.insert(pair<City,town>(City::Mumbai,{Color::Black,{City::Karachi,City::Delhi,City::Chennai},false,false,0}));
            cities.insert(pair<City,town>(City::Osaka,{Color::Red ,{City::Taipei,City::Tokyo},false,false,0}));
            cities.insert(pair<City,town>(City::Paris,{Color::Blue,{City::Algiers,City::Essen,City::Madrid,City::Milan,City::London},false,false,0}));
            cities.insert(pair<City,town>(City::Riyadh,{Color::Black,{City::Baghdad,City::Cairo,City::Karachi},false,false,0}));
            cities.insert(pair<City,town>(City::SanFrancisco,{Color::Blue,{City:: LosAngeles,City::Chicago,City::Tokyo,City::Manila},false,false,0}));
            cities.insert(pair<City,town>(City::Santiago,{Color::Yellow,{City::Lima},false,false,0}));
            cities.insert(pair<City,town>(City::SaoPaulo,{Color::Yellow,{City::Bogota,City::BuenosAires,City::Lagos,City::Madrid},false,false,0}));
            cities.insert(pair<City,town>(City::Seoul,{Color::Red ,{City::Beijing,City::Shanghai,City::Tokyo},false,false,0}));
            cities.insert(pair<City,town>(City::Shanghai,{Color::Red ,{City::Beijing,City::HongKong,City::Taipei,City::Seoul,City::Tokyo},false,false,0}));
            cities.insert(pair<City,town>(City::StPetersburg,{Color::Blue,{City::Essen,City::Istanbul,City::Moscow},false,false,0}));
            cities.insert(pair<City,town>(City::Sydney,{Color::Red ,{City::Jakarta,City::Manila,City::LosAngeles},false,false,0}));
            cities.insert(pair<City,town>(City::Taipei,{Color::Red ,{City::Shanghai,City::HongKong,City::Osaka,City::Manila},false,false,0}));
            cities.insert(pair<City,town>(City::Tehran,{Color::Black,{City::Baghdad,City::Moscow,City::Karachi,City::Delhi},false,false,0}));
            cities.insert(pair<City,town>(City::Tokyo,{Color::Red ,{City::Seoul,City::Shanghai,City::Osaka,City::SanFrancisco},false,false,0}));
            cities.insert(pair<City,town>(City::Washington,{Color::Blue,{City::Atlanta,City::NewYork,City::Montreal,City::Miami},false,false,0}));
        
            cures_found.insert(pair<Color,bool>(Color::Red,false));
            cures_found.insert(pair<Color,bool>(Color::Yellow,false));
            cures_found.insert(pair<Color,bool>(Color::Black,false));
            cures_found.insert(pair<Color,bool>(Color::Blue,false));
            
        }
        map<City, town> cities;
        map<Color, bool> cures_found;
        vector<City> sick_cities;
        set<City> stations;
        vector<City> medics;
        int operator[](City i) const; // get operator
        int &operator[](City i);      // set operator
        bool is_clean();              // checks for disease
        void remove_cures();
        void remove_stations();
        friend ostream &operator<<(ostream &os, const Board &board);
    };
}
#endif
