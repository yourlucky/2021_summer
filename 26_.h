#pragma once

//merge sort concept can improve this code.
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int twentysix()
{
    //ifstream cin; //cin�� �ܼ��Է��� ��ü-1
    //cin.open("Input_data.txt"); //cin�� �ܼ��Է��� ��ü-2


    int size = 0;
    cin >> size;

    vector<int> data;

    int number_d;
    for (int i = 0; i < size; i++)
    {
        cin >> number_d;
        data.push_back(number_d);
    }




    int ranking = 1;
    for (int i = 0; i < size; i++)
    {
        ranking = 1;

        for (int j = 0; j < i; j++)
        {
            if (data[i] <= data[j])
                ranking++;
        }

        cout << ranking << " ";
    }

    return 0;
}