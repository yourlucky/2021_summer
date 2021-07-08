#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;
void Merge(int i, int number, int(&_raw)[101]);

int big_answer = 0;

int sixtytwo()
{
    ifstream cin; //cin의 콘솔입력을 대체-1
    cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int number;
    cin >> number;

    int _raw[101];
    int data;
    for (int i = 1; i <= number; i++)
    {
        cin >> data;
        _raw[i] = data;
    }
    Merge(1, number, _raw);

    for (int i = 1; i <= number; i++)
        cout << _raw[i] << ", ";

    return 0;
}

void Merge(int i, int number, int(&_raw)[101])
{
    int left = i;
    int mid = (i + number) / 2;
    int right = number;

    int _craw[101] = { 0 };

    if (left < right)
    {
        Merge(left, mid, _raw);
        Merge(mid + 1, right, _raw);
    }

    int left_p = i;
    int right_p = mid + 1;
    int total_p = i;

    while (left_p <= mid && right_p <= number)
    {
        if (_raw[left_p] <= _raw[right_p])
            _craw[total_p++] = _raw[left_p++];
        else
            _craw[total_p++] = _raw[right_p++];

    }
    while (left_p <= mid)
    {
        _craw[total_p++] = _raw[left_p++];
    }
    while (right_p <= number)
    {
        _craw[total_p++] = _raw[right_p++];
    }

    for (int j = i; j <= number; j++)
    {
        _raw[j] = _craw[j];
    }


}

