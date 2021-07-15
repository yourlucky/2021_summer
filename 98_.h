#pragma once

#include<bits/stdc++.h>

using namespace std;
int DFS(int n1, int n2, vector < vector <int> >& _data, vector < vector <int> >& _value);

int nintyeight()
{

	ifstream cin; //cin의 콘솔입력을 대체-1
	cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int number = 0;
	cin >> number;

	vector < vector <int> > _data;
	vector < vector <int> > _value;



	int d1;
	for (int i = 0; i < number; i++)
	{
		vector <int> v1;
		vector <int> v2;
		for (int j = 0; j < number; j++)
		{
			cin >> d1;
			v1.push_back(d1);
			v2.push_back(0);
		}
		_data.push_back(v1);
		_value.push_back(v2);
	}


	_value[0][0] = _data[0][0];

	cout << DFS(number - 1, number - 1, _data, _value) << endl;


	//cout << "+++++++++++++++++++++++++++++" << endl;

	//for (int i = 0; i < number; i++)
	//{
	//	for (int j = 0; j < number; j++)
	//	{
	//		cout << _value[i][j] << "\t";
	//	}
	//	cout << endl;
	//}

	return 0;
}


int DFS(int n1, int n2, vector < vector <int> >& _data, vector < vector <int> >& _value)
{
	if (_value[n1][n2] != 0)
		return _value[n1][n2];

	else if (n1 == 0 && n2 == 0)
		return _value[0][0] = _data[0][0];

	else if (n1 == 0)
	{
		for (int i = 1; i <= n2; i++)
		{
			_value[0][i] = _value[0][i - 1] + _data[0][i];
		}
	}

	else if (n2 == 0)
	{
		for (int i = 1; i <= n1; i++)
		{
			_value[i][0] = _value[i - 1][0] + _data[i][0];
		}
	}
	else
	{
		return _value[n1][n2] = min(DFS(n1 - 1, n2, _data, _value), DFS(n1, n2 - 1, _data, _value)) + _data[n1][n2];
	}
}