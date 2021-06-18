#pragma once
#include<iostream>
#include<limits>

using namespace std;

int Three()
{
	int max_age = std::numeric_limits<int>::min();
	int min_age = std::numeric_limits<int>::max();

	int a;
	cin >> a;

	int* age = new int[a];

	for (int i = 0; i < a; i++)
		cin >> age[i];

	for (int i = 0; i < a; i++)
	{
		if (age[i] > max_age)
			max_age = age[i];
		if (age[i] < min_age)
			min_age = age[i];
	}

	cout << max_age - min_age << endl;

	return 0;

}