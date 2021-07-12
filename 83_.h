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

int visited[10] = { 0 };
int _data[8] = { 0 };
int send();
int more();
int money();
void DFS(int num);


int eightythree()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2


	DFS(0);


	return 0;

}

void DFS(int num)
{
	if (num == 8)
	{

		if (send() + more() == money())
		{
			//cout << "send" << send() << endl;

			if (_data[0] == 0 || _data[4] == 0)
				return;

			else
			{
				cout << _data[0] << " " << _data[1] << " " << _data[2] << " " << _data[3] << endl;
				cout << " + " << _data[4] << " " << _data[5] << " " << _data[6] << " " << _data[7] << endl;
				cout << "-------------------------------------" << endl;
				cout << _data[4] << " " << _data[5] << " " << _data[2] << " " << _data[1] << " " << _data[7] << endl;
				cout << endl;
				cout << endl;
				cout << endl;
			}
		}

	}

	else
	{
		for (int i = 0; i < 10; i++)
		{
			if (visited[i] == 0)
			{
				_data[num] = i;
				visited[i] = 1;
				DFS(num + 1);
				visited[i] = 0;
			}
		}
	}
}

int send()
{
	return _data[0] * 1000 + _data[1] * 100 + _data[2] * 10 + _data[3];

}
int more()
{
	return _data[4] * 1000 + _data[5] * 100 + _data[6] * 10 + _data[1];

}

int money()
{
	return _data[4] * 10000 + _data[5] * 1000 + _data[2] * 100 + _data[1] * 10 + _data[7];

}