#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>


void print_n(int n);
using namespace std;


int fiftyseven()
{
    int number = 0;
    cin >> number;

    print_n(number);

    return 0;
}

void print_n(int  n)
{
    if (n == 1 || n == 0)
    {
        cout << n;
        return;
    }
    else
    {
        print_n(n / 2);
        cout << n % 2;
    }
}
