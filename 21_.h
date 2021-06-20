#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;



int twentyone()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int A_x[10] = { 0 };
    int B_x[10] = { 0 };
    char R_x[10] = { 0 };

    for (int i = 0; i < 10; i++)
        cin >> A_x[i];

    for (int i = 0; i < 10; i++)
        cin >> B_x[i];

    for (int i = 0; i < 10; i++)
    {
        if (A_x[i] > B_x[i])
            R_x[i] = 'A';

        else if (A_x[i] < B_x[i])
            R_x[i] = 'B';

        else
            R_x[i] = 'D';
    }

    int a_point = 0;
    int b_point = 0;

    for (int i = 0; i < 10; i++)
    {
        if (R_x[i] == 'A')
            a_point += 3;
        else if (R_x[i] == 'B')
            b_point += 3;
        else
        {
            a_point++;
            b_point++;
        }
    }

    cout << a_point << " " << b_point << endl;

    if (a_point > b_point)
        cout << "A" << endl;

    else if (b_point > a_point)
        cout << "B" << endl;

    else
    {
        int a_max = -1;
        int b_max = -1;

        for (int i = 0; i < 10; i++)
        {
            if (R_x[i] == 'A')
                a_max = i;
            if (R_x[i] == 'B')
                b_max = i;
        }

        if (a_max > b_max)
            cout << "A" << endl;

        else if (a_max < b_max)
            cout << "B" << endl;

        else
            cout << "D" << endl;

    }

    return 0;
}
