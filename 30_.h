#pragma once

#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int count_three(int number, int left, vector<int>& n_number);

int thirty()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    string number;
    cin >> number;

    vector<int>n_number;

    for (int i = 0; i < number.size(); i++)
    {
        n_number.push_back(number.at(i) - 48);
    }

    int left_count = 0;
    int right_count = 0;
    int number_one = 0;

    int answer = 0;
    for (int i = 0; i < n_number.size(); i++)
    {
        left_count = i;
        number_one = n_number.at(i);
        answer += count_three(number_one, left_count, n_number);
    }

    cout << answer << endl;


    return 0;
}


int count_three(int number, int left, vector<int>& n_number)
{
    int count_three = 0;
    if (number > 3)
    {
        int left_number = 0;

        for (int i = 0; i < left; i++)
        {
            left_number += n_number.at(i) * pow(10, left - i - 1);
        }
        //cout << "현재 자리수 : " << left << ",  왼쪽 숫자 : " << left_number << ",  곱해질 숫자 : " << pow(10, n_number.size() - left - 1) << endl;
        left_number++;
        count_three = left_number * pow(10, n_number.size() - left - 1);
    }
    else if (number == 3)
    {
        int left_number = 0;

        for (int i = 0; i < left; i++)
        {
            left_number += n_number.at(i) * pow(10, left - i - 1);
        }
        //cout << "현재 자리수 : " << left << ",  왼쪽 숫자 : " << left_number << ",  곱해질 숫자 : " << pow(10, n_number.size() - left - 1) << endl;
        count_three = (left_number)*pow(10, n_number.size() - left - 1);

        int right_number = 0;

        for (int i = left + 1; i < n_number.size(); i++)
        {
            right_number += n_number.at(i) * pow(10, n_number.size() - i - 1);
        }
        right_number++;
        count_three += right_number;
    }

    else if (number < 3)
    {
        int left_number = 0;

        for (int i = 0; i < left; i++)
        {
            left_number += n_number.at(i) * pow(10, left - i - 1);
        }
        //cout << "현재 자리수 : " << left << ",  왼쪽 숫자 : " << left_number << ",  곱해질 숫자 : " << pow(10, n_number.size() - left - 1) << endl;
        count_three = left_number * pow(10, n_number.size() - left - 1);
    }

    return count_three;
}
