#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

string maze[1002];

int fireMove[1002][1002];
int charMove[1002][1002];

int R;
int C;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
	{
		fill(fireMove[i], fireMove[i] + C, -1);
		fill(charMove[i], charMove[i] + C, -1);
	}

	for (int i = 0; i < R; i++)
	{
		cin >> maze[i];
	}

	queue<pair<int, int> > Q1;
	queue<pair<int, int> > Q2;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (maze[i][j] == 'F')
			{
				Q1.push({ i,j });
				fireMove[i][j] = 0;
			}
			if (maze[i][j] == 'J')
			{
				Q2.push({ i,j });
				charMove[i][j] = 0;
			}
		}
	}


	while (!Q1.empty())
	{
		auto cur = Q1.front();
		Q1.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				continue;
			}
			if (fireMove[nx][ny] >= 0 || maze[nx][ny] == '#')
			{
				continue;
			}

			fireMove[nx][ny] = fireMove[cur.X][cur.Y] + 1;
			Q1.push({ nx,ny });
		}
	}

	while (!Q2.empty())
	{
		auto cur = Q2.front();
		Q2.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
			{
				cout << charMove[cur.X][cur.Y] + 1;
				return 0;
			}
			if (charMove[nx][ny] >= 0 || maze[nx][ny] == '#')
			{
				continue;
			}
			if (fireMove[nx][ny] != -1 && fireMove[nx][ny] <= charMove[cur.X][cur.Y] + 1)
			{
				continue;
			}

			charMove[nx][ny] = charMove[cur.X][cur.Y] + 1;
			Q2.push({ nx,ny });
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}