#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>


using namespace std;

int thirtyfive()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int number_size = 0;
    cin >> number_size;

    vector<int> box;
    int input;

    for (int i = 0; i < number_size; i++)
    {
        cin >> input;
        box.push_back(input);
    }

    vector<int> box_negative;
    vector<int> box_positive;



    for (int i = 0; i < number_size; i++)
    {
        if (box[i] > 0)
            box_positive.push_back(box[i]);

        if (box[i] < 0)
            box_negative.push_back(box[i]);
    }

    for (int d : box_negative)
    {
        cout << d << " ";
    }

    for (int d : box_positive)
    {
        cout << d << " ";
    }


    return 0;
}

