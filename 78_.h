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



int find(int n, int(&data)[1001]);

void _union(int n1, int n2, int(&data)[1001]);

int seventyeight()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int v = 0;
	cin >> v;

	int e = 0;
	cin >> e;


	int data[1001];

	int cost_data[1001][3];

	vector < pair <int, pair<int, int> > > costdata;

	for (int i = 0; i < 1001; i++)
	{
		data[i] = i;
	}


	int f1;
	int f2;
	int value;

	for (int i = 0; i < e; i++)
	{
		cin >> f1;
		cin >> f2;
		cin >> value;


		costdata.push_back(make_pair(value, make_pair(f1, f2)));
	}

	sort(costdata.begin(), costdata.end());


	int i = 0;
	int min_cost = 0;
	int ee = 0;
	while (ee != v - 1)
	{

		if (find(costdata[i].second.first, data) != find(costdata[i].second.second, data))
		{
			min_cost += costdata[i].first;

			ee++;
			/*cout << "연결 노드 : " << costdata[i].second.first << " ---" << costdata[i].second.second << endl;
			cout << ee << " 번째 비용 : " << costdata[i].first << " , 합계 : " << min_cost << endl;
			cout << "find 함수 값  from : " << find(costdata[i].second.first, data) << ",  find 함수 값  to : " << find(costdata[i].second.second, data) << endl;
			cout << "=================================================" << endl;*/

			_union(costdata[i].second.first, costdata[i].second.second, data);

			/*cout << "find 함수 값  from : " << find(costdata[i].second.first, data) << ",  find 함수 값  to : " << find(costdata[i].second.second, data) << endl;
			cout << "***********************************" << endl;*/
		}
		i++;
	}


	cout << min_cost << endl;

	return 0;
}

int find(int n, int(&data)[1001])
{
	if (n == data[n])
	{
		return n;
	}

	else
	{
		return data[n] = find(data[n], data);
	}

}

void _union(int n1, int n2, int(&data)[1001])
{
	n1 = find(n1, data);
	n2 = find(n2, data);

	if (n1 < n2) data[n2] = n1;
	else data[n1] = n2;

}
