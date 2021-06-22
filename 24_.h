#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int twentyfour()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2


    int size = 0;
    cin >> size;

    vector<int> data;
    vector<int> difference;

    int number_d;
    for (int i = 0; i < size; i++)
    {
        cin >> number_d;
        data.push_back(number_d);
    }

    for (int i = 0; i < size - 1; i++)
    {
        difference.push_back(std::abs(data.at(i + 1) - data.at(i)));
    }


    bool answer = 0;
    for (int i = 1; i <= size - 1; i++)
    {
        answer = 0;
        for (int j : difference)
        {
            if (i == j)
            {
                answer = 1;
                break;
            }
        }
        if (answer == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}