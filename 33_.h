#pragma once
#include<iostream>
#include<vector>

using namespace std;

int thirtythree()
{
    //ifstream cin; //cin�� �ܼ��Է��� ��ü-1
    //cin.open("Input_data.txt"); //cin�� �ܼ��Է��� ��ü-2

    int number_size = 0;
    cin >> number_size;

    vector<int> box;
    int input;

    for (int i = 0; i < number_size; i++)
    {
        cin >> input;
        box.push_back(input);
    }
    int max_one = -1;
    int max_two = -2;
    int max_three = -3;

    for (int i = 0; i < number_size; i++)
    {
        if (max_three < box.at(i) && max_two != box.at(i) && max_one != box.at(i))
        {
            if (max_two < box.at(i))
            {
                if (max_one < box.at(i))
                {
                    max_three = max_two;
                    max_two = max_one;
                    max_one = box.at(i);
                }
                else
                {
                    max_three = max_two;
                    max_two = box.at(i);
                }
            }
            else
            {
                max_three = box.at(i);
            }
        }

    }

    cout << max_three;


    return 0;
}
