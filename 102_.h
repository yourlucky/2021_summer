#pragma once
#include<bits/stdc++.h>

using namespace std;


int onehundredtwo()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int _data[101][101];

	int node;
	cin >> node;

	int edge;
	cin >> edge;


	int d1;
	int d2;
	int d3;


	for (int i = 0; i < edge; i++)
	{
		cin >> d1;
		cin >> d2;
		cin >> d3;

		_data[d1][d2] = d3;
	}

	for (int i = 1; i <= node; i++)
	{
		for (int j = 1; j <= node; j++)
		{
			if (i == j)
				_data[i][j] = 0;

			else if (_data[i][j] == 0)
			{
				_data[i][j] = 5000000;
			}
		}
	}

	for (int k = 1; k <= node; k++)
	{
		for (int i = 1; i <= node; i++)
		{
			for (int j = 1; j <= node; j++)
			{
				_data[i][j] = min(_data[i][j], _data[i][k] + _data[k][j]);
			}
		}
	}



	for (int i = 1; i <= node; i++)
	{
		for (int j = 1; j <= node; j++)
		{
			if (_data[i][j] >= 5000000)
				cout << "M" << " ";
			else
				cout << _data[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

