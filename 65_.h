#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
int big_answer = 0;

void dfs(int i, int j, int(&_map)[9][9]);

int sixtyfive()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int node = 7;
    int _map[9][9];

    int data;
    for (int i = 0; i < node + 2; i++)
    {
        for (int j = 0; j < node + 2; j++)
        {
            if (i == 0 || j == 0)
                _map[i][j] = 1;

            else if (i == 8 || j == 8)
                _map[i][j] = 1;

            else
            {
                cin >> data;
                _map[i][j] = data;
            }
        }
    }

    _map[1][1] = 1;
    dfs(1, 1, _map);
    cout << big_answer++;

    return 0;
}

void dfs(int i, int j, int(&_map)[9][9])
{
    if (i == 7 && j == 7)
    {
        big_answer++;
        exit;
    }
    if (i == 8 || j == 8 || i == 0 || j == 0)
        exit;

    else
    {
        //cout <<"( " << i <<" , "<<j<<" )" << endl;
        if (_map[i - 1][j] == 0)
        {
            _map[i - 1][j] = 1;
            dfs(i - 1, j, _map);
            _map[i - 1][j] = 0;
        }

        if (_map[i + 1][j] == 0)
        {
            _map[i + 1][j] = 1;
            dfs(i + 1, j, _map);
            _map[i + 1][j] = 0;
        }

        if (_map[i][j - 1] == 0)
        {
            _map[i][j - 1] = 1;
            dfs(i, j - 1, _map);
            _map[i][j - 1] = 0;
        }

        if (_map[i][j + 1] == 0)
        {
            _map[i][j + 1] = 1;
            dfs(i, j + 1, _map);
            _map[i][j + 1] = 0;
        }

    }

}



