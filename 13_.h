#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<math.h>


using namespace std;


int Thirteen()
{
    //ifstream cin; //cin�� �ܼ��Է��� ��ü-1
    //cin.open("Input_data.txt"); //cin�� �ܼ��Է��� ��ü-2

    int number[10] = { 0 };

    string line;
    getline(cin, line);


    for (int i = 0; i < line.size(); i++)
    {
        number[int(line[i] - 48)]++;
    }

    int max = -1;
    int answer = -1;

    for (int i = 0; i <= 9; i++)
    {

        if (number[i] >= max)
        {
            max = number[i];
            answer = i;
        }
    }

    cout << answer << endl;

    return 0;
}

