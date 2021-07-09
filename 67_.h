#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
void dfs(int _from, int node, vector< vector<int> >& matrix, int(&visited)[30]);


int value = 0;
int min_v = 2147000000;

int sixtyseven()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int node;
    cin >> node;

    int edge;
    cin >> edge;

    vector<vector<int>> data;
    int visited[30] = { 0 };


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

    visited[1] = 1;
    dfs(1, node, data, visited);

    cout << min_v;
    return 0;
}

void dfs(int _from, int node, vector< vector<int> >& data, int(&visited)[30])
{
    if (_from == node)
    {
        if (value < min_v)
            min_v = value;
    }

    else {
        for (int i = 1; i <= node; i++)
        {
            if (data[_from][i] != 0 && visited[i] == 0)
            {
                visited[_from] = 1;
                value += data[_from][i];
                dfs(i, node, data, visited);
                value -= data[_from][i];
                visited[_from] = 0;
            }
        }
    }

}


