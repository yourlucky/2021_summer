#pragma once
#include<iostream>
#include<fstream>


using namespace std;

int digit_sum(int x);

int ten()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int x;
    cin >> x;

    cout << digit_sum(x) << endl;


    return 0;
}

int digit_sum(int x)
{
    int number;
    int max_sum = 0;
    int sum = 0;
    int answer = 0;
    int k_number = 0;

    for (int i = 1; i <= x; i++)
    {
        cin >> number;
        //cout << "짜잔" << i<<endl;

        k_number = number;
        sum = 0;

        sum += number / 10000000;
        number %= 10000000;

        sum += number / 1000000;
        number %= 1000000;

        sum += number / 100000;
        number %= 100000;

        sum += number / 10000;
        number %= 10000;

        sum += number / 1000;
        number %= 1000;

        sum += number / 100;
        number %= 100;

        sum += number / 10;
        number %= 10;

        sum += number;


        if (max_sum < sum)
        {
            answer = k_number;
            max_sum = sum;
        }
        if (max_sum == sum)
        {
            if (k_number > answer)
            {
                answer = k_number;
            }
        }

        //cout << "answer : " << answer << " sum :" << sum << endl;

    }


    return answer;
}