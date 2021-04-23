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

int main()
{

  /* load initial units
  1 km = 1000 m
1 m = 100 cm
1 inch = 3 cm
1 kg = 1000 g
1 ton = 1000 kg
1 USD = 3.33 ILS
*/
  ifstream units_file{"units.txt"};
  NumberWithUnits::read_units(units_file);

  //km --> m --> cm --> inch
  NumberWithUnits a{1, "km"};  // 2 kilometers
  NumberWithUnits b{300, "m"}; // 300 meters
  NumberWithUnits c{1, "inch"};
  NumberWithUnits d{300000, "cm"};
  NumberWithUnits e{100000, "inch"};

  cout << a << endl;                                     // Prints "2[km]".
  cout << (-a) << endl;                                  // Prints "-1[km]"
  cout << (3 * a) << endl;                               // Prints "3[km]"
  cout << (c + a) << endl;                               // prints 33334.3[inch]
  cout << (a + c) << endl;                               // prints 1.00003[km]
  cout << (a + (b + NumberWithUnits{200, "m"})) << endl; // prints 1.5KM
  a += (a + a);
  cout << (a) << endl;     // prints 3KM
  cout << (a - a) << endl; // prints 0KM

  cout << boolalpha;                                 // print booleans as strings from now on:
  cout << (d > a) << endl;                           // Prints "true" d is 3 KM
  cout << (d < a) << endl;                           // prints "false"
  cout << (a <= b) << endl;                          // Prints "false"
  cout << (a >= b) << endl;
  cout << (d == NumberWithUnits{3000, "m"}) << endl; // Prints "true"
  cout << (d == e) << endl;                          // Prints "true"
  cout << (d != e) << endl;


//try to initialize a unit that is not present
    try
  {
    cout << NumberWithUnits{7,"day"} << endl;
  }
  catch (const std::exception &ex)
  {
    cout << ex.what() << endl; // Prints "Units do not match - [m] cannot be converted to [kg]"
  }
/*
1 week = 7 day
1 day = 24 hour
1 hour = 60 min
1 min = 60 sec
*/
  ifstream units_file2{"units2.txt"};
  NumberWithUnits::read_units(units_file2);

  //now initialize the unit
  NumberWithUnits f{1,"week"};
  NumberWithUnits g{7,"day"};
  NumberWithUnits h{24,"hour"};

  cout<< (f+g) << endl; // prints 2 [week]
  cout << (f+7*h) << endl; // prints 2[week]
  cout<< g*5 + f << endl; // prints 43[day]
  cout<< h+f << endl; //prints 192 [hour]

    try
  {
    cout << (a + f) << endl;
  }
  catch (const std::exception &ex)
  {
    cout<< "units not from the same unit-verse!"<<endl;;
    cout << ex.what() << endl; // Prints "Units do not match - [m] cannot be converted to [kg]"
  }


  istringstream sample_input{"700 [ kg ]"};
  sample_input >> a;
  istringstream sample_input2{"1 [ton]"};
  sample_input2 >> b;
  cout << a+b << endl;                                // Prints "1700[kg]"
  cout << (a += NumberWithUnits{5, "ton"}) << endl; // prints "5700[kg]"
  cout << a << endl;                                // Prints "5700[kg]". Note that a has changed.

  cout << "End of Main!" << endl;
  return 0;
}
