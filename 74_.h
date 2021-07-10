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

int seventyfour()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	priority_queue<int> pQ;

	while (1)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			if (!pQ.empty())
			{
				cout << -pQ.top() << endl;;
				pQ.pop();
			}
			else
			{
				cout << "-1" << endl;
			}
		}

		else if ((n == -1))
		{
			exit(0);
		}

		else
		{
			pQ.push(-n);
		}
	}

	return 0;
}

