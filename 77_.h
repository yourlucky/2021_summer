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

int seventyseven()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int n = 0;
	cin >> n;

	int r = 0;
	cin >> r;

	int data[1001];

	for (int i = 0; i < 1001; i++)
	{
		data[i] = i;
	}


	int f1;
	int f2;
	for (int i = 0; i < r; i++)
	{
		cin >> f1;
		cin >> f2;
		_union(f1, f2, data);
	}

	int a1;
	int a2;
	cin >> a1;
	cin >> a2;


	if (find(a1, data) == find(a2, data))
		cout << "YES";

	else
		cout << "NO";



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

