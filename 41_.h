#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int fourtyone()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int value = 0;
    cin >> value;

    int a = 0, b = 2;
    int answer = 0;

    do
    {
        a = 0;
        for (int i = 1; i <= b; i++)
        {
            a += i;
        }

        if ((value - a) % b == 0)
        {
            int n = (value - a) / b;

            for (int i = 1; i < b; i++)
            {
                cout << i + n << " + ";
            }
            cout << b + n << " = " << value << endl;

            answer++;
        }

        b++;


    } while (a < value);


    cout << answer << endl;

    return 0;
}
