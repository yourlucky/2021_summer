#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
void Merge(int i, int number, int(&_raw)[101]);

int big_answer = 0;

int sixtythree()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int node;
    cin >> node;

    int edge;
    cin >> edge;

    vector<vector<int>> data;
    vector<vector<int>> answer;

    for (int i = 0; i < node + 1; i++)
    {
        vector<int> v1;
        for (int j = 0; j < node + 1; j++)
        {
            v1.push_back(0);
        }
        data.push_back(v1);
    }
    int from;
    int to;
    int value;
    for (int i = 0; i < edge; i++)
    {
        cin >> from;
        cin >> to;
        cin >> value;

        data[from][to] = value;

    }

    for (int i = 1; i <= node; i++)
    {
        for (int j = 1; j <= node; j++)
        {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

}
