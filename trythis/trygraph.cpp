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
  unordered_map<string, int> umap; 
  unordered_map<string, int> lomap;
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
    s+="Line:"+to_string(i)+" ";
    for (int j = 0; j < vec.at(i).size(); j++)
    {
      s += "<" + vec.at(i).at(j).first + "::";
      for (int k = 0; k < vec.at(i).at(j).second.size(); k++)
      {
        s += "(" + vec.at(i).at(j).second.at(k).first + "," + to_string(vec.at(i).at(j).second.at(k).second) + ")";
      }
      if(j!=vec.at(i).size()-1)
      s += ">,";
      else s+=">";
    }
    if (i==vec.size()-1){
      s+="]";
    }
    else{
    s += "\n";
    }
  }
  cout << s << endl;
}

int findIndex(graph &graph, int line, string unit){
for (size_t i = 0; i < graph.matrix.at(line).size(); i++)
{
  if (graph.matrix.at(line).at(i).first==unit){
    return i;
  }
}
return -1;
}

double connect(graph &graph, int line, string left_unit, string right_unit)
{
  int out_vector = graph.matrix.at(line).size();
  double conversion=-10;
  int ind = 0;
  for (size_t i = 0; i < graph.matrix.at(line).size(); i++)
  {
    if (graph.matrix.at(line).at(i).first==left_unit){ 
      ind=i;
      break;
      }
  }

int length = graph.matrix.at(line).at(ind).second.size(); //KM vector length
  //check if KM has the right_unit
  for (int j = 0 ; j<length;j++ ){
    if(graph.matrix.at(line).at(ind).second.at(j).first==right_unit){
      return graph.matrix.at(line).at(ind).second.at(j).second;}
  }

  //THIS IS KM VECTOR
  vector<pair<string,double>> temp = graph.matrix.at(line).at(ind).second;
  int vec_length = temp.size();
  for (int i=0; i<graph.matrix.at(line).size();i++){


    string temp_unit = graph.matrix.at(line).at(ind).second.at(i).first;
    conversion= graph.matrix.at(line).at(ind).second.at(i).second;
    int temp_ind = findIndex(graph,line,temp_unit);

    int temp_length = graph.matrix.at(line).at(temp_ind).second.size();


    for(int j=0;j<temp_length;j++){
      string temp_name = graph.matrix.at(line).at(temp_ind).second.at(j).first;
      if(temp_name!=left_unit && temp_name!=temp_unit){
        conversion*=graph.matrix.at(line).at(temp_ind).second.at(j).second;
        graph.matrix.at(line).at(ind).second.push_back(make_pair(temp_name,conversion));
        vec_length++;
        conversion/=graph.matrix.at(line).at(temp_ind).second.at(j).second;
      }
    }
  }
  for(int i =0; i<graph.matrix.at(line).at(ind).second.size();i++){
    if (graph.matrix.at(line).at(ind).second.at(i).first==right_unit){
      cout<<" hello:" << graph.matrix.at(line).at(ind).second.at(i).second << endl;
      return graph.matrix.at(line).at(ind).second.at(i).second;
    }
  }
  
  return conversion;
}

void insert2units(vector<string> &units, graph &graph, int &i)
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
  graph.umap.insert(left_unit);
  graph.umap.insert(right_unit);
  
}

void insert1unit(vector<string> &units, graph &graph, int &i)
{
  int pointer;
  double conv1 = stod(units.at(i + 3));
  string unit1 = units.at(i + 1);
  string unit2 = units.at(i + 4);
  pair<string, int> left_unit;
  pair<string, int> right_unit;
  pair<string, vector<pair<string, double>>> add_to_existing_vec; // add new unit to line in matrix
  vector<pair<string, double>> add_to_pair;                       // vec inside the pair

  //if the right unit is missing:
  if (graph.umap.count(units.at(i + 4)) == 0)
  {
    pointer = graph.umap.at(unit1); // at which line am I
  }

  //if the left unit is missing
  else
  {
    unit1 = units.at(i + 4);
    unit2 = units.at(i + 1);
    //find where at which line am i
    pointer = graph.umap.at(unit1);
    conv1 = 1/stod(units.at(i + 3));
  }

  pair<string, double> curr_conversion(unit1, 1/conv1); //a pair that will be added
  add_to_pair.push_back(curr_conversion); // created a new conversion list and added the curr conversion

  //give the new vector a name
  add_to_existing_vec.first = unit2;
  add_to_existing_vec.second = add_to_pair;

  //push to the matrix the final vector
  graph.matrix.at(pointer).push_back(add_to_existing_vec); // add pair to the existing vecto

  //create pair to add to the existing vector of the other unit
  left_unit.first = unit2;
  left_unit.second = pointer; 
  
  int ind;
  for (int i = 0; i < graph.matrix.at(pointer).size(); i++)
  {
    if (graph.matrix.at(pointer).at(i).first == unit1)
      ind = i;
  }

  pair<string, double> left_conversion(unit2, conv1); //(m,1000)
  graph.matrix.at(pointer).at(ind).second.push_back(left_conversion);
  graph.umap.insert(left_unit);
}

graph &initGraph(vector<string> &units, graph &graph)
{
  int count = 0;
  //list of units inserted up to now
  vector<pair<string, int>> graph_units;
  

  for (int i = 0; i < units.size(); i += 5)
  {
    double conv1 = stod(units.at(i + 3));
    double conv2 = 1 / stod(units.at(i + 3));
    string unit1 = units.at(i + 1);
    string unit2 = units.at(i + 4);

    if (graph.umap.count(units.at(i + 1)) == 0 && graph.umap.count(units.at(i + 4)) == 0)
    {
      insert2units(units, graph, i);
    }
    else if (graph.umap.count(units.at(i + 1)) == 0 || graph.umap.count(units.at(i + 4)) == 0)
    {
      insert1unit(units, graph, i);
    }
  }
  for (auto &x : graph.umap)
    cout << x.first << ": " << x.second << endl;

  return graph;
}

int main()
{
   
  graph graph;
  vector<string> units = readText("test.txt");
  initGraph(units, graph);
 
  print(graph);
  double d = connect(graph,2,"hour","kg"); //1000000
  cout<<d<<endl;

  
  
  return 0;
}
