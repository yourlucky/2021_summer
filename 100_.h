#pragma once
#include<bits/stdc++.h>

using namespace std;


int _map[31][1001];


int onehundred()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int number;
	cin >> number;

	vector<int> _data;
	int answer[101][501];

	int d1;
	for (int i = 0; i < number; i++)
	{
		cin >> d1;
		_data.push_back(d1);
	}

	int target;
	cin >> target;


	sort(_data.begin(), _data.end());


	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j <= target; j++)
		{
			if (j == 0)
			{
				answer[i][j] = 0;
			}
			else if (i == 0)
			{
				if (j % _data[i] == 0)
				{
					answer[i][j] = j / _data[i];
				}
				else
				{
					answer[i][j] = 2147000000;
				}
			}
			else
			{
				if (j - _data[i] >= 0)
					answer[i][j] = min(answer[i - 1][j], answer[i][j - _data[i]] + 1);

				else
					answer[i][j] = answer[i - 1][j];
			}

		}
	}

	//for (int i = 0; i < number; i++)
	//{
	//	for (int j = 1; j <= target; j++)
	//	{
	//		cout <<setw(2) <<answer[i][j] << "  ";

	//	}
	//	cout << endl;
	//}

	cout << answer[number - 1][target] << endl;


	return 0;
}
