#include "NumberWithUnits.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>

constexpr int jump = 5;
constexpr double tolerance = 0.0001;

using namespace std;

namespace ariel
{
    NumberWithUnits::NumberWithUnits(double num, string const &unit)
    {
        std::unordered_map<std::string, uint>::const_iterator got = graph.umap.find(unit);
        if (got == graph.umap.end())
        {
            throw std::runtime_error("Unit is not present!");
        }
        this->num = num;
        this->unit = unit;
    }
    /*
    insert the entire units in a string vector
    and use it to intialize our graph
    */
    void NumberWithUnits::read_units(std::ifstream &file)
    {
        if (file.is_open())
        {
            string s;
            while (file >> s)
            {
                units.push_back(s);
            }
        }
        initGraph(units, graph);
    }
    /*
    this will initialize our graph by inserting either 2 new units
    or just 1 new unit, meaning we need to connect it with the other nodes 
    */
    void NumberWithUnits::initGraph(std::vector<std::string> &units, Graph &graph)
    {
        //list of units inserted up to now
        vector<pair<string, int>> graph_units;
        //based on the permenant positions of the units and conversions we will assign
        // each new verse as a new vector in our matrix
        for (unsigned int i = 0; i < units.size(); i += jump)
        {
            std::string unit1 = units.at(i + 1);
            std::string unit2 = units.at(i + 4);

            if (graph.umap.count(units.at(i + 1)) == 0 && graph.umap.count(units.at(i + 4)) == 0)
            {
                insert2units(units, graph, i);
            }
            else if (graph.umap.count(units.at(i + 1)) == 0 || graph.umap.count(units.at(i + 4)) == 0)
            {
                insert1unit(units, graph, i);
            }
        }
    }
    /*
    will help us find the index of the unit in the verse-vector
    */
    uint NumberWithUnits::findIndex(Graph &graph, string const &unit)
    {
        uint line = graph.umap.at(unit);
        for (size_t i = 0; i < graph.matrix.at(line).size(); i++)
        {
            if (graph.matrix.at(line).at(i).first == unit)
            {
                return i;
            }
        }
        return 0;
    }
    /*
   connect is the function responsible for the conversion of our given 2 units
   will also throw exception if 2 units are not from the same verse
   */
    double NumberWithUnits::connect(Graph &graph, string const &left_unit, string const &right_unit)
    {
        if (left_unit == right_unit)
        {
            return 1;
        }
        double conversion = 0.0;
        unordered_map<string, uint> existing_units;
        existing_units[left_unit] = 0;

        //first we check they are from the same unit-verse
        if (graph.umap.at(left_unit) == graph.umap.at(right_unit))
        {
            uint line = graph.umap.at(left_unit);
            vector<pair<string, vector<pair<string, double>>>> &ver_vec = graph.matrix.at(line);

            uint ind = findIndex(graph, left_unit);
            vector<pair<string, double>> &vec = ver_vec.at(ind).second; //KM_VEC

            int vec_length = vec.size();
            for (unsigned int i = 0; i < ver_vec.size(); i++)
            {
                string temp_unit = vec.at(i).first; // looking for the same unit
                if (temp_unit == right_unit)
                {
                    return 1 / vec.at(i).second;
                }
                conversion = vec.at(i).second;

                uint temp_ind = findIndex(graph, temp_unit);
                vector<pair<string, double>> &vec_temp = ver_vec.at(temp_ind).second;
                unsigned int temp_length = vec_temp.size();

                for (unsigned int j = 0; j < temp_length; j++)
                {
                    string temp_name = vec_temp.at(j).first;
                    if (existing_units.find(temp_name) == existing_units.end())
                    {
                        conversion *= vec_temp.at(j).second;
                        vec.push_back(make_pair(temp_name, conversion));
                        existing_units[temp_name] = i;
                        vec_length++;
                        conversion /= vec_temp.at(j).second;
                    }
                }
            }
            for (unsigned int i = 0; i < vec.size(); i++)
            {
                if (vec.at(i).first == right_unit)
                {
                    return 1 / vec.at(i).second;
                }
            }
        } //if not from unit-verse throw exception
        else
        {
            const std::exception ex;
            throw(ex);
        }

        return 1 / conversion;
    }

    /*
    responsuble for inserting only 1 new units,
    which means the verse-vector already exists and we need to connect it with each other
    */
    void NumberWithUnits::insert1unit(vector<string> &units, Graph &graph, uint i)
    {
        uint pointer = 0;
        double conv1 = stod(units.at(i + 3));
        string unit1 = units.at(i + 1);
        string unit2 = units.at(i + 4);
        pair<string, uint> left_unit;
        pair<string, uint> right_unit;
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
            conv1 = 1 / stod(units.at(i + 3));
        }

        pair<string, double> curr_conversion(unit1, 1 / conv1); //a pair that will be added
        add_to_pair.push_back(curr_conversion);                 // created a new conversion list and added the curr conversion

        //give the new vector a name
        add_to_existing_vec.first = unit2;
        add_to_existing_vec.second = add_to_pair;

        //push to the matrix the final vector
        graph.matrix.at(pointer).push_back(add_to_existing_vec); // add pair to the existing vecto

