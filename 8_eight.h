#pragma once
#include<iostream>
#include <fstream>
#include<vector>


using namespace std;

int eight()
{
    //ifstream cin; //cin�� �ܼ��Է��� ��ü-1
    //cin.open("Input_data.txt"); //cin�� �ܼ��Է��� ��ü-2

    char input[101] = { 0 };
    cin >> input;

    int i = 0;
    int answer = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '(')
            answer++;
        else if (input[i] == ')')
            answer--;

        if (answer < 0)
        {
            cout << "NO" << endl;
            return 0;
        }

    }

    if (answer == 0)
    {
        cout << "YES";
    }

    else
    {
        cout << "NO";
    }




    return 0;
}