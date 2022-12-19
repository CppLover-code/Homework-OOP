#pragma once
#include <iostream>

using namespace std;

class Data
{
    int d;
    int m;
    int y;

public:

    Data();

    friend int Less(const Data& D);

    friend int Greater(const Data& D);

    friend  std::ostream& operator<<(std::ostream& os, const Data& P);

    int operator-(Data& t);

    Data operator+(int count);

    void Output()
    {
        cout << d << "." << m << "." << y << "\n";
    }

    ~Data()
    {
        // cout << " Деструктор\n";
    }
};
