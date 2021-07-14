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

queue<BF> sQ;
vector < vector<int> > _data;
vector < vector<int> > _map;
pair<int, int> simbalocation;
int simbasize = 2;
int n;


int _x[4] = { -1,0,0,1 };
int _y[4] = { 0,1,-1,0 };


BF target_location();
void map_f();


int main()
{

	int _max = 0;

	ifstream cin; //cin의 콘솔입력을 대체-1
	cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	cin >> n;

	for (int i = 0; i <= n + 1; i++)
	{
		vector <int> v1;
		vector <int> v2;
		for (int j = 0; j <= n + 1; j++)
		{
			v1.push_back(-1);
			v2.push_back(-1);
		}
		_data.push_back(v1);
		_map.push_back(v2);
	}


	int n1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> n1;
			_data[i][j] = n1;
		}
	}

	simbalocation = make_pair(0, 0);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (_data[i][j] == 9)
			{
				simbalocation = make_pair(i, j);
				_data[i][j] = 0;
			}
		}
	}



	int time = 0;
	while (1)
	{
		map_f();

		BF tempe = target_location();

		if (tempe.value == -999)
			break;
		else
		{
			time += tempe.value;
			simbasize++;
			simbalocation = make_pair(tempe.x, tempe.y);
			_data[tempe.x][tempe.y] = 0;
		}
	}

	cout << time << endl;


	return 0;
}

void map_f()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (_data[i][j] <= simbasize)
				_map[i][j] = 0;
			else
				_map[i][j] = 1;
		}
	}
}

BF target_location()
{
	sQ.push(BF(simbalocation.first, simbalocation.second, 0));
	BF target_min = BF(0, 0, 2147000000);

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			if (_data[i][j] < simbasize && _data[i][j] > 0)
			{
				while (!sQ.empty())
				{
					BF tmp = sQ.front();
					int x = tmp.x;
					int y = tmp.y;

					if (x == i && y == j)
					{
						if (tmp.value == target_min.value)
						{
							if (target_min.y > j)
							{
								target_min.x = i;
								target_min.y = j;
							}
							else if (target_min.x > i)
							{
								target_min.x = i;
								target_min.y = j;
							}
						}
						else if (tmp.value < target_min.value)
						{
							target_min.x = i;
							target_min.y = j;
							target_min.value = tmp.value;
						}

					}

					sQ.pop();
					for (int i = 0; i < 4; i++)
					{
						int xx = x + _x[i];
						int yy = y + _y[i];

						if (_map[xx][yy] == 0)
						{
							sQ.push(BF(xx, yy, tmp.value + 1));
							_map[xx][yy] = 1;
						}
					}
				}


			}

		}
	}

	if (target_min.value != 2147000000)
	{
		_data[target_min.x][target_min.y] = 0;
		return target_min;
	}

	else
		return BF(0, 0, -999);

}

