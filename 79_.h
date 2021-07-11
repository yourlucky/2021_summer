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


struct Edge {

	int to;
	int cost;

	Edge(int n1, int c)
	{
		to = n1;
		cost = c;
	}

	bool operator < (const Edge& b) const
	{
		return cost > b.cost;
	}

};

int seventynine()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int v = 0;
	cin >> v;

	int e = 0;
	cin >> e;

	vector < Edge > data[30];
	priority_queue<Edge> pQ;
	int visited[31] = { 0 };

	int n1;
	int n2;
	int n3;

	data[0].push_back(Edge(1, 0));



	for (int i = 0; i < e; i++)
	{
		cin >> n1;
		cin >> n2;
		cin >> n3;

		data[n1].push_back(Edge(n2, n3));
		data[n2].push_back(Edge(n1, n3));
	}


	int ee = 0;
	int answer = 0;
	pQ.push(data[0][0]);

	while (ee != v)
	{
		Edge tmp = pQ.top();
		pQ.pop();


		if (visited[tmp.to] == 0)
		{
			//cout << ee << " : 도착점 : " << tmp.to << " , cost : " << tmp.cost << endl;
			answer += tmp.cost;
			ee++;
			visited[tmp.to] = 1;

			for (int i = 0; i < data[tmp.to].size(); i++)
			{
				pQ.push(data[tmp.to][i]);
			}
		}

	}
	cout << answer << endl;

	return 0;
}

