#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>

void print_n(const int& n);
using namespace std;

int fiftysix()
{
    int number = 0;
    cin >> number;

    print_n(number);

    return 0;
}

void print_n(const int& n)
{
    if (n < 1)
        return;
    else
    {
        print_n(n - 1);
        cout << n << " ";
    }
}
