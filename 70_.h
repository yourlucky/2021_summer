#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<queue>
#include<math.h>

using namespace std;

int seventy()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int node;
	cin >> node;

	int edge;
	cin >> edge;

	vector <int> data[30];
	queue<int> yoon;

	int _from;
	int _to;
	for (int i = 0; i < edge; i++)
	{
		cin >> _from;
		cin >> _to;
		data[_from].push_back(_to);
	}

	int count[30] = { 0 };
	count[1] = { 1 };

	yoon.push(1);

	int x = 0;

	while (!yoon.empty())
	{
		x = yoon.front();

		for (int i = 0; i < data[x].size(); i++)
		{
			if (count[data[x][i]] == 0)
			{
				yoon.push(data[x][i]);
				count[data[x][i]] = count[x] + 1;
			}
		}
		yoon.pop();

	}

	for (int i = 2; i <= node; i++)
	{
		cout << i << " : " << count[i] - 1 << endl;
	}


	return 0;
}