#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;

int tweneytwo()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2


    int size = 0;
    int sequence = 0;

    cin >> size;
    cin >> sequence;

    int A_x[100000] = { 0 };
    int R_x[100000] = { 0 };

    for (int i = 0; i < size; i++)
        cin >> A_x[i];

    int max = -2140000000;
    int sub_sum = 0;


    for (int j = 0; j < sequence; j++)
        R_x[0] += A_x[j];

    for (int i = 1; i <= size - sequence; i++)
    {
        R_x[i] = R_x[i - 1] - A_x[i - 1] + A_x[i + sequence - 1];

        if (R_x[i] > max)
            max = R_x[i];
    }

    cout << max << endl;

    return 0;
}