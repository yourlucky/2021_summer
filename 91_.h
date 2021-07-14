#pragma once

#include<bits/stdc++.h>

using namespace std;

int n_array[100];
int count_f(int a);
int number = 0;

int nightyone()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> number;

	n_array[1] = 1;
	n_array[2] = 2;

	cout << count_f(number);


	return 0;
}

int count_f(int a)
{
	if (a <= 1)
	{
		return 1;
	}

	else
	{
		if (n_array[a] != 0)
			return n_array[a];

		else
		{
			return n_array[a] = count_f(a - 2) + count_f(a - 1);
		}
	}
}