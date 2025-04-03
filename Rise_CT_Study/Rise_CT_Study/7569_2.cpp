#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

// ��, ��, ��, ��, ����, �Ʒ���
int dx[6] = { 0, 0, -1, 1, 0, 0 };
int dy[6] = { -1, 1, 0, 0, 0, 0 };
int dz[6] = { 0, 0, 0, 0, 1, -1 };

int boxes[103][103][103];
int dist[103][103][103];

queue<tuple<int, int, int>> Q;
int m, n, h;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;

	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				int input;

				cin >> input;

				boxes[z][y][x] = input;

				if (input == 1)
				{
					Q.push({ z, y, x });

					// �̹� ������������ 0���� �ʱ�ȭ�Ǿ� �ֱ� ������ ��������� ���������� �巯��
					dist[z][y][x] = 0; 
				}
				else if (input == 0)
				{
					dist[z][y][x] = -1;
				}
			}
		}
	}

	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int curX, curY, curZ;
		tie(curZ, curY, curX) = cur;

		for (int dir = 0; dir < 6; dir++)
		{
			int nz = curZ + dz[dir];
			int ny = curY + dy[dir];
			int nx = curX + dx[dir];
			if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (dist[nz][ny][nx] != -1)
				continue;
			dist[nz][ny][nx] = dist[curZ][curY][curX] + 1;
			Q.push({ nz, ny, nx });
		}
	}

	int ans = 0;
	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (dist[z][y][x] == -1)
				{
					cout << -1;
					return 0;
				}
				ans = max(ans, dist[z][y][x]);
			}
		}
	}
	cout << ans;
	return 0;
}