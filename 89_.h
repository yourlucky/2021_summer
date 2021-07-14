#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


struct BF {
	int x;
	int y;
	int value;
	BF(int xx, int yy, int vv)
	{
		x = xx;
		y = yy;
		value = vv;
	}

};


int eightynine()
{



	int _x[4] = { -1,0,0,1 };
	int _y[4] = { 0,1,-1,0 };

	int _max = 0;
	queue<BF> sQ;


	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int m;
	cin >> m;
	int n;
	cin >> n;



	vector < vector<int> > _data;

	for (int i = 0; i <= n + 1; i++)
	{
		vector <int> v1;
		for (int j = 0; j <= m + 1; j++)
		{
			v1.push_back(2);
		}
		_data.push_back(v1);
	}



	int n1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> n1;
			_data[i][j] = n1;
		}
	}



	//for (int i = 0; i <= n + 1; i++)
	//{
	//	for (int j = 0; j <= m + 1; j++)
	//	{
	//		cout << _data[i][j] << " ";
	//	}
	//	cout << endl;
	//}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (_data[i][j] == 1)
				sQ.push(BF(i, j, 0));
		}
	}


	if (sQ.empty())
		cout << "-1";

	else
	{
		while (!sQ.empty())
		{
			BF tmp = sQ.front();
			int x = tmp.x;
			int y = tmp.y;
			sQ.pop();
			if (tmp.value > _max)
			{
				_max = tmp.value;
			}
			for (int i = 0; i < 4; i++)
			{
				int xx = x + _x[i];
				int yy = y + _y[i];
				if (_data[xx][yy] == 0)
				{
					sQ.push(BF(xx, yy, tmp.value + 1));
					_data[xx][yy] = 1;
				}
			}

		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (_data[i][j] == 0)
					_max = -1;
			}
		}

		cout << _max << endl;
	}



	return 0;
}


