#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
void DFS(int i, int number, int target, int arr[], int _raw[]);

int big_answer = 0;

int sixtyone()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int number;
    cin >> number;

    int target;
    cin >> target;


    int _raw[11] = { 0 };
    int data;

    for (int i = 1; i <= number; i++)
    {
        cin >> data;
        _raw[i] = data;
    }



    int _set[11] = { 0 };
    DFS(1, number, target, _set, _raw);


    if (big_answer == 0)
        cout << "-1" << endl;
    else
        cout << big_answer << endl;


    return 0;
}


void DFS(int i, int number, int target, int arr[], int _raw[])
{
    if (i == number + 1)
    {
        int p_sum = 0;
        for (int j = 1; j <= number; j++)
        {
            if (arr[j] == 1)
            {
                p_sum += _raw[j];
            }
            else if (arr[j] == -1)
            {
                p_sum -= _raw[j];
            }
        }

        if (p_sum == target)
        {
            big_answer++;
            /* for(int j=1; j <= number; j++)
                 cout<< "j값 : "<< j <<", arr[j] : "<< arr[j] << ", _raw[j] : "<< _raw[j]<<endl;

             cout << "***********************" << endl;*/
        }
    }

    else
    {
        arr[i] = 1;
        DFS(i + 1, number, target, arr, _raw);
        arr[i] = 0;
        DFS(i + 1, number, target, arr, _raw);
        arr[i] = -1;
        DFS(i + 1, number, target, arr, _raw);
    }
}