        //create pair to add to the existing vector of the other unit
        left_unit.first = unit2;
        left_unit.second = pointer;

        uint ind = 0;
        for (unsigned int i = 0; i < graph.matrix.at(pointer).size(); i++)
        {
            if (graph.matrix.at(pointer).at(i).first == unit1)
            {
                ind = i;
            }
        }

        pair<string, double> left_conversion(unit2, conv1); //(m,1000)
        graph.matrix.at(pointer).at(ind).second.push_back(left_conversion);
        graph.umap.insert(left_unit);
    }
    /*
    responsible for entering two entire units that has not been in the graph before
    thus creating a new verse-vector and inserting it into our matrix
    */
    void NumberWithUnits::insert2units(vector<string> &units, Graph &graph, uint i)
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

    // a+b = c
    NumberWithUnits operator+(const NumberWithUnits &f1, const NumberWithUnits &f2)
    {
        double d = NumberWithUnits::connect(graph, f1.unit, f2.unit);
        NumberWithUnits a(f1.num + f2.num * d, f1.unit);
        return a;
    }
    //a+=b
    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits &f2)
    {
        double d = NumberWithUnits::connect(graph, unit, f2.unit);
        num = num + f2.num * d;
        return *this;
    }

    //plus unari
    NumberWithUnits operator+(const NumberWithUnits &f1)
    {
        return f1;
    }
    //a-b=c
    NumberWithUnits operator-(const NumberWithUnits &f1, const NumberWithUnits &f2)
    {
        double d = NumberWithUnits::connect(graph, f1.unit, f2.unit);
        NumberWithUnits a(f1.num - f2.num * d, f1.unit);
        return a;
    }
    //a-=b;
    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& f2)
    {
        double d = NumberWithUnits::connect(graph, unit, f2.unit);
        num = num - f2.num * d;
        return *this;
    }

    //-(a) = -a
    NumberWithUnits operator-(const NumberWithUnits &f1)
    {
        NumberWithUnits a{-1 * f1.num, f1.unit};
        return a;
    }
    //a<b
    bool NumberWithUnits::operator<(const NumberWithUnits &f) const
    {
        double d = NumberWithUnits::connect(graph, unit, f.unit);
        return !(*this == f) && num < f.num * d;
    }
    //a<=b
    bool NumberWithUnits::operator<=(const NumberWithUnits &f) const
    {
        double d = NumberWithUnits::connect(graph, unit, f.unit);
        return num < f.num * d || num == f.num * d;
    }
    //a>b
    bool NumberWithUnits::operator>(const NumberWithUnits &f) const
    {
        double d = NumberWithUnits::connect(graph, unit, f.unit);
        return num > f.num * d;
    }
    //a>=b
    bool NumberWithUnits::operator>=(const NumberWithUnits &f) const
    {
        double d = NumberWithUnits::connect(graph, unit, f.unit);
        return num > f.num * d || num == f.num * d;
    }
    //a==b
    bool NumberWithUnits::operator==(const NumberWithUnits &f) const
    {
        double d = NumberWithUnits::connect(graph, unit, f.unit);
        return ((-1) * tolerance < num - f.num * d && num - f.num * d < tolerance);
    }
    //a!=b
    bool NumberWithUnits::operator!=(const NumberWithUnits &f) const
    {
        return !(*this == f);
    }
    //
    NumberWithUnits &NumberWithUnits::operator++()
    {
        this->num += 1;
        return *this;
    } // prefix: ++a
    NumberWithUnits NumberWithUnits::operator++(int)
    {
        NumberWithUnits temp = *this;
        ++(this->num);
        return temp;
    } // postfix: a++

    NumberWithUnits &NumberWithUnits::operator--()
    {
        this->num -= 1;
        return *this;
    } // prefix: --a
    NumberWithUnits NumberWithUnits::operator--(int)
    {
        NumberWithUnits temp = *this;
        --(this->num);
        return temp;
    } // postfix: a--
    //number*double
    NumberWithUnits operator*(const NumberWithUnits &f1, const double &f2)
    {
        NumberWithUnits a{f1.num * f2, f1.unit};
        return a;
    }
    //double * number
    NumberWithUnits operator*(const double &f1, const NumberWithUnits &f2)
    {
        NumberWithUnits a{f1 * f2.num, f2.unit};
        return a;
    }

    std::ostream &operator<<(std::ostream &os, const NumberWithUnits &f)
    {
        return os << f.num << "[" << f.unit << "]";
    }
    std::istream &operator>>(std::istream &is, NumberWithUnits &f)
    {
        double num = 0;
        string unit;
        char leftS = '.', rsign = '.';

        is >> skipws >> num >> leftS >> unit;
        if (unit.at(unit.length() - 1) == ']')
        {
            unit = unit.substr(0, unit.length() - 1);
        }
        else
        {
            is >> skipws >> rsign;
        }

        std::unordered_map<std::string, uint>::const_iterator got = graph.umap.find(unit);
        if (got == graph.umap.end())
        {
            throw std::runtime_error("Unit is not present!");
        }

        f.num = num;
        f.unit = unit;
        return is;
    }
}