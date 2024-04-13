#pragma once

#include<iostream>

using namespace std;


inline void line(int n) // A simple line used for formatting
{
    for (int i(0); i < n; i++)
    {
        std::cout << '-';
    }
    std::cout << "+" << endl;
}