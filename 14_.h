#pragma once
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

int is_prime(int x);
int make_number(int x);

int fourteen()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2


    int count = 0;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        int number;
        cin >> number;
        number = make_number(number);
        if (is_prime(number))
            cout << number << " ";
    }

    return 0;
}

int is_prime(int x)
{
    if (x == 1)
        return 0;
    for (int i = x - 1; i > 1; i--)
    {
        if (x % i == 0)
            return 0;
    }
    return 1;
}


int make_number(int x)
{
    int origin_number = x;
    int change_number = 0;
    int count = 0;

    while (x)
    {
        count++;
        x = x / 10;
    }

    x = origin_number;

    for (int i = 1; i <= count; i++)
    {
        change_number += (x % 10) * pow(10, count - i);
        x = x / 10;
    }

    return change_number;

}