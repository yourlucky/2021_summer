#pragma once

#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;

int sixteen()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int answer = 0;

    string word_1;
    string word_2;

    getline(cin, word_1);
    getline(cin, word_2);


    int arr_1[128] = { 0 };
    int arr_2[128] = { 0 };


    //for (int i = 0; i < word_1.size(); i++)
    for (int i = 0; word_1[i] != '\0'; i++)
        arr_1[word_1[i]]++;

    for (int i = 0; i < word_2.size(); i++)
        arr_2[word_2[i]]++;

    if (word_1.size() != word_2.size())
    {
        cout << "NO" << endl;
        return 0;
    }


    //for (int i = 0; i < 128; i++)
    //{
    //    if (arr_1[i] != 0)
    //        cout << "arr_1[" << i << "] : " << arr_1[i] << endl;
    //}

    for (int i = 0; i < 128; i++)
    {
        if (arr_1[i] != arr_2[i])
        {
            cout << "NO";
            return 0;
        }

    }

    cout << "YES";

    return 0;
}


