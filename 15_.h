#pragma once
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

bool is_prime(int x);

int fifteen()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2


    int count = 0;
    cin >> count;

    int answer = 0;

    for (int i = 2; i <= count; i++)
    {
        answer += is_prime(i);
    }

    cout << answer;


    return 0;
}

inline bool is_prime(int x)
{
    if (x == 1)
        return 0;


    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}
