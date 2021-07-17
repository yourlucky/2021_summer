#pragma once
#include<bits/stdc++.h>

using namespace std;


int hundredthree()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int _data[51][51];
	int _score[51];

	int number;
	cin >> number;

	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= number; j++)
		{
			_data[i][j] = 5000;
		}
	}


	int d1 = 0;
	int d2 = 0;

	while (d1 != -1 || d2 != -1)
	{
		cin >> d1;
		cin >> d2;

		_data[d1][d2] = 1;
		_data[d2][d1] = 1;

	}


	for (int k = 1; k <= number; k++)
	{
		for (int i = 1; i <= number; i++)
		{
			for (int j = 1; j <= number; j++)
			{
				_data[i][j] = min(_data[i][j], _data[i][k] + _data[k][j]);
			}
		}
	}

	int t_min = 2147000000;
	for (int i = 1; i <= number; i++)
	{
		_score[i] = 0;
		for (int j = 1; j <= number; j++)
		{
			_score[i] = max(_score[i], _data[i][j]);
		}
		t_min = min(_score[i], t_min);
	}





	vector<int> president;

	for (int i = 0; i <= number; i++)
	{
		if (_score[i] == t_min)
		{
			president.push_back(i);
		}
	}


	cout << t_min << " " << president.size() << endl;

	for (int i = 0; i < president.size(); i++)
	{
		cout << president[i] << " ";
	}

	return 0;
}

