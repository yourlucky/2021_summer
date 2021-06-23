#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int thirtysix()
{
    ifstream cin; //cin의 콘솔입력을 대체-1
    cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int number_size = 0;
    cin >> number_size;

    vector<int> box;
    int input;

    for (int i = 0; i < number_size; i++)
    {
        cin >> input;
        box.push_back(input);
    }

    int key = 0;
    int j = 0;
    for (int i = 1; i < number_size; i++)
    {
        key = box[i];
        j = i - 1;
        while (j >= 0 && box[j] > key)
        {
            box[j + 1] = box[j];
            j--;
        }
        box[j + 1] = key;

    }

    for (int k : box)
        cout << k << " ";

    return 0;
}

