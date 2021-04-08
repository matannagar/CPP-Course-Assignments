#include <iostream>
#include <vector>
#include <string>
#include <fstream>

int main()
{
    using namespace std;

    ifstream file("test.txt");
    if(file.is_open())
    {
        vector<string> myVec;
        string s;

        // for(int i = 0; i < 5; ++i)
        // {
        //     file >> s;
        //     myVec.push_back(s);
        // }

        while (file >> s) {
        
          myVec.push_back(s);
       
    }
        // for(int i = 0; i < myVec.size(); ++i)
        // {
        //     cout << myVec.at(i);
        // }
    cout<<myVec.at(0);
    }
    

}