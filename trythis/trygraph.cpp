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
#include <unordered_map>
using namespace std;
struct graph
{
  vector<vector<pair<string, vector<pair<string, double>>>>> matrix;
};

std::vector<string> readText(const string &file_name)
{
  vector<string> myVec;
  ifstream file(file_name);
  if (file.is_open())
  {
    string s;
    while (file >> s)
    {
      myVec.push_back(s);
    }
  }
  return myVec;
}

void update(graph &graph,int line, const string &unit_1, const string &unit2)
{
for (size_t i = 0; i < graph.matrix.at(line).size(); i++)
{
  if (graph.matrix.at(line).at(i).first==unit_1 || graph.matrix.at(line).at(i).first==unit_1){
    for (size_t j=i+1;j<graph.matrix.at(line).size();j++){
      if (graph.matrix.at(line).at(j).first==unit_1 || graph.matrix.at(line).at(j).first==unit_1)
      {
        graph.matrix.at(line).at(i).second; // this is my conversion vector
        graph.matrix.at(line).at(j).second; // this is the other conversion vector.
        pair<string,double> conv;
         
      }
    }
  }
}

}

graph &initGraph(vector<string> &units, graph &graph)
{
  //list of units inserted up to now
  vector<pair<string, int>> graph_units;
  unordered_map<string, int> umap;

  for (int i = 0; i < units.size(); i += 5)
  {
    string unit1=units.at(i+1);
    string unit2=units.at(i+4);
    if (umap.count(units.at(i + 1)) == 0 && umap.count(units.at(i + 4)) == 0) //only if the two units are not available
    {
      //this is the vector we eventually emplace back to the matrix
      vector<pair<string, vector<pair<string, double>>>> final_vec;

      //vector that will contain conversions
      vector<pair<string, double>> right_inside_units;
      vector<pair<string, double>> left_inside_units;

      //each conversion going inside above vector
      pair<string, double> conversion;
      pair<string, double> left_conversion(units.at(i + 4), stod(units.at(i + 3)));      //(m,1000)
      pair<string, double> right_conversion(units.at(i + 1), 1 / stod(units.at(i + 3))); // (km,1\1000)

      left_inside_units.push_back(left_conversion);
      right_inside_units.push_back(right_conversion);

      //this pair is one of two that will be pushed inside above vec
      pair<string, vector<pair<string, double>>> left_pair(units.at(i + 1), left_inside_units);
      pair<string, vector<pair<string, double>>> right_pair(units.at(i + 4), right_inside_units);

      final_vec.push_back(left_pair);
      final_vec.push_back(right_pair);

      //add new conversion units to the graph
      graph.matrix.emplace_back(final_vec);

      //mark which units were added to the list with the index of the line
      pair<string, int> left_unit(units.at(i + 1), graph.matrix.size() - 1);
      pair<string, int> right_unit(units.at(i + 4), graph.matrix.size() - 1);
      umap.insert(left_unit);
      umap.insert(right_unit);
    }
    else if (umap.count(units.at(i + 1)) == 0 || umap.count(units.at(i + 4)) == 0) //only 1 isnt available
    {
      int pointer;
      int index;
      pair<string, int> left_unit;
      pair<string, vector<pair<string, double>>> add_to_existing_vec;
      vector<pair<string, double>> add_to_pair;
      if (umap.count(units.at(i + 4)) == 0)
      {
        pointer = umap.at(units.at(i + 1));                                                    //tells us at what line we should add the new pair
        pair<string, double> curr_conversion(units.at(i + 1), 1 / stod(units.at(i + 3)));      // create a new pair to add to vec
        add_to_pair.push_back(curr_conversion);                                                // created a new conversion list and added the curr conversion
        add_to_existing_vec.first = units.at(i + 4), add_to_existing_vec.second = add_to_pair; //this is the pair we will push insde vec
        graph.matrix.at(pointer).push_back(add_to_existing_vec);                               // add pair to the existing vector
        left_unit.first = units.at(i + 4), left_unit.second = pointer;
      }
      else
      {
        pointer = umap.at(units.at(i + 4));                                                    //tells us at what line we should add the new pair
        pair<string, double> curr_conversion(units.at(i + 4), stod(units.at(i + 3)));          // create a new pair to add to vec
        add_to_pair.push_back(curr_conversion);                                                // created a new conversion list and added the curr conversion
        add_to_existing_vec.first = units.at(i + 1), add_to_existing_vec.second = add_to_pair; //this is the pair we will push insde vec
        graph.matrix.at(pointer).push_back(add_to_existing_vec);                               // add pair to the existing vector
        left_unit.first = units.at(i + 1), left_unit.second = pointer;
      }
      umap.insert(left_unit);
    }
    else //if two of units are available, then connect them
    {
      int pointer1 = umap.at(units.at(i + 1));
      int pointer2 = umap.at(units.at(i + 4));
      int size_vec1 = graph.matrix.at(pointer1).size();
      int size_vec2 = graph.matrix.at(pointer2).size();
      //join the second vector to the first vector
      for (int i = 0; i < size_vec2; i++)
      {
        graph.matrix.at(pointer1).push_back(graph.matrix.at(pointer2).at(i));
      }

      //iterate the umap to update index
      for (auto it = umap.begin(); it != umap.end(); ++it)
      {
        if (it->second == pointer2)
          it->second = pointer1;
      }
      graph.matrix.erase(graph.matrix.begin() + pointer2);
    }
    update(graph,0,unit1,unit2);
  }
  for (auto &x : umap)
    cout << x.first << ": " << x.second << endl;

  return graph;
}
int main()
{
  graph graph;
  vector<string> units = readText("test.txt");
  initGraph(units, graph);
  return 0;
}
