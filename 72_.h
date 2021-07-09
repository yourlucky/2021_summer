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

int seventytwo()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int p;
	cin >> p;
	int num;
	cin >> num;

	queue<int> yoon;

	for (int i = 1; i <= p; i++)
	{
		yoon.push(i);
	}



	while (yoon.size() != 1)
	{
		for (int i = 1; i < num; i++)
		{
			yoon.push(yoon.front());
			yoon.pop();
		}
		yoon.pop();
	}

	cout << yoon.front() << endl;


	return 0;
}


