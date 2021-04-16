#include <iostream>
#include "doctest.h"           //include interface
#include "NumberWithUnits.hpp" //include interface
using namespace ariel;         //ariel declared insdie snowman.hpp

#include <string>
using namespace std; //used to include functions such as memcpy..

TEST_CASE("read_units")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    /*
1 km = 1000 m
1 m = 100 cm
1 kg = 1000 g
1 ton = 1000 kg
1 hour = 60 min
1 kg = 1000 g
1 ton = 1000 kg
1 hour = 60 min
1 min = 60 sec
1 USD = 3.33 ILS
*/
    //AVILABLE UNITS
    CHECK_NOTHROW(NumberWithUnits a(1, "km"));
    CHECK_NOTHROW(NumberWithUnits b(1, "m"));
    CHECK_NOTHROW(NumberWithUnits c(1, "cm"));
    CHECK_NOTHROW(NumberWithUnits e(1, "ton"));
    CHECK_NOTHROW(NumberWithUnits f(1, "kg"));
    CHECK_NOTHROW(NumberWithUnits g(1, "hour"));
    CHECK_NOTHROW(NumberWithUnits h(1, "min"));
    CHECK_NOTHROW(NumberWithUnits i(1, "USD"));
    CHECK_NOTHROW(NumberWithUnits j(1, "ILS"));
    //UNAVILABLE UNITS: CASE SENSITIVE
    CHECK_THROWS(NumberWithUnits k(1, "KM"));
    CHECK_THROWS(NumberWithUnits m(1, "M"));
    CHECK_THROWS(NumberWithUnits l(1, "CM"));
    CHECK_THROWS(NumberWithUnits n(1, "TON"));
    CHECK_THROWS(NumberWithUnits o(1, "KG"));
    CHECK_THROWS(NumberWithUnits p(1, "HOUR"));
    CHECK_THROWS(NumberWithUnits q(1, "MIN"));
    CHECK_THROWS(NumberWithUnits r(1, "usd"));
    CHECK_THROWS(NumberWithUnits z(1, "ils"));
    //UNAVILABLE UNITS: NON EXISTENT
    CHECK_THROWS(NumberWithUnits aa(1, "gallon"));
    CHECK_THROWS(NumberWithUnits ab(1, "mm"));
    CHECK_THROWS(NumberWithUnits ac(1, "inch"));
    CHECK_THROWS(NumberWithUnits ad(1, "wolt"));
    CHECK_THROWS(NumberWithUnits ae(1, "feet"));
    CHECK_THROWS(NumberWithUnits af(1, "square"));
    CHECK_THROWS(NumberWithUnits ag(1, "euro"));
}
TEST_CASE("operator a+b")
{

    //normal addition
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km
    CHECK((a + a).num == 2);
    CHECK((a + b).num == 1.1);
    CHECK((a + c).num == 1.01);
    CHECK((b + a).num == 1100);
    CHECK((b + b).num == 200);
    CHECK((b + c).num == 110);
    CHECK((c + a).num == 101000);
    CHECK((c + b).num == 11000);
    CHECK((c + c).num == 2000);

    //add 0
    NumberWithUnits d(0, "km"); //10m , 0.01km
    CHECK((a + d).num == 1);
    CHECK((b + d).num == 100);
    CHECK((c + d).num == 1000);

    //add -1
    NumberWithUnits e(-1, "km"); //10m , 0.01km
    CHECK((a + d).num == 0);
    CHECK((b + d).num == -900);
    CHECK((c + d).num == -99000);
}
TEST_CASE("operator a-b")
{
    //normal substraction
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km
    CHECK((a - a).num == 0);
    CHECK((a - b).num == 0.9);
    CHECK((a - c).num == 0.99);
    CHECK((b - a).num == -900);
    CHECK((b - b).num == 0);
    CHECK((b - c).num == 90);
    CHECK((c - a).num == -99000);
    CHECK((c - b).num == -9000);
    CHECK((c - c).num == 0);

    //substract 0
    NumberWithUnits d(0, "km"); //10m , 0.01km
    CHECK((a - d).num == 1);
    CHECK((b - d).num == 100);
    CHECK((c - d).num == 1000);

    //add -1
    NumberWithUnits e(-1, "km"); //10m , 0.01km
    CHECK((a - d).num == 2);
    CHECK((b - d).num == 1100);
    CHECK((c - d).num == 101000);
}
TEST_CASE("operator a+=b")
{
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km

    CHECK((a += a).num == 2);
    CHECK((a += b).num == 1.1);
    CHECK((a += c).num == 1.01);
    CHECK((b += a).num == 1100);
    CHECK((b += b).num == 200);
    CHECK((b += c).num == 110);
    CHECK((c += a).num == 101000);
    CHECK((c += b).num == 11000);
    CHECK((c += c).num == 2000);
}
TEST_CASE("operator a-=b")
{
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km

    CHECK((a -= a).num == 0);
    CHECK((a -= b).num == 0.9);
    CHECK((a -= c).num == 0.99);
    CHECK((b -= a).num == -900);
    CHECK((b -= b).num == 0);
    CHECK((b -= c).num == 90);
    CHECK((c -= a).num == -99000);
    CHECK((c -= b).num == -9000);
    CHECK((c -= c).num == 0);
}
TEST_CASE("operator + unary")
{
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km

    CHECK((+a).num == 1);
    CHECK((+b).num == 100);
    CHECK((+c).num == 1000);
}
TEST_CASE("operator - unary")
{
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km

    CHECK((-a).num == -1);
    CHECK((-b).num == -100);
    CHECK((-c).num == -1000);
}

