#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int thirtyeight()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int memory_size = 0;
    cin >> memory_size;

    vector<int> memory(memory_size);
    vector<int> answer(memory_size, 0);

    int number = 0;
    for (int i = 0; i < memory_size; i++)
    {
        cin >> number;
        memory[i] = number;
    }

    int count = 0;
    int location = 0;
    for (int i = 1; i < memory_size + 1; i++)
    {
        count = 0;
        location = memory.at(i - 1);
        for (int j = 0; j < memory_size; j++)
        {
            if (count == location && answer.at(j) == 0)
            {
                answer.at(j) = i;
                break;
            }
            if (answer.at(j) == 0)
                count++;
        }
    }

    for (int k : answer)
        cout << k << " ";

    return 0;
}

