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

void print(const graph &graph)
{
  string s = "[";
  vector<vector<pair<string, vector<pair<string, double>>>>> vec = graph.matrix;

  for (int i = 0; i < vec.size(); i++)
  {

    for (int j = 0; j < vec.at(i).size(); j++)
    {
      s += "<" + vec.at(i).at(j).first + "::";
      for (int k = 0; k < vec.at(i).at(j).second.size(); k++)
      {
        s += "(" + vec.at(i).at(j).second.at(k).first + "," + to_string(vec.at(i).at(j).second.at(k).second) + ")";
      }
      s += ">,";
    }
    s += "\n";
  }
  cout << s << endl;
}

void update(graph &graph, int line, double conv1, double conv2, const string &unit1, const string &unit2)
{
  int ind1;
  int ind2;
  int unit_length1;
  int unit_length2;
  int vec_length = graph.matrix.at(line).size();
  for (int i = 0; i < vec_length; i++)
  {

    if (graph.matrix.at(line).at(i).first == unit1)
    {
      ind1 = i;
      unit_length1 = graph.matrix.at(line).at(i).second.size();
    }
    if (graph.matrix.at(line).at(i).first == unit2)
    {
      ind1 = i;
      unit_length1 = graph.matrix.at(line).at(i).second.size();
    }
  }

  for (int i = 0; i < unit_length1; i++)
  {
    string s = graph.matrix.at(line).at(ind2).second.at(i).first;
    double d = graph.matrix.at(line).at(ind2).second.at(i).second;
    if (s != unit2)
    {
      graph.matrix.at(line).at(ind1).second.push_back(make_pair(s, conv1 * d));
    }
  }
  for (int i = 0; i < unit_length2; i++)
  {
    string s = graph.matrix.at(line).at(ind1).second.at(i).first;
    double d = graph.matrix.at(line).at(ind1).second.at(i).second;
    if (s != unit1)
    {
      graph.matrix.at(line).at(ind2).second.push_back(make_pair(s, conv1 * d));
    }
  }
}

