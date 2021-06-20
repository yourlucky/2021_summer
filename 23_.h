#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>

using namespace std;

int twentythree()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2


    int size = 0;
    int sequence = 0;

    cin >> size;

    vector<int> data;
    vector<int> answer(size);

    int number_d;

    for (int i = 0; i < size; i++)
    {
        cin >> number_d;
        data.push_back(number_d);
    }


    answer.at(0) = 1;

    int m_max = 0;
    for (int i = 1; i < data.size(); i++)
    {
        if (data.at(i) >= data.at(i - 1))
            answer.at(i) = answer.at(i - 1) + 1;
        else
            answer.at(i) = 1;

        if (answer.at(i) > m_max)
            m_max = answer.at(i);
    }

    cout << m_max << endl;

    return 0;
}