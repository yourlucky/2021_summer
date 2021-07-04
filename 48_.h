#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<string.h>
#include <windows.h>

using namespace std;



int fourtyeight()
{
    //ifstream cin;//cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt");//cin의 콘솔입력을 대체-2

    int number[9][9];

    int data = 0;

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> data;
            number[i][j] = data;
        }
    }

    int avg[9] = { 0 };
    int an_number[9] = { 0 };
    double sum = 0;



    for (int i = 0; i < 9; i++)
    {
        sum = 0;
        for (int j = 0; j < 9; j++)
        {
            sum += number[i][j];
        }
        sum = round(sum / 9);
        avg[i] = sum;
    }

    int min = 2147000000;
    int number_c = 0;

    for (int i = 0; i < 9; i++)
    {
        min = 2147000000;
        number_c = 0;

        for (int j = 0; j < 9; j++)
        {
            int value = avg[i] - number[i][j];
            if (value * value < min)
            {
                min = value * value;
                an_number[i] = number[i][j];
            }

            else if (value * value < min)
            {
                if (an_number[i] < number[i][j])
                    an_number[i] = number[i][j];
            }

        }
    }

    for (int i = 0; i < 9; i++)
        cout << avg[i] << " " << an_number[i] << endl;


    return 0;
}
