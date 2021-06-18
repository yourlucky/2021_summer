#pragma once
#include<iostream>
#include<String>
#include<Vector>
#include<math.h>

using namespace std;

int Six()
{
	string k;
	cin >> k;
	
	vector<int> Number;

	int n = 0;
	int i = 0;


	for (int i = 0; i < k.length(); i++)
	{
		
		if (k[i] >= 48 && k[i] <= 57)
		{
			n = k[i] - 48;
			Number.push_back(n);
		}
			
	}

	/*for (auto i = Number.begin(); i != Number.end(); ++i)
		cout << *i << endl;*/

	int bigNumber = 0;

	for (int i = Number.size(); i >= 1; --i)
	{
		bigNumber += pow(10, i) * Number[Number.size()-i];
	}

	bigNumber /= 10;
	cout << bigNumber << endl;;

	int answer = 0;

	for (int i = 1; i <= bigNumber; i++)
	{
		if (bigNumber % i == 0)
		{
			answer++;
		}
	}
	cout << answer;

	return 0;
}