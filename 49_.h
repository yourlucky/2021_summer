#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;



int fourtynine()
{
    ifstream cin;//cin의 콘솔입력을 대체-1
    cin.open("Input_data.txt");//cin의 콘솔입력을 대체-2

    int size = 0;
    cin >> size;



    vector< vector <int> > block_(size, vector<int>(size, 0));
    vector<int> front(size, 0);
    vector<int> side(size, 0);

    int data = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> data;
        front[i] = data;
    }

    for (int i = 0; i < size; i++)
    {
        cin >> data;
        side[i] = data;
    }




    for (int i = 0; i < size; i++)
    {
        data = front[i];
        for (int j = 0; j < size; j++)
        {
            block_[j][i] = data;
        }
    }

    for (int i = 0; i < size; i++)
    {
        data = side[i];
        for (int j = 0; j < size; j++)
        {
            if (block_[i][j] > data)
                block_[i][j] = data;
        }
    }


    int answer = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            answer += block_[i][j];
        }
    }


    cout << answer << endl;

    return 0;
}

