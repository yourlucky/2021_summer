#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>

void pop(int& ptr);
void push(int(&answer)[320], int& ptr, const int& num);

using namespace std;

int fiftyfive()
{
    int number = 0;
    cin >> number;

    int B_ptr = 1;//B도시 출입순서

    int array_A[320];//A도시 출발순서
    int a = 0;
    for (int i = 1; i <= number; i++)
    {
        cin >> a;
        array_A[i] = a;
    }
    int A_ptr = 1;


    int array_t[320];//교차로
    int T_ptr = -1;//교차로 포인터


    char answer_word[320];
    int w_ptr = 0;

    while (A_ptr != number + 1)
    {
        if (array_A[A_ptr] == B_ptr)
        {
            answer_word[w_ptr++] = 'P';
            answer_word[w_ptr++] = 'O';
            B_ptr++;
            A_ptr++;
        }
        else if (array_t[T_ptr] == B_ptr)
        {
            T_ptr--;
            answer_word[w_ptr++] = 'O';
            B_ptr++;
        }

        else
        {
            push(array_t, T_ptr, array_A[A_ptr]);
            answer_word[w_ptr++] = 'P';
            A_ptr++;
        }

    }

    while (T_ptr != -1)
    {
        if (array_t[T_ptr] == B_ptr)
        {
            T_ptr--;
            answer_word[w_ptr++] = 'O';
            B_ptr++;
        }
        else
        {
            break;
        }

    }


    if (B_ptr == number + 1)
    {
        for (int i = 0; i <= w_ptr - 1; i++)
            cout << answer_word[i];
    }

    else
    {
        cout << "impossible";
    }


    return 0;
}

void push(int(&answer)[320], int& ptr, const int& num)
{
    answer[++ptr] = num;
}