#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

int thirtyfour()
{
    ifstream cin; //cin의 콘솔입력을 대체-1
    cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int number_size = 0;
    cin >> number_size;

    vector<int> box;
    int input;

    while (cin >> input)
        box.push_back(input);

    int temp = 0;
    for (int i = 0; i < number_size - 1; i++)
    {
        for (int j = 0; j < number_size - i - 1; j++)
            if (box[j] > box[j + 1])
            {
                temp = box[j];
                box[j] = box[j + 1];
                box[j + 1] = temp;
            }

    }
    for (int k : box)
    {
        cout << k << " ";
    }


    return 0;
}