void insert2units(vector<string> &units, graph &graph, int &i, unordered_map<string, int> &umap)
{
  double conv1 = stod(units.at(i + 3));
  double conv2 = 1 / stod(units.at(i + 3));
  string unit1 = units.at(i + 1);
  string unit2 = units.at(i + 4);

  //this is the vector we eventually emplace back to the matrix
  vector<pair<string, vector<pair<string, double>>>> final_vec;

  //vector that will contain conversions
  vector<pair<string, double>> right_inside_units;
  vector<pair<string, double>> left_inside_units;

  //each conversion going inside above vector
  pair<string, double> conversion;
  conv1 = stod(units.at(i + 3));
  conv2 = 1 / stod(units.at(i + 3));

  pair<string, double> right_conversion(units.at(i + 1), conv2); // (km,1\1000)

  pair<string, double> left_conversion(units.at(i + 4), conv1); //(m,1000)
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

void insert1unit(vector<string> &units, graph &graph, int &i, unordered_map<string, int> &umap)
{
  int pointer;
  int index;
  double conv1 = stod(units.at(i + 3));
  double conv2 = 1 / stod(units.at(i + 3));
  string unit1 = units.at(i + 1);
  string unit2 = units.at(i + 4);
  pair<string, int> left_unit;
  pair<string, int> right_unit;
  pair<string, vector<pair<string, double>>> add_to_existing_vec; // add new unit to line in matrix
  vector<pair<string, double>> add_to_pair;// vec inside the pair
  
  //if the right unit is missing:
  if (umap.count(units.at(i + 4)) == 0)
  {
    pointer = umap.at(unit1); // at which line am I

    
    //tells us at what line we should add the new pair
    // create a new pair to add to vec
    // // ~~~ 1
    // pair<string, double> curr_conversion(unit1, conv2);
    // // ~~~ 2
    // add_to_pair.push_back(curr_conversion); // created a new conversion list and added the curr conversion

    // //give the new vector a name
    // // ~~~ 3
    // add_to_existing_vec.first = unit2;
    // add_to_existing_vec.second = add_to_pair;

    // // ~~~ 4
    // //push to the matrix the final vector
    // graph.matrix.at(pointer).push_back(add_to_existing_vec); // add pair to the existing vecto

    // //create pair to add to the existing vector of the other unit
    // // ~~~ 5
    // left_unit.first = unit2;
    // left_unit.second = pointer;

    // //find my index !!TERRIBLE
    // // ~~~ 6
    // int ind;
    // for (int i = 0; i < graph.matrix.at(pointer).size(); i++)
    // {
    //   if (graph.matrix.at(pointer).at(i).first == unit1)
    //     ind = i;
    // }

    // // ~~~ 7
    // pair<string, double> left_conversion(unit2, conv1); //(m,1000)
    // graph.matrix.at(pointer).at(ind).second.push_back(left_conversion);
  }

  //if the left unit is missing
  else
  {
    unit1 = units.at(i + 4);
    unit2 = units.at(i + 1);
    //find where at which line am i
    pointer = umap.at(unit1);
    //conversions
    conv1 = stod(units.at(i + 3));
    conv2 = 1 / stod(units.at(i + 3));
    //create the conversion pair
    // // ~~~ 1
    // pair<string, double> curr_conversion(unit2, conv1);

    // // create a new pair to add to vec
    // // ~~~ 2
    // add_to_pair.push_back(curr_conversion);
    // // setting the new pair
    // // ~~~ 3
    // add_to_existing_vec.first = unit1;
    // add_to_existing_vec.second = add_to_pair;

    // // ~~~ 4
    // //this is the pair we will push insde vec
    // graph.matrix.at(pointer).push_back(add_to_existing_vec);

    // // ~~~ 5
    // // add pair to the existing vector
    // left_unit.first = unit1;
    // left_unit.second = pointer;

    // //find my index !!TERRIBLE
    // // ~~~ 6
    // int ind;
    // for (int i = 0; i < graph.matrix.at(pointer).size(); i++)
    // {
    //   if (graph.matrix.at(pointer).at(i).first == unit2)
    //     ind = i;
    // }
    // // ~~~ 7
    // pair<string, double> left_conversion(unit1, conv2); //(m,1000)
    // graph.matrix.at(pointer).at(ind).second.push_back(left_conversion);
  }
  
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~`
  // ~~~ 1
    pair<string, double> curr_conversion(unit1, conv2);
    // ~~~ 2
    add_to_pair.push_back(curr_conversion); // created a new conversion list and added the curr conversion

    //give the new vector a name
    // ~~~ 3
    add_to_existing_vec.first = unit2;
    add_to_existing_vec.second = add_to_pair;

    // ~~~ 4
    //push to the matrix the final vector
    graph.matrix.at(pointer).push_back(add_to_existing_vec); // add pair to the existing vecto

    //create pair to add to the existing vector of the other unit
    // ~~~ 5
    left_unit.first = unit2;
    left_unit.second = pointer;

    //find my index !!TERRIBLE
    // ~~~ 6
    int ind;
    for (int i = 0; i < graph.matrix.at(pointer).size(); i++)
    {
      if (graph.matrix.at(pointer).at(i).first == unit1)
        ind = i;
    }

    // ~~~ 7
    pair<string, double> left_conversion(unit2, conv1); //(m,1000)
    graph.matrix.at(pointer).at(ind).second.push_back(left_conversion);

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
  
  umap.insert(left_unit);
  // update(graph, pointer, conv1, conv2, unit1, unit2);
}

graph &initGraph(vector<string> &units, graph &graph)
{
  int count = 0;
  //list of units inserted up to now
  vector<pair<string, int>> graph_units;
  unordered_map<string, int> umap;

  for (int i = 0; i < units.size(); i += 5)
  {
    double conv1 = stod(units.at(i + 3));
    double conv2 = 1 / stod(units.at(i + 3));
    string unit1 = units.at(i + 1);
    string unit2 = units.at(i + 4);

    if (umap.count(units.at(i + 1)) == 0 && umap.count(units.at(i + 4)) == 0)
    {
      insert2units(units, graph, i, umap);
    }
    else if (umap.count(units.at(i + 1)) == 0 || umap.count(units.at(i + 4)) == 0)
    {
      insert1unit(units, graph, i, umap);
    }
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
  print(graph);
  return 0;
}
