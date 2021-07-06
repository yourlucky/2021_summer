#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>


using namespace std;

void pop(int& ptr);
void push(int(&answer)[501], int& ptr, const int& num);

int fiftythree()
{
    int number = 0;
    cin >> number;

    int de_number = 0;
    cin >> de_number;

    int answer[501];
    int ptr = -1;

    char sign[20] = { '0',49,50,51,52,53,54,55,56,'9','A','B','C','D','E','F','G','H','I','G' };


    while (number >= de_number)
    {
        push(answer, ptr, number % de_number);
        number /= de_number;
    }

    push(answer, ptr, number);


    while (ptr != -1)
    {
        cout << sign[answer[ptr]];
        pop(ptr);
    }



    return 0;
}


void pop(int& ptr)
{
    ptr--;
}

void push(int(&answer)[501], int& ptr, const int& num)
{
    answer[++ptr] = num;
}