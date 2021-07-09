#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>


using namespace std;


int fiftynine_two()
{
    queue<int> q;//stack
    vector<int> a[8];//기초 자료
    int visited[8] = { 0 };//방문 여부



    //기본 연결도
    a[1].push_back(2);
    a[1].push_back(3);

    a[2].push_back(4);
    a[2].push_back(5);

    a[3].push_back(6);
    a[3].push_back(7);



    q.push(1);


    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << endl;

        for (int i = 0; i < a[x].size(); i++)
        {
            if (!visited[a[x][i]])
            {
                q.push(a[x][i]);
            }
        }
    }


    return 0;
}