#ifndef NUMBERWITHUNITS_H
#define NUMBERWITHUNITS_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <stdexcept>
using namespace std;
namespace ariel
{
    struct Graph
    {
        vector<vector<pair<string, vector<pair<string, double>>>>> matrix;
        unordered_map<string, int> umap;
        unordered_map<string, int> lomap;
    };

    class NumberWithUnits
    {

        string unit;
        double num;

    public:
        
        static Graph graph;

        NumberWithUnits(double num, string unit)
        {
            this->num = num;
            this->unit = unit;
        };
        NumberWithUnits();

        double getNum();
        string getUnit();

        static void read_units(ifstream &file)
        {
            vector<string> myUnits;
            if (file.is_open())
            {
                string s;
                while (file >> s)
                {
                myUnits.push_back(s);
                }
            }
        }

        friend NumberWithUnits operator+(const NumberWithUnits &f1, const NumberWithUnits &f2);
        friend NumberWithUnits operator+=(const NumberWithUnits &f1, const NumberWithUnits &f2);
        friend NumberWithUnits operator+(const NumberWithUnits &f1);

        friend NumberWithUnits operator-(const NumberWithUnits &f1, const NumberWithUnits &f2);
        friend NumberWithUnits operator-=(const NumberWithUnits &f1, const NumberWithUnits &f2);
        friend NumberWithUnits operator-(const NumberWithUnits &f1);

        bool operator<(const NumberWithUnits &f) const;
        bool operator<=(const NumberWithUnits &f) const;
        bool operator>(const NumberWithUnits &f) const;
        bool operator>=(const NumberWithUnits &f) const;
        bool operator==(const NumberWithUnits &f) const;
        bool operator!=(const NumberWithUnits &f) const;

        NumberWithUnits &operator++();         // prefix: ++a
        const NumberWithUnits operator++(int); // postfix: a++

        NumberWithUnits &operator--();         // prefix: --a
        const NumberWithUnits operator--(int); // postfix: a--

        friend NumberWithUnits operator*(const NumberWithUnits &f1, const double &f2);
        friend NumberWithUnits operator*(const double &f1, const NumberWithUnits &f2);

        friend std::ostream &operator<<(std::ostream &os, const NumberWithUnits &f);
        friend std::istream &operator>>(std::istream &is, NumberWithUnits &f);

        void initGraph(vector<string> &units, Graph &graph);
        void print(const Graph &graph);
        int findIndex(Graph &graph, string unit);
        double connect(Graph &graph, string left_unit, std::string right_unit);
        void insert2units(vector<string> &units, Graph &graph, int i);
        void insert1unit(vector<string> &units, Graph &graph, int i);
    };
}

#endif