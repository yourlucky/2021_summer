#pragma once
#include<bits/stdc++.h>

using namespace std;

struct Edge
{
	int from;
	int to;
	int cost;

	Edge(int f, int t, int c)
	{
		from = f;
		to = t;
		cost = c;
	}


	bool operator < (const Edge& b) const {
		return cost > b.cost;
	}
};


int eightyone()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int node;
	cin >> node;

	int edge_n;
	cin >> edge_n;


	vector <Edge> _data;
	int _answer[25];

	for (int i = 0; i < 25; i++)
		_answer[i] = 2147000000;

	int d1;
	int d2;
	int d3;
	for (int i = 0; i < edge_n; i++)
	{
		cin >> d1 >> d2 >> d3;

		_data.push_back(Edge(d1, d2, d3));
	}

	int start;
	cin >> start;

	int goal;
	cin >> goal;

	_answer[start] = 0;


	for (int j = 1; j <= node; j++)
	{
		for (int i = 0; i < edge_n; i++)
		{
			int n_from = _data[i].from;
			int n_to = _data[i].to;
			int n_cost = _data[i].cost;

			if (_answer[n_from] != 2147000000 && _answer[n_to] > _answer[n_from] + n_cost)
			{
				_answer[n_to] = _answer[n_from] + n_cost;
			}
		}
	}

	for (int i = 0; i < edge_n; i++)
	{
		int n_from = _data[i].from;
		int n_to = _data[i].to;
		int n_cost = _data[i].cost;

		if (_answer[n_from] != 2147000000 && _answer[n_to] > _answer[n_from] + n_cost)
		{
			cout << "-1" << endl;
			return 0;
		}
	}


	cout << _answer[goal] << endl;

	return 0;
}

