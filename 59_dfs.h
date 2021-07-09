#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<stack>


using namespace std;


int fiftynine_one()
{
    stack<int> yoon;//stack
    vector<int> a[8];//기초 자료
    int visited[8] = { 0 };//방문 여부



    //기본 연결도
    a[1].push_back(2);
    a[1].push_back(3);

    a[2].push_back(4);
    a[2].push_back(5);

    a[3].push_back(6);
    a[3].push_back(7);



    yoon.push(1);


    while (!yoon.empty())
    {
        int x = yoon.top();
        yoon.pop();
        cout << x << endl;

        for (int i = a[x].size() - 1; i >= 0; i--)
        {
            if (!visited[a[x][i]])
            {
                yoon.push(a[x][i]);
            }
        }
    }


    return 0;
}


