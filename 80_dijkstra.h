#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

struct Edge
{
	int to;
	int cost;
	Edge(int t, int c)
	{
		to = t;
		cost = c;
	}

	bool operator < (const Edge& b) const {
		return cost > b.cost;
	}
};


int eighty()
{

	ifstream cin; //cin의 콘솔입력을 대체-1
	cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int v = 0;
	cin >> v;

	int e = 0;
	cin >> e;

	priority_queue<Edge> pQ;

	vector < pair<int, int> > data[21];
	int cost[25];
	for (int i = 2; i < 25; i++)
	{
		cost[i] = 2147000000;
	}
	cost[0] = { 0 };
	cost[1] = { 0 };

	int n1;
	int n2;
	int n3;
	for (int i = 0; i < e; i++)
	{
		cin >> n1;
		cin >> n2;
		cin >> n3;

		data[n1].push_back(make_pair(n2, n3));
	}


	data[0].push_back(make_pair(1, 0));

	int count = 0;
	int answer = 0;

	pQ.push(Edge(1, 0));

	while (!pQ.empty())
	{
		Edge tmp = pQ.top();
		int l = tmp.to;
		int c = tmp.cost;
		pQ.pop();

		if (c > cost[l]) continue;
		for (int j = 0; j < data[l].size(); j++)
		{
			/*cout << j << endl;
				cout << "data[i][j].first : " << data[i][j].first << endl;
				cout << "cost[data[i][j].first] : " << cost[data[i][j].first] << endl;
				cout << "cost[i]  :  " << cost[i] <<endl;
				cout << "data[i][j].second  :  " << data[i][j].second << endl;*/

			int next = data[l][j].first;
			int next_cost = data[l][j].second + c;

			if (cost[next] > next_cost)
			{
				cost[next] = next_cost;
				pQ.push(Edge(next, next_cost));
			}
		}




	}

	for (int i = 2; i <= v; i++)
	{
		cout << i << " : ";
		if (cost[i] == 2147000000)
			cout << "impossible" << endl;
		else
			cout << cost[i] << endl;
	}

	return 0;
}

