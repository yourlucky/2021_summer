#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<queue>


using namespace std;

int _data[9][9] = { 0 };

int _x[4] = { -1, 0 ,0, 1 };
int _y[4] = { 0, -1, 1, 0 };

int _min = 2147000000;

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



int eightyeight()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2


	queue<BF> sQ;//stack

	for (int i = 0; i <= 8; i++)
	{
		for (int j = 0; j <= 8; j++)
		{
			_data[i][j] = 1;
		}
	}


	int n1;
	for (int i = 1; i <= 7; i++)
	{
		for (int j = 1; j <= 7; j++)
		{
			cin >> n1;
			_data[i][j] = n1;
		}
	}

	//for (int i = 0; i <= 8; i++)
	//{
	//	for (int j = 0; j <= 8; j++)
	//	{
	//		cout << _data[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	sQ.push(BF(1, 1, 0));
	_data[1][1] = 1;

	while (!sQ.empty())
	{
		BF tmp = sQ.front();
		if (tmp.x == 7 && tmp.y == 7)
		{
			if (tmp.value < _min)
				_min = tmp.value;
		}
		sQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int xx = tmp.x + _x[i];
			int yy = tmp.y + _y[i];

			if (_data[xx][yy] == 0)
			{
				sQ.push(BF(xx, yy, tmp.value + 1));
				_data[xx][yy] = 1;
			}
		}

	}

	cout << _min << endl;



	return 0;
}


