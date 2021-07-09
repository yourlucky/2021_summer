#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>


using namespace std;

void DFS(int v, int node, int value, int(&visited)[30], vector< pair<int, int> >(&data)[30]);
int min_v = 2147000000;

int sixtyeight()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int node;
	cin >> node;

	int edge;
	cin >> edge;


	vector< pair<int, int> > data[30];

	int from;
	int to;
	int value;

	for (int i = 0; i < edge; i++)
	{
		cin >> from;
		cin >> to;
		cin >> value;
		data[from].push_back(make_pair(to, value));
	}

	int visited[30] = { 0 };
	visited[1] = 1;
	value = 0;
	DFS(1, node, value, visited, data);

	cout << min_v << endl;

	//for (int i = 1; i <= edge; i++)
	//{
	//	if (data[i].size())
	//	{
	//		for (int j = 0; j < data[i].size(); j++)
	//		{
	//			cout << i << " , " << data[i][j].first << " , " << data[i][j].second << endl;
	//		}
	//		
	//	}
	//}


	return 0;
}

void DFS(int v, int node, int value, int(&visited)[30], vector< pair<int, int> >(&data)[30])
{
	if (v == node)
	{
		if (min_v > value)
		{
			min_v = value;
		}
	}
	else
	{
		if (data[v].size())
		{
			for (int j = 0; j < data[v].size(); j++)
			{
				if (visited[data[v][j].first] == 0)
				{
					visited[data[v][j].first] = 1;
					DFS(data[v][j].first, node, value + data[v][j].second, visited, data);
					visited[data[v][j].first] = 0;
				}
			}
		}
	}
}
