#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;


int ninteen()
{
    //ifstream cin; //cin�� �ܼ��Է��� ��ü-1
    //cin.open("Input_data.txt"); //cin�� �ܼ��Է��� ��ü-2

    int x;
    cin >> x;

    int row[100] = { 0 };
    for (int i = 0; i < x; i++)
    {
        cin >> row[i];
    }



    bool answer = true;
    int max = row[x - 1];
    int count = 0;

    for (int i = x - 1; i >= 1; i--)
    {
        if (row[i] > max)
        {
            max = row[i];
            count++;
        }

    }

    cout << count;



    return 0;
}
