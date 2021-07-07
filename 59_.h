#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
void DFS(int i, int number, int arr[]);

int fiftynine()
{
    int number;
    cin >> number;

    int _set[11] = { 0 };
    DFS(1, number, _set);


    return 0;
}


void DFS(int i, int number, int arr[])
{
    if (i == number + 1)
    {
        for (int i = 0; i <= number; i++)
        {
            if (arr[i] == 1)
                cout << i << " ";
        }
        cout << endl;
    }

    else
    {
        arr[i] = { 1 };
        DFS(i + 1, number, arr);
        arr[i] = { 0 };
        DFS(i + 1, number, arr);
    }
}


