#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int sixtynine()
{

	ifstream cin; //cin의 콘솔입력을 대체-1
	cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int node = 7;
	int edge = 6;

	vector<int> data[30];

	int from;
	int to;

	for (int i = 1; i <= edge; i++)
	{
		cin >> from;
		cin >> to;

		data[from].push_back(to);
	}

	int visited[30] = { 0 };

	queue<int> yoon;
	yoon.push(1);

	int x;
	while (!yoon.empty())
	{

		x = yoon.front();

		if (data[x].size())
		{
			for (int i = 0; i < data[x].size(); i++)
			{
				if (visited[data[x][i]] == 0)
				{
					//cout << data[x][i] << endl;
					visited[data[x][i]] = 1;
					yoon.push(data[x][i]);
				}
			}
		}
		cout << x << " ";
		yoon.pop();
	}

	return 0;
}
