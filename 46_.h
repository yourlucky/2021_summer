#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int fourtysix()
{
    //ifstream cin; //cin의 콘솔입력을 대체-1
    //cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

    int task_number = 0;
    cin >> task_number;

    vector<int> tasks;
    int number = 0;

    tasks.push_back(0);

    for (int i = 0; i < task_number; i++)
    {
        cin >> number;
        tasks.push_back(number);
    }

    int last_time = 0;
    cin >> last_time;

    int answer = 0;

    int sum = 0;
    for (int i : tasks)
        sum += i;

    if (sum <= last_time)
    {
        answer = -1;
        cout << answer << endl;
        return 0;
    }


    int time = 0;
    int location = 0;


    while (time <= last_time)
    {
        location++;
        if (location > task_number)
            location = 1;

        if (tasks[location] == 0)
            continue;

        tasks[location]--;
        time++;
        answer = location;
    }

    cout << answer << endl;

    return 0;
}