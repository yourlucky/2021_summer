#pragma once
#include<bits/stdc++.h>
#include<queue>

using namespace std;

int onehundredfour()
{

	ifstream cin; //cin의 콘솔입력을 대체-1
	cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	vector <int> _data[51];
	int _input[51] = { 0 };
	int _visited[51] = { 0 };

	queue<int> yoon;


	int node;
	cin >> node;

	int edge;
	cin >> edge;


	int d1;
	int d2;
	for (int i = 1; i <= edge; i++)
	{
		cin >> d1;
		cin >> d2;

		_data[d1].push_back(d2);
		_input[d2]++;
	}

	while (yoon.size() != node)
	{
		for (int i = 1; i <= node; i++)
		{
			if (_input[i] == 0 && _visited[i] == 0)
			{
				yoon.push(i);
				_visited[i] = 1;

				for (int j = 0; j < _data[i].size(); j++)
				{
					_input[_data[i][j]]--;
				}
			}
		}
	}

	while (!yoon.empty())
	{
		cout << yoon.front() << " ";
		yoon.pop();
	}


	return 0;
}

