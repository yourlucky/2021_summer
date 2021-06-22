#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int scale(vector<int>number);


int main()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    string carbon;
    getline(cin, carbon);


    vector<int>number_one;
    vector<int>number_two;


    int location = 1;
    while (carbon[location] != 'H')
    {
        number_one.push_back(carbon[location] - 48);
        location++;
    }


    location++;
    while (carbon[location] != '\0')
    {
        number_two.push_back(carbon[location] - 48);
        location++;
    }


    int c_weight = scale(number_one) * 12;
    int h_weight = scale(number_two) * 1;


    cout << c_weight + h_weight;


    return 0;
}


int scale(vector<int>number)
{
    int weight = 0;
    int k = 0;

    if (number.size() >= 1)
    {
        for (int j = number.size() - 1; j >= 0; j--)
        {
            weight += (number.at(k) * pow(10, j));
            k++;
        }
    }
    else
        weight = 1;


    return weight;
}