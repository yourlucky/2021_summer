#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>
#include<cmath>

using namespace std;

int _size;
int _data[25][25] = { 0 };
int big_answer = 0;
int _count = 2;

int _x[8] = { -1, -1, -1, 0 ,0, 1, 1, 1 };
int _y[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void DFS(int x, int y);

int eightyseven()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	cin >> _size;

	int n1;
	for (int i = 1; i <= _size; i++)
	{
		for (int j = 1; j <= _size; j++)
		{
			cin >> n1;
			_data[i][j] = n1;
		}
	}

	for (int i = 1; i <= _size; i++)
	{
		for (int j = 1; j <= _size; j++)
		{
			if (_data[i][j] == 1)
			{
				DFS(i, j);
				big_answer++;
				_count++;
			}
		}
	}


	cout << big_answer << endl;

	/*for (int i = 0; i <= _size+1; i++)
	{
		for (int j = 0; j <= _size+1; j++)
		{
				cout << _data[i][j] << " ";
		}
		cout << endl;
	}*/



	return 0;
}


void DFS(int x, int y)
{
	_data[x][y] = _count;
	int _xx = 0;
	int _yy = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			_xx = x + _x[i];
			_yy = y + _y[j];
			if (_data[_xx][_yy] == 1)
			{
				DFS(_xx, _yy);
			}

		}
	}

}