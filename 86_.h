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

void DFS(int l, int p);
int _map[50][50] = { 0 };
int pizza_ok[15];
vector < pair <int, int> >pizza_l;
vector < pair <int, int> >house_l;

int pizza_target;
int pizza_real = 0;
int house_real = 0;
int _size;

int tt_house_mc = 2147000000;

int eightysix()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2


	cin >> _size;
	cin >> pizza_target;

	int n1;
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			cin >> n1;
			_map[i][j] = n1;

			if (n1 == 2)
			{
				pizza_l.push_back(make_pair(i, j));
				pizza_real++;
			}
			else if (n1 == 1)
			{
				house_l.push_back(make_pair(i, j));
				house_real++;
			}

		}
	}


	int val = 0;
	DFS(0, 0);

	cout << tt_house_mc << endl;

	return 0;
}

void DFS(int l, int p)
{
	if (l == pizza_target)
	{
		/*for (int i = 0; i < pizza_real; i++)
		{
			cout << pizza_ok[i] << " , ";
		}
		cout << endl;*/

		int t_house_mc = 0;
		int house_mc = 2147000000;
		int house_value = 0;

		for (int i = 0; i < house_real; i++)
		{
			house_mc = 2147000000;
			for (int j = 0; j < pizza_real; j++)
			{
				if (pizza_ok[j] == 1)
				{
					house_value = abs(pizza_l[j].first - house_l[i].first) + abs(pizza_l[j].second - house_l[i].second);
					if (house_value < house_mc)
						house_mc = house_value;
				}
			}
			t_house_mc += house_mc;
		}

		if (t_house_mc < tt_house_mc)
			tt_house_mc = t_house_mc;

	}

	else
	{
		for (int i = p; i < pizza_real; i++)
		{
			pizza_ok[i] = 1;
			DFS(l + 1, i + 1);
			pizza_ok[i] = 0;
		}

	}
}