#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int thirtytwo()
{
    ifstream cin; //cin의 콘솔입력을 대체-1
    cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int number_size = 0;
    cin >> number_size;

    vector<int> box;
    int input;

    while (cin >> input)
        box.push_back(input);

    int min = 100000000000;
    int swap = 9999;
    for (int i = 0; i < number_size; i++)
    {
        min = box.at(i);
        for (int j = i; j < number_size; j++)
        {
            if (box.at(j) < min)
            {
                min = box.at(j);
                box.at(j) = box.at(i);
                box.at(i) = min;

            }
        }
    }

    for (int k : box)
        cout << k << " ";

    return 0;
}