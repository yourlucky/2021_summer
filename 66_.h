#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
void dfs(int _from, int _to);

int big_answer = 0;
int data_[30][30];
int data_count[30] = { 0 };
int visited[30] = { 0 };


int sixtysix()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int node;
    cin >> node;

    int edge;
    cin >> edge;

    vector<int> path;

    int from_data;
    int to_data;
    for (int i = 0; i < edge; i++)
    {
        cin >> from_data;
        cin >> to_data;
        data_[from_data][data_count[from_data]++] = to_data;
    }

    visited[1] = 1;
    dfs(1, node);

    cout << big_answer++;
    return 0;
}

void dfs(int _from, int _to)
{
    if (_from == _to)
    {
        big_answer++;
    }

    else
    {
        for (int j = 0; j < data_count[_from]; j++)
        {
            if (visited[data_[_from][j]] == 0)
            {
                visited[data_[_from][j]] = 1;
                dfs(data_[_from][j], _to);
                visited[data_[_from][j]] = 0;
            }
        }
    }
}
