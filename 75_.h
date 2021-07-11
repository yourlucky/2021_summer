#pragma once
#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;

struct Model_ {
	int money;
	int day;

	Model_(int m, int d)
	{
		money = m;
		day = d;
	}
	bool operator < (const Model_& b) const {
		if (day != b.day) return day > b.day;
		else return money > b.money;
	}

};


int seventyfive()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	priority_queue<int> pQ;
	vector<Model_> data;

	int number = 0;
	cin >> number;

	int m;
	int d;

	int max = 0;
	for (int i = 1; i <= number; i++)
	{
		cin >> m;
		cin >> d;

		if (d > max)
			max = d;

		data.push_back(Model_(m, d));
	}

	sort(data.begin(), data.end());

	int answer = 0;
	int j = 0;
	for (int i = max; i >= 1; i--)
	{
		for (; j < number; j++)
		{
			if (data[j].day < i)break;
			pQ.push(data[j].money);
		}

		if (!pQ.empty())
		{
			answer += pQ.top();
			pQ.pop();
		}
	}

	cout << answer << endl;

	return 0;
}

