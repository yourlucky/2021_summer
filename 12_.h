#pragma once


#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int digit_sum(int x);

int tweleve()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int number[9] = { 0 };

    int sp_number = 0;

    for (int i = 1; i < 9; i++)
    {
        number[i] += number[i - 1];
        number[i] += (pow(10, i) - pow(10, i - 1)) * i;
    }



    int x;
    cin >> x;

    int digit = 0;
    digit = digit_sum(x) - 1;

    int answer = (x - pow(10, digit) + 1) * (digit + 1);
    answer += number[digit];


    cout << answer << endl;

    return 0;
}

int digit_sum(int x)
{
    int count = 0;

    while (x)
    {
        count++;
        x = x / 10;
    }

    return count;
}