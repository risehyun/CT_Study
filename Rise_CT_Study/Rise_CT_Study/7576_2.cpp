#include <iostream>
#include <queue>
using namespace std;

int box[1002][1002];
int dist[1002][1002];

int n, m, result;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int main()
{
	cin >> m >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> box[y][x];
			dist[y][x] = -1;
		}
	}

	queue<pair<int, int>> q;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (box[y][x] == 1)
			{
				q.push({ y, x });
				dist[y][x] = 0;
			}
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cur.first + dx[dir];
			int nx = cur.second + dy[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
			{
				continue;
			}

			if (box[ny][nx] == -1 || dist[ny][nx] != -1)
			{
				continue;
			}

		}
	}

	int result = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (box[y][x] == 0 && dist[y][x] == -1)
			{
				cout << -1 << '\n';
				return 0;
			}
			result = max(result, dist[y][x]);
		}
	}

	return 0;
}