TEST_CASE("operator a<b")
{
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km

    CHECK((a < a) == false);
    CHECK((a < b) == false);
    CHECK((a < c) == false);

    CHECK((b < a) == true);
    CHECK((b < b) == false);
    CHECK((b < c) == false);

    CHECK((c < a) == true);
    CHECK((c < b) == true);
    CHECK((c < c) == false);
}
TEST_CASE("operator a>b")
{
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km

    CHECK((a > a) == false);
    CHECK((a > b) == true);
    CHECK((a > b) == true);

    CHECK((b > a) == false);
    CHECK((b > b) == false);
    CHECK((b > c) == true);

    CHECK((c > a) == false);
    CHECK((c > b) == false);
    CHECK((c > c) == false);
}
TEST_CASE("operator a<=b")
{
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km

    CHECK((a <= a) == true);
    CHECK((a <= b) == false);
    CHECK((a <= c) == false);

    CHECK((b <= a) == true);
    CHECK((b <= b) == true);
    CHECK((b <= c) == false);

    CHECK((c <= a) == true);
    CHECK((c <= b) == true);
    CHECK((c <= c) == true);
}
TEST_CASE("operator a>=b")
{
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km

    CHECK((a >= a) == true);
    CHECK((a >= b) == true);
    CHECK((a >= c) == true);

    CHECK((b >= a) == false);
    CHECK((b >= b) == true);
    CHECK((b >= c) == true);

    CHECK((c >= a) == false);
    CHECK((c >= b) == false);
    CHECK((c >= c) == true);
}

TEST_CASE("operator a==b")
{
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km

    CHECK((a == a) == true);
    CHECK((a == b) == false);
    CHECK((a == c) == false);

    CHECK((b == a) == true);
    CHECK((b == b) == true);
    CHECK((b == c) == false);

    CHECK((c == a) == false);
    CHECK((c == b) == false);
    CHECK((c == c) == true);
}
TEST_CASE("operator a!=b")
{
    NumberWithUnits a(1, "km");    //1000m, 100,000cm
    NumberWithUnits b(100, "m");   //0.1km , 10,000cm
    NumberWithUnits c(1000, "cm"); //10m , 0.01km

    CHECK((a != a) == false);
    CHECK((a != b) == true);
    CHECK((a != c) == true);

    CHECK((b != a) == true);
    CHECK((b != b) == false);
    CHECK((b != c) == true);

    CHECK((c != a) == true);
    CHECK((c != b) == true);
    CHECK((c != c) == false);
}
TEST_CASE("operator ++a prefix")
{
}
TEST_CASE("operator a++ postfix")
{
}
TEST_CASE("operator --a prefix")
{
}
TEST_CASE("operator a-- postfix")
{
}
TEST_CASE("operator a*d || d*a ")
{
}
TEST_CASE("operator <<")
{
}
TEST_CASE("operator >>")
{
}