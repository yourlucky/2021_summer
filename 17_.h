#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;

void test(int x, int y);

int seventeen()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int count = 0, a_x, a_y;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        cin >> a_x;
        cin >> a_y;
        test(a_x, a_y);
    }

    return 0;
}

void test(int x, int y)
{
    int sum = 0;

    for (int i = 1; i <= x; i++)
        sum += i;


    if (sum == y)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}