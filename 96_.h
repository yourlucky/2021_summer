#pragma once
#include<bits/stdc++.h>


using namespace std;


struct tower {
	int area;
	int height;
	int weight;

	tower(int a, int v, int w)
	{
		area = a;
		height = v;
		weight = w;
	}

	bool operator < (const tower& b) const {
		return area < b.area;
	}
};


int ninetysix()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int number = 0;

	vector <tower> n_data;
	vector <int> n_value(number);


	cin >> number;


	int d1;
	int d2;
	int d3;

	for (int i = 0; i < number; i++)
	{
		cin >> d1;
		cin >> d2;
		cin >> d3;

		n_data.push_back(tower(d1, d2, d3));
	}


	sort(n_data.begin(), n_data.end());

	for (int i = 0; i < number; i++)
	{
		n_value.push_back(n_data[i].height);
	}


	int _tmax = 0;
	for (int i = 0; i < number; i++)
	{
		int _max = 0;
		for (int j = 0; j < i; j++)
		{

			if (n_data[i].weight > n_data[j].weight)
			{
				/*if (n_value[j] > _max)
					_max = n_value[j];*/
				_max = max(_max, n_value[j]);
			}
		}
		n_value[i] += _max;
		_tmax = max(_tmax, n_value[i]);
	}

	cout << _tmax << endl;

	//cout << endl;

	//cout << "*******************************" << endl;

	//for (int i = 0; i < number; i++)
	//{
	//	cout << "넓이 : " << n_data[i].area  << ", 높이 : " << n_data[i].height << ", 무게 : " << n_data[i].weight <<endl;
	//}


	//cout << "*******************************" << endl;

	//for (int i = 0; i < number; i++)
	//{
	//	cout << i << "번째 : " << n_value[i] << endl;
	//}


	return 0;
}
