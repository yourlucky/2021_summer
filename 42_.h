#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int size = 0;
    cin >> size;

    int value = 0;
    cin >> value;

    vector<int> _array;

    int number = 0;
    for (int i = 0; i < size; i++)
    {
        cin >> number;
        _array.push_back(number);
    }

    int count = 1;
    for (int i : _array)
    {
        if (i < value)
            count++;
    }

    cout << count << endl;

    return 0;
}
