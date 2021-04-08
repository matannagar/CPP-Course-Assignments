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
#include <string>
using namespace std;



int main()
{
  ifstream units_file{"units.txt"};
   int sum = 0;
   string s="";
    char x;
    ifstream inFile;
    
    inFile.open("units.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    
    while (inFile >> x) {
        
          s=s+x;
       
    }
    
    inFile.close();
    cout << "Sum = " << s << endl; 
  return 0;
}
