#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
void DFS(int i, int number, int sum, int arr[], int _raw[]);

int big_answer = 0;

int sixty()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int number;
    cin >> number;

    int _raw[11] = { 0 };
    int data;
    int sum = 0;

    for (int i = 1; i <= number; i++)
    {
        cin >> data;
        sum += data;
        _raw[i] = data;
    }

    if (sum % 2 == 1)
    {
        cout << "NO" << endl;
        return 0;
    }
    sum /= 2;



    int _set[11] = { 0 };
    DFS(1, number, sum, _set, _raw);


    if (big_answer == 0)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;


    return 0;
}


void DFS(int i, int number, int sum, int arr[], int _raw[])
{
    if (i == number + 1)
    {
        int p_sum = 0;
        for (int j = 0; j <= number; j++)
        {
            if (arr[j] == 1)
            {
                // cout <<_raw[j] <<",  ";
                p_sum += _raw[j];
            }
        }
        //cout << endl;

        if (p_sum == sum)
            big_answer = 1;
    }

    else
    {
        arr[i] = 1;
        DFS(i + 1, number, sum, arr, _raw);
        arr[i] = 0;
        DFS(i + 1, number, sum, arr, _raw);
    }
}

