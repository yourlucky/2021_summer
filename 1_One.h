#pragma once
#include <iostream>

int One()
{
	using namespace std;

	int a, b;
	cin >> a >> b;
	int sum = 0;

	for (int i = 0; i <= a; i++)
	{
		if (i % b == 0)
		{
			sum += i;
		}
	}

	cout << sum << endl;

	return 0;

}