#pragma once
#include<bits/stdc++.h>

using namespace std;

int main()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int number = 0;
	cin >> number;


	vector<int> n_data;
	vector<int> n_cal;

	int _data;
	for (int i = 0; i < number; i++)
	{
		cin >> _data;
		n_data.push_back(_data);
		n_cal.push_back(1);
	}


	for (int i = 0; i < number; i++)
	{
		int max = 0;
		for (int j = 0; j < i; j++)
		{

			if (n_data[i] > n_data[j])
			{
				if (n_cal[j] > max)
					max = n_cal[j];
			}
		}
		n_cal[i] = max + 1;
	}


	cout << *max_element(n_cal.begin(), n_cal.end());



	return 0;
}
