#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


int twentynight()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int number = 0;
    cin >> number;

    int answer = 0;
    int tmp = 0;
    int digit = 0;
    for (int i = 1; i <= number; i++)
    {
        tmp = i;
        while (tmp > 0)
        {
            digit = tmp % 10;
            if (digit == 3)
                answer++;
            tmp = tmp / 10;
        }
    }

    cout << answer << endl;

    return 0;
}

