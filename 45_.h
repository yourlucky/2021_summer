#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int fourtyfive()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int total = 0;
    cin >> total;

    int num = 0;
    cin >> num;

    vector<int> prince;

    int sum = 0;

    for (int i = 0; i < total; i++)
    {
        prince.push_back(1);
    }

    for (int i : prince)
        sum += i;

    int ptr = 0;
    int count = 0;


    while (sum != 1)
    {
        if (ptr >= prince.size())
        {
            ptr = ptr % prince.size();
        }

        if (prince[ptr] == 1)
        {
            if (count == num - 1)
            {
                prince[ptr] = 0;
                count = 0;
            }
            else
            {
                count++;
            }
            ptr++;
        }

        else
        {
            ptr++;
        }

        sum = 0;

        for (int i : prince)
        {
            sum += i;
        }
    }

    int k = 0;

    for (int i : prince)
    {
        k++;
        if (i == 1)
            cout << k << endl;
    }



    return 0;
}