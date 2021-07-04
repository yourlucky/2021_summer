#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<string.h>
#include <windows.h>

using namespace std;



int fourtyseven()
{
    ifstream cin;//cin의 콘솔입력을 대체-1
    cin.open("Input_data.txt");//cin의 콘솔입력을 대체-2

    int size = 0;
    cin >> size;

    size += 2;

    int** arr = new int* [size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = new int[size];
        memset(arr[i], 0, sizeof(int) * size);
    }

    int f_size = size - 2;

    int number = 0;
    for (int i = 1; i <= f_size; i++)
    {
        for (int j = 1; j <= f_size; j++)
        {
            cin >> number;
            arr[i][j] = number;
        }
    }

    int count = 0;
    for (int i = 1; i <= f_size; i++)
    {
        for (int j = 1; j <= f_size; j++)
        {
            if (arr[i][j] > arr[i + 1][j] && arr[i][j] > arr[i][j + 1] && arr[i][j] > arr[i - 1][j] && arr[i][j] > arr[i][j - 1])
                count++;
        }
    }

    cout << count << endl;


    for (int i = 0; i < size; ++i)
    {
        delete[] arr[i];
    }

    delete[]arr;
    return 0;
}
