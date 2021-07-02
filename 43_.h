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

    int number_ = 0;
    cin >> number_;

    int cd_ = 0;
    cin >> cd_;

    vector<int> songlist_;

    int time_ = 0;
    for (int i = 0; i < number_; i++)
    {
        cin >> time_;
        songlist_.push_back(time_);
    }



    int total = 0;
    for (int i : songlist_)
        total += i;

    int left = 1;
    int right = total;
    int mid = (left + right) / 2;

    int count, sum, answer = 2147000000;

    do
    {
        count = 1;
        sum = 0;

        for (int i : songlist_)
        {
            if (sum + i <= mid)
                sum += i;

            else
            {
                count++;
                sum = i;
            }
        }

        if (count > cd_)
            left = mid;

        else
        {
            right = mid;
            if (answer > mid)
                answer = mid;
        }

        mid = (left + right) / 2;

    } while (mid != left && mid != right);

    cout << answer << endl;

    return 0;
}
