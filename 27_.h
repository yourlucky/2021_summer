#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void calcu(int numb, int(&answer)[990]);

int twentyseven()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int number = 0;
    cin >> number;

    int answer[990] = { 0 };

    for (int i = 2; i <= number; i++)
    {
        calcu(i, answer);
    }

    cout << number << "! = ";

    for (int i = 2; i < 990; i++)
    {
        if (answer[i] != 0)
        {
            cout << answer[i] << " ";
        }

    }
    return 0;
}

void calcu(int numb, int(&answer)[990])
{
    int denote = 2;

    while (numb > 1)
    {
        if (numb % denote == 0)
        {
            answer[denote]++;
            numb /= denote;
        }
        else
        {
            denote++;
        }

    }

}
