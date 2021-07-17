#pragma once
#include<bits/stdc++.h>

using namespace std;



struct My {
	int x;
	int y;
	int d;
	My(int _x, int _y, int _d)
	{
		x = _x;
		y = _y;
		d = _d;
	}

	bool operator < (const My& b) const
	{
		if (d == b.d)
		{
			if (x == b.x) return y > b.y;
			else return x > b.x;
		}
		else
			return d > b.d;

	}
};
int big_answer = 0;
int m_size;
int _map[26][26] = { 0 };
int visited[26][26] = { 0 };
pair<int, int> simba_l;
int simba_s = 2;
priority_queue<My> sQ;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int prey = 0;

void simba_eat();

void bfs(int x, int y, int d);

int ninety()
{

	//ifstream cin; //cin의 콘솔입력을 대체-1
	//cin.open("Input_data.txt"); //cin의 콘솔입력을 대체-2

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> m_size;

	int d1;
	for (int i = 1; i <= m_size; i++)
	{
		for (int j = 1; j <= m_size; j++)
		{
			cin >> d1;
			_map[i][j] = d1;
		}
	}


	for (int i = 1; i <= m_size; i++)
	{
		for (int j = 1; j <= m_size; j++)
		{
			if (_map[i][j] == 9)
			{
				simba_l.first = i;
				simba_l.second = j;
				_map[i][j] = 0;

			}
		}
	}

	sQ.push(My(simba_l.first, simba_l.second, 0));
	bfs(simba_l.first, simba_l.second, 0);

	cout << big_answer;

	return 0;
}

void bfs(int x, int y, int d)
{
	while (!sQ.empty())
	{
		My temp = sQ.top();
		int n_x = temp.x;
		int n_y = temp.y;
		int n_d = temp.d;
		sQ.pop();

		if (_map[n_x][n_y] != 0 && _map[n_x][n_y] < simba_s)
		{
			simba_eat();
			big_answer += n_d;
			_map[n_x][n_y] = 0;
			n_d = 0;

			while (!sQ.empty())
				sQ.pop();

			sQ.push(My(n_x, n_y, 0));


			for (int i = 1; i <= m_size; i++)
			{
				for (int j = 1; j <= m_size; j++)
				{
					visited[i][j] = 0;
				}
			}


		}

		for (int i = 0; i < 4; i++)
		{
			int n_xx = n_x + dx[i];
			int n_yy = n_y + dy[i];

			if (visited[n_xx][n_yy] == 0 && n_xx > 0 && n_yy > 0 && n_xx <= m_size && n_yy <= m_size)
			{
				if (_map[n_xx][n_yy] <= simba_s)
				{
					sQ.push(My(n_xx, n_yy, n_d + 1));
					visited[n_xx][n_yy] = 1;
				}
			}
		}

	}

}

void simba_eat()
{
	prey++;
	if (prey >= simba_s)
	{
		simba_s++;
		prey = 0;
	}

}