#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;

void test(int x, int y);

int eighteen()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int x, y;

    cin >> x;
    cin >> y;

    test(x, y);

    return 0;
}

void test(int x, int y)
{
    int count = 0;
    int measurements[100] = { 0 };
    int max = 0;


    for (int i = 0; i < x; i++)
    {
        cin >> measurements[i];
    }

    for (int i = 0; i < x; i++)
    {
        if (measurements[i] > y)
            count++;
        else
            count = 0;

        if (count > max)
            max = count;
    }

    cout << max << endl;
}
