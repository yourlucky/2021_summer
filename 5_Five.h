#pragma once
#include<iostream>
#include<string>
#include <fstream>

using namespace std;

int Five()
{
	//ifstream cin;//cin�� �ܼ��Է��� ��ü-1
	//cin.open("Input_data.txt");//cin�� �ܼ��Է��� ��ü-2

	string a;
	cin >> a;

	int k1 = a[0] - 48;
	int k2 = a[1] - 48;

	int age = 0;
	char gender = 'M';

	if (a[7] == 1 + 48)
	{
		age = 1900 + 10 * k1 + k2;
		gender = 'M';
	}

	else if (a[7] == 2 + 48)
	{
		age = 1900 + 10 * k1 + k2;
		gender = 'W';
	}

	else if (a[7] == 3 + 48)
	{
		age = 2000 + 10 * k1 + k2;
		gender = 'M';
	}

	else if (a[7] == 4 + 48)
	{
		age = 2000 + 10 * k1 + k2;
		gender = 'W';
	}

	else
	{
		cout << "�ֹε�Ϲ�ȣ ����" << endl;
		return 0;
	}

	cout << 2019 - age + 1 << "  " << gender;

	return 0;
}