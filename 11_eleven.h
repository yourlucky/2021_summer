#pragma once
#include<iostream>
#include<fstream>


using namespace std;

int digit_sum(int x);

int eleven()
{
    //ifstream cin; //cin�� �ܼ��Է��� ��ü-1
    //cin.open("Input_data.txt"); //cin�� �ܼ��Է��� ��ü-2

    int x;
    cin >> x;

    int answer = 0;

    for (int i = 1; i <= x; i++)
        answer += digit_sum(i);

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
