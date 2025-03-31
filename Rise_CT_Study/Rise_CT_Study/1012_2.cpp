#include <iostream>
#include <queue>
using namespace std;

int t, m, n, k, x, y;

int ground[51][51];
bool visited[51][51];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;


int bfs(int x, int y)
{
    visited[x][y] = true;
    q.push({ x,y });
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            {
                continue;
            }
            if (visited[nx][ny] || ground[nx][ny] != 1)
            {
                continue;
            }

            visited[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
}

int main()
{
	cin >> t;

	cin >> m, n, k;

	while (--t)
	{
		for (int i = 0; i < k; i++)
		{
			cin >> x >> y;
			ground[x][y] = 1;
		}

		int result = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (ground[i][j] == 1 && !visited[i][j])
                {
                    bfs(i, j);
                    result++;
                }
            }
        }

        cout << result << '\n';

        for (int i = 0; i < n; i++)
        {
            fill(ground[i], ground[i] + m, 0);
            fill(visited[i], visited[i] + m, false);
        }
	}

	return 0;
}