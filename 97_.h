#pragma once
#include<bits/stdc++.h>


using namespace std;

int DFS(int n1, int n2, vector < vector <int> >& _data, vector < vector <int> > & _value);

int  ninetyseven()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

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


	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < number; j++)
		{
			if (i == 0 && j == 0)
				_value[i][j] = _data[i][j];

			else if (i == 0)
			{
				_value[i][j] = _value[i][j - 1] + _data[i][j];
			}

			else if (j == 0)
			{
				_value[i][j] = _value[i - 1][j] + _data[i][j];
			}

			else
			{
				_value[i][j] = (min(_value[i][j - 1], _value[i - 1][j])) + _data[i][j];
			}
		}

	}



	cout << _value[number - 1][number - 1] << endl;

	return 0;
}
