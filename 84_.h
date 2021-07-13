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

vector < pair <int, int> > _data;
int big_answer = 0;
int _max = 0;
int last_day = 0;

void DFS(int today);

int eightyfour()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	cin >> last_day;

	int d;
	int v;

	_data.push_back(make_pair(0, 0));
	for (int i = 1; i <= last_day; i++)
	{
		cin >> d;
		cin >> v;
		_data.push_back(make_pair(d, v));
	}



	DFS(1);

	cout << _max << endl;

	return 0;
}

void DFS(int today)
{
	if (today == last_day + 1)
	{
		if (big_answer > _max)
			_max = big_answer;
	}

	else
	{

		int len = _data[today].first;
		int val = _data[today].second;

		if (today + len <= last_day + 1)
		{
			big_answer += val;
			DFS(today + len);
			big_answer -= val;
			DFS(today + 1);
		}
		else
		{
			DFS(today + 1);
		}
	}
}