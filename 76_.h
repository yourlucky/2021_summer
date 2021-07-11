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

int remember[21] = { 0 };

int factorial(int n);

int seventysix()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	int n = 0;
	cin >> n;

	int r = 0;
	cin >> r;


	remember[0] = 1;
	remember[1] = 1;


	cout << factorial(n) / (factorial(r) * factorial(n - r)) << endl;



	return 0;
}


int factorial(int n)
{
	if (remember[n] != 0)
	{
		return remember[n];
	}

	else if (n > 1)
	{
		remember[n] = n * factorial(n - 1);
	}

	return remember[n];
}

