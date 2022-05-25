/**
 * Demo file for the exercise on numbers with units
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;

int main() {
   ifstream units_MyFile{"filename.txt"};
    NumberWithUnits::read_units(units_MyFile);

     NumberWithUnits temp_input(7, "r_ILS");

    istringstream iss("20 [r_sec]");
    iss >> temp_input;
    bool flag = (temp_input== NumberWithUnits(20, "r_sec"));
    

    istringstream iss1("6[ r_g ]");
    iss1 >> temp_input;
    flag = (temp_input== NumberWithUnits(6, "r_g"));

    istringstream iss2(" 900 [r_ton] ");
    iss2 >> temp_input;
    // CHECK_EQ(temp_input, NumberWithUnits(900, "r_ton"));

    NumberWithUnits a(7, "r_ILS");
    NumberWithUnits b(7, "r_ILS");
    NumberWithUnits c(7, "r_ILS");
    istringstream iss3{" -16 [r_m]   -7 [r_hour ]  8.8 [r_min ]"};
    iss3 >> a >> b >> c;
    // CHECK_EQ(a, NumberWithUnits(-16, "r_m"));
    // CHECK_EQ(b, NumberWithUnits(-7, "r_hour"));
    // CHECK_EQ(c, NumberWithUnits(8.8, "r_min"));

    cout<<boolalpha;
    cout<<flag<<endl;

  // NumberWithUnits a{2, "km"};   // 2 kilometers
  // cout << a << endl;           // Prints "2[km]".
  // cout << (-a) << endl;    // Prints "-2[km]"
  // cout << (3*a) << endl;    // Prints "6[km]"

  // NumberWithUnits b{300, "m"};  // 300 meters
  // cout << (a+b) << endl;   // Prints "2.3[km]". Note: units are determined by first number (a).
  // cout << (b-a) << endl;   // Prints "-1700[m]". Note: units are determined by first number (b).

  // cout << boolalpha; // print booleans as strings from now on:
  // cout << (a>b) << endl;  // Prints "true"
  // cout << (a<=b) << endl;  // Prints "false"
  // cout << (a==NumberWithUnits{2000, "m"}) << endl;  // Prints "true"

  // istringstream sample_input{"700 [ kg ]"};
  // sample_input >> a;
  // cout << a << endl;   // Prints "700[kg]"
  // cout << (a += NumberWithUnits{1, "ton"}) << endl;  // prints "1700[kg]"
  // cout << a << endl;   // Prints "1700[kg]". Note that a has changed.

  // try {
  //   cout << (a+b) << endl;  
  // } catch (const std::exception& ex) {
  //   cout << ex.what() << endl; // Prints "Units do not match - [m] cannot be converted to [kg]"
  // }
  // cout << "End of demo!" << endl;
  return 0;
}
