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

int seventyone()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int s;
	cin >> s;
	int e;
	cin >> e;

	queue<int> yoon;
	int count[10001] = { 0 };

	count[s] = 1;
	yoon.push(s);
	int jump[3] = { -1,1,5 };

	int x = 0;
	int x_j = 0;


	while (x != e)
	{
		x = yoon.front();



		for (int i = 0; i < 3; i++)
		{
			x_j = x + jump[i];
			if (x_j == e)
			{
				cout << count[x] << endl;
				exit(0);
			}



			if (count[x_j] == 0)
			{
				yoon.push(x_j);
				count[x_j] = count[x] + 1;
			}
		}

		yoon.pop();
	}

	cout << count[e] << endl;

	return 0;
}
