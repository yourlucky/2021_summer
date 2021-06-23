#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int fourty()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int size_one = 0;
    cin >> size_one;

    vector<int> one;

    int data = 0;
    for (int i = 0; i < size_one; i++)
    {
        cin >> data;
        one.push_back(data);
    }

    int size_two = 0;
    cin >> size_two;

    vector<int> two;

    for (int i = 0; i < size_two; i++)
    {
        cin >> data;
        two.push_back(data);
    }


    int one_ptr = 0;
    int two_ptr = 0;

    vector<int> answer;

    sort(one.begin(), one.end());
    sort(two.begin(), two.end());

    while (one_ptr < size_one && two_ptr < size_two)
    {
        if (one[one_ptr] > two[two_ptr])
            two_ptr++;
        else if (one[one_ptr] < two[two_ptr])
            one_ptr++;
        else if (one[one_ptr] == two[two_ptr])
        {
            answer.push_back(one[one_ptr]);
            one_ptr++;
            two_ptr++;
        }
    }

    for (int j : answer)
    {
        cout << j << " ";
    }

    return 0;
}
