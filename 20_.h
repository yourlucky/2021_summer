#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>

using namespace std;


char judge(int x, int y);

int twenty()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int count;
    cin >> count;

    int A_x[100] = { 0 };
    int B_x[100] = { 0 };

    for (int i = 0; i < count; i++)
        cin >> A_x[i];

    for (int i = 0; i < count; i++)
        cin >> B_x[i];

    for (int i = 0; i < count; i++)
        cout << judge(A_x[i], B_x[i]) << endl;


    return 0;
}


char judge(int x, int y)
{
    if (x == y)
        return 'D';

    switch (x) {
    case 1:
        if (y == 2)
            return 'B';
        else if (y == 3)
            return 'A';
    case 2:
        if (y == 1)
            return 'A';
        else if (y == 3)
            return 'B';
    case 3:
        if (y == 1)
            return 'B';
        else if (y == 2)
            return 'A';

    default:
        cout << "코딩 좀 잘해라" << endl;
    }

    return 'K';

}
