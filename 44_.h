#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int possible(int gap, int horse_n, vector<int>& stall_l);

int fourtyfour()
{

    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int stall_n = 0;
    cin >> stall_n;

    int horse_n = 0;
    cin >> horse_n;

    vector<int> stall_l;


    int number = 0;
    for (int i = 0; i < stall_n; i++)
    {
        cin >> number;
        stall_l.push_back(number);
    }

    sort(stall_l.begin(), stall_l.end());

    int left = 0;
    int right = stall_l[stall_n - 1];
    int gap = (right + left) / 2;
    int answer = 0;


    while (left <= right)
    {
        if (possible(gap, horse_n, stall_l))
        {
            answer = gap;
            left = gap + 1;
        }
        else
        {
            right = gap - 1;
        }
        gap = (right + left) / 2;

    }
    cout << answer << endl;

    return 0;
}


int possible(int gap, int horse_n, vector<int>& stall_l)
{
    int location = stall_l[0];
    int count = 1;
    int i = 0;
    location = stall_l[0] + gap;

    while (count < horse_n)
    {
        i++;
        if (i > stall_l.size() - 1)
            return 0;
        if (stall_l[i] < location)
            continue;

        count++;
        location = stall_l[i] + gap;
    }

    return 1;
}