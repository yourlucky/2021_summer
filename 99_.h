#pragma once
#include<bits/stdc++.h>

using namespace std;


struct package
{
	int weight;
	int value;

	package(int w, int v)
	{
		weight = w;
		value = v;
	}
	bool operator < (const package b)const
	{
		return weight > b.weight;
	}
};

int _map[31][1001];


int nightynine()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int item = 0;
	cin >> item;

	int limit_l = 0;
	cin >> limit_l;


	vector< package > _data;
	int d1;
	int d2;

	for (int i = 0; i < item; i++)
	{
		cin >> d1;
		cin >> d2;
		_data.push_back(package(d1, d2));
	}


	for (int i = 0; i < item; i++)
	{

		for (int j = 0; j <= limit_l; j++)
		{
			int new_weight = _data[i].weight;
			int new_value = _data[i].value;

			if (j == 0)
			{
				_map[i][j] = 0;
			}

			else if (i == 0 && j < new_weight)
			{
				_map[0][j] = 0;
			}
			else if (i == 0 && j >= new_weight)
			{
				_map[0][j] = _map[0][j - new_weight] + new_value;
			}

			else
			{

				if (j < new_weight)
				{
					_map[i][j] = _map[i - 1][j];
				}

				else if (j >= new_weight)
				{
					_map[i][j] = max(_map[i - 1][j], _map[i][j - new_weight] + new_value);
				}
			}
		}
	}



	//for (int i = 0; i < item; i++)
	//{
	//	for (int j = 0; j <= limit_l; j++)
	//	{
	//		cout << _map[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	//cout << "**********************" << endl;


	cout << _map[item - 1][limit_l];



	return 0;
}
