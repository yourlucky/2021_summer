#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int twentyfive()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2


    int size = 0;
    int sequence = 0;

    cin >> size;

    vector<int> data;
    vector<int> ranking;

    int number_d;

    for (int i = 0; i < size; i++)
    {
        cin >> number_d;
        data.push_back(number_d);
        ranking.push_back(number_d);
    }

    std::sort(ranking.begin(), ranking.end(), greater<int>());




    for (int i : data)
    {
        for (int j = 0; j < ranking.size(); j++)
        {
            if (i == ranking.at(j))
            {
                cout << j + 1 << " ";
                break;
            }
        }
    }

    return 0;
}