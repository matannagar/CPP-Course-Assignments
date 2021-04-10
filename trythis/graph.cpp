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
#include <vector>
using namespace std;

struct node
{
  string unit;
  static int id;
  int verse;
  std::vector<pair<string, double>> vect;
};

struct graph_node
{
  std::vector<node> vertices;
};
int node::id = -1;
string connect() void print(node &node)
{
  string s = "~~" + node.unit + "~~\n";
  s += "Node ID: " + to_string(node.id) + "\nVerse: " + std::to_string(node.verse);
  string t = "\n[";
  for (int i = 0; i < node.vect.size(); i++)
  {
    t += "(" + node.vect.at(i).first + "," + to_string(node.vect.at(i).second) + ")";
    if (i < node.vect.size() - 1)
    {
      t += ",";
    }
  }
  t = t + "]";
  s = s + t;
  cout << s << endl;
}
/*
this function will receive a string format array
looping through the array it will create nodes 
add the units to the checklist array (to make sure there are no duplicates)
store the nodes in a graph.
*/
void divideToNodes(const string &list, graph &graph)
{
  vector<pair<string, int>> vect; //list of all available units, made to prevent duplicates

  string s[] = {"1", "km", "=", "1000", "m", "1", "m", "=", "100", "cm"}; // not meant to be here

  int verse = 0;
  for (int i = 0; i < s.size(); i += 5)
  {
    string v1 = s[1 + i];
    string v2 = s[4 + i];

    for (int j = 0; j < vect.size(); j++)
    {
      if (vect.at(j).first == v1) // if the unit already exists , connect it
      {
      }
      else if (vect.at(j).first == v2)
      {
      }
      else
      {
        
      }
    }
  }
}
int main()
{

  string t = " hello ben how r u";
  vector<char> v(t.begin(), t.end());
  cout << v.at(2);
  string s[] = {"1", "km", "=", "1000", "m", "1", "m", "=", "100", "cm"};
  node v1;
  v1.unit = s[1];
  v1.id = node::id;
  node::id++;
  v1.verse = 0;
  v1.vect.emplace_back(make_pair(s[4], stod(s[3])));

  node v2;
  v2.unit = s[4];
  v2.id = node::id;
  node::id++;
  v2.verse = 0;
  v2.vect.emplace_back(make_pair(s[1], 1 / stod(s[3])));

  print(v1);
  print(v2);

  return 0;
}
