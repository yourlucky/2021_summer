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



void DFS(int count, int(&list)[20], int(&number)[20], int(&visit)[20], int n, int r);
int answer_count = 0;

int eightytwo()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int n = 0;
	cin >> n;

	int r = 0;
	cin >> r;

	int number[20] = { 0 };
	int visit[20] = { 0 };
	int list[20] = { 0 };


	int k = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		number[i] = k;
	}

	DFS(1, list, number, visit, n, r);

	cout << answer_count << endl;



	return 0;
}

void DFS(int count, int(&list)[20], int(&number)[20], int(&visit)[20], int n, int r)
{

	if (count == r + 1)
	{
		for (int i = 1; i <= r; i++)
		{
			cout << list[i] << " ";
		}


		cout << endl;
		answer_count++;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			//cout << "i값 : " << i << ", number[i] : " << number[i] << " visit[number[i]] : " << visit[number[i]] << endl;
			if (visit[i] == 0)
			{
				list[count] = number[i];
				visit[i] = 1;
				DFS(count + 1, list, number, visit, n, r);
				visit[i] = 0;

			}
		}
	}

}