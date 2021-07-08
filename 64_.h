#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
void dfs(int _from, int node, vector< vector<int> >& matrix, int(&visited)[30], vector<int> path);

int big_answer = 0;


int sixtyfour()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int node;
    cin >> node;

    int edge;
    cin >> edge;

    vector<vector<int>> data;
    int visited[30] = { 0 };
    vector<int> path;


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
    for (int i = 0; i < edge; i++)
    {
        cin >> from;
        cin >> to;
        data[from][to] = 1;

    }

    visited[1] = 1;
    dfs(1, node, data, visited, path);

    cout << big_answer++;
    return 0;
}

void dfs(int _from, int node, vector< vector<int> >& data, int(&visited)[30], vector<int> path)
{
    visited[_from] = 1;
    path.push_back(_from);


    if (_from == node)
    {
        big_answer++;
        for (int k : path)
        {
            cout << k << " ";
        }
        cout << endl;
    }

    else {
        for (int i = 1; i <= node; i++)
        {
            if (data[_from][i] == 1 && visited[i] == 0)
            {
                dfs(i, node, data, visited, path);
            }
        }
    }
    visited[_from] = 0;
}



