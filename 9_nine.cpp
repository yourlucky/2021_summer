#include<iostream>
#include <fstream>
#include<vector>


using namespace std;

int nine()
{
    //ifstream cin; //cin�� �ܼ��Է��� ��ü-1
    //cin.open("Input_data.txt"); //cin�� �ܼ��Է��� ��ü-2

    int a;
    cin >> a;
    int k = 1;

    int answer[50001] = { 0 };

    for (int i = 1; i <= a; i++)
    {
        for (int k = i; k <= a; k = k + i)
        {
            answer[k]++;
        }
    }


    for (int i = 1; i <= a; i++)
    {
        cout << answer[i] << " ";
    }

    return 0;
}