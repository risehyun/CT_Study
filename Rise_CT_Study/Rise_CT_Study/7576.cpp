#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int m;
int n;
int result;

int box[1002][1002];
int dist[1002][1002];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<pair<int, int>> Q;

	cin >> m >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];

			if (box[i][j] == 1)
			{
				Q.push({ i, j });
			}
			if (box[i][j] == 0)
			{
				dist[i][j] = -1;
			}
		}
	}

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			{
				continue;
			}
			if (dist[nx][ny] >= 0)
			{
				continue;
			}

			dist[nx][ny] = dist[cur.X][cur.Y] + 1;
			Q.push({ nx, ny });
		}
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < m; j++) 
		{
			if (dist[i][j] == -1) 
			{
				cout << -1 << '\n';
				return 0;
			}
			result = max(result, dist[i][j]);
		}
	}

	cout << result;

	return 0;
}