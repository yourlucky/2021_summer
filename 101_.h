#pragma once
#include<bits/stdc++.h>

using namespace std;


int _map[31][1001];


struct My
{
	int value;
	int time;

	My(int v, int t)
	{
		value = v;
		time = t;
	}
};


int onehundredone()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int number;
	cin >> number;


	int t_time;
	cin >> t_time;


	vector<My> _data;
	int answer[101][1001];

	int d1;
	int d2;
	for (int i = 0; i < number; i++)
	{
		cin >> d1;
		cin >> d2;
		_data.push_back(My(d1, d2));
	}


	for (int i = 0; i < number; i++)
	{
		int count = 1;
		for (int j = 0; j <= t_time; j++)
		{
			if (j == 0)
			{
				answer[i][j] = 0;
			}
			else if (i == 0)
			{
				if (j >= _data[i].time)
				{

					answer[i][j] = _data[i].value;
				}
				else
				{
					answer[i][j] = 0;
				}
			}
			else
			{
				if (j >= _data[i].time)
					answer[i][j] = max(answer[i - 1][j], answer[i - 1][j - _data[i].time] + _data[i].value);
				else
					answer[i][j] = answer[i - 1][j];
			}

		}
	}

	//for (int i = 0; i <number ; i++)
	//{
	//	for (int j = 1; j <= t_time; j++)
	//	{
	//		cout <<setw(2) <<answer[i][j] << "  ";

	//	}
	//	cout << endl;
	//}

	cout << answer[number - 1][t_time] << endl;


	return 0;
}
