#ifndef NUMBERWITHUNITS_H
#define NUMBERWITHUNITS_H
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>

namespace ariel
{
    class NumberWithUnits
    {
    public:
        NumberWithUnits(){};

        void read_units(const std::string &file);
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
    };
}

#endif