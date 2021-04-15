#include <iostream>
#include "doctest.h" //include interface
#include "NumberWithUnits.hpp" //include interface
using namespace ariel; //ariel declared insdie snowman.hpp

#include <string>
using namespace std; //used to include functions such as memcpy..

TEST_CASE("read_units"){
ifstream units_file{"units.txt"};
NumberWithUnits::read_units(units_file);
/*
1 km = 1000 m
1 m = 100 cm
1 kg = 1000 g
1 ton = 1000 kg
1 hour = 60 min
1 min = 60 sec
1 USD = 3.33 ILS
*/
//AVILABLE UNITS
CHECK_NOTHROW(NumberWithUnits a(1,"km"));
CHECK_NOTHROW(NumberWithUnits b(1,"m"));
CHECK_NOTHROW(NumberWithUnits c(1,"cm"));
CHECK_NOTHROW(NumberWithUnits e(1,"ton"));
CHECK_NOTHROW(NumberWithUnits f(1,"kg"));
CHECK_NOTHROW(NumberWithUnits g(1,"hour"));
CHECK_NOTHROW(NumberWithUnits h(1,"min"));
CHECK_NOTHROW(NumberWithUnits i(1,"USD"));
CHECK_NOTHROW(NumberWithUnits j(1,"ILS"));
//UNAVILABLE UNITS: CASE SENSITIVE
CHECK_THROWS(NumberWithUnits k(1,"KM")) ;
CHECK_THROWS(NumberWithUnits m(1,"M"));
CHECK_THROWS(NumberWithUnits l(1,"CM"));
CHECK_THROWS(NumberWithUnits n(1,"TON"));
CHECK_THROWS(NumberWithUnits o(1,"KG"));
CHECK_THROWS(NumberWithUnits p(1,"HOUR"));
CHECK_THROWS(NumberWithUnits q(1,"MIN"));
CHECK_THROWS(NumberWithUnits r(1,"usd"));
CHECK_THROWS(NumberWithUnits z(1,"ils"));
//UNAVILABLE UNITS: NON EXISTENT
CHECK_THROWS(NumberWithUnits aa(1,"gallon"));
CHECK_THROWS(NumberWithUnits ab(1,"mm"));
CHECK_THROWS(NumberWithUnits ac(1,"inch"));
CHECK_THROWS(NumberWithUnits ad(1,"wolt"));
CHECK_THROWS(NumberWithUnits ae(1,"feet"));
CHECK_THROWS(NumberWithUnits af(1,"square"));
CHECK_THROWS(NumberWithUnits ag(1,"euro"));

} 
TEST_CASE("operator a+b"){
	
} 
TEST_CASE("operator a-b"){
}
TEST_CASE("operator a+=b"){
	
} 
TEST_CASE("operator a-=b"){
}
TEST_CASE("operator + unary"){
	
} 
TEST_CASE("operator - unary"){
}

TEST_CASE("operator a<b"){
	
} 
TEST_CASE("operator a>b"){
}
TEST_CASE("operator a<=b"){
	
} 
TEST_CASE("operator a>=b"){
}

TEST_CASE("operator a==b"){
}
TEST_CASE("operator a!=b"){
	
} 
TEST_CASE("operator ++a prefix"){
}
TEST_CASE("operator a++ postfix"){
	
} 
TEST_CASE("operator --a prefix"){
}
TEST_CASE("operator a-- postfix"){
	
} 
TEST_CASE("operator a*d || d*a "){
}
TEST_CASE("operator <<"){
	
} 
TEST_CASE("operator >>"){
}