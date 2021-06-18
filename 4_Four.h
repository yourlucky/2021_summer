#pragma once
#include<iostream>
#include<limits>
#include<vector>
#include <fstream>

using namespace std;

int main()
{
	ifstream cin;//cin의 콘솔입력을 대체-1
	cin.open("Input_data.txt");//cin의 콘솔입력을 대체-2
	int max_age = std::numeric_limits<int>::min();
	int min_age = std::numeric_limits<int>::max();

	std::vector<int> age;

	int a;
	cin >> a;

	int input = 0;

	for (int i = 0; i < a; i++)
	{
		cin >> input;
		age.push_back(input);
	}
	int size = age.size();


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