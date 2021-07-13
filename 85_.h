#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

int number = 0;

int big_answer = 0;
int _max = 0;
int _min = 217000000;

int n_data[20];
int s_data[4];

void DFS(int l, int v);

int eightyfive()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2


	cin >> number;

	int _n = 0;
	for (int i = 0; i < number; i++)
	{
		cin >> _n;
		n_data[i] = _n;
	}

	for (int i = 0; i <= 3; i++)
	{
		cin >> _n;
		s_data[i] = _n;
	}


	int value = n_data[0];
	DFS(0, value);

	cout << _max << endl;
	cout << _min << endl;


	return 0;
}

void DFS(int l, int v)
{

	if (l == number - 1)
	{

		if (v < _min)
			_min = v;
		if (v > _max)
			_max = v;

	}

	else
	{
		if (s_data[0] > 0)
		{
			s_data[0]--;
			DFS(l + 1, v + n_data[l + 1]);
			s_data[0]++;
		}

		if (s_data[1] > 0)
		{
			s_data[1]--;
			DFS(l + 1, v - n_data[l + 1]);
			s_data[1]++;
		}

		if (s_data[2] > 0)
		{
			s_data[2]--;
			DFS(l + 1, v * n_data[l + 1]);
			s_data[2]++;
		}

		if (s_data[3] > 0)
		{
			s_data[3]--;
			DFS(l + 1, v / n_data[l + 1]);
			s_data[3]++;

		}
	}



}