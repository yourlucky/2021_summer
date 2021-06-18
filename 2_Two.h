#pragma once

#include<iostream>
using namespace std;

int Two()
{
	int a;

	cin >> a;
	int sum = 1;
	int i = 1;

	cout << i;

	for (i = 2; i < a; i++)
	{
		if (a % i == 0)
		{
			cout<<" + " << i ;
			sum += i;
		}
	}
	
		cout << " = " << sum  << endl;
	

		return 0;

}