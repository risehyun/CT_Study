#include <iostream>
#include <queue>
using namespace std;

int paper[502][502];
bool visited[502][502];
int n, m;

// 상, 하, 좌, 우 이동 방향
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	visited[x][y] = true;
	int area = 1;

	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curX + dx[i];
			int ny = curY + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			{
				continue;
			}

			if (visited[nx][ny] || paper[nx][ny] == 0)
			{
				continue;
			}

			visited[nx][ny] = true;
			q.push({ nx, ny });
			area++;
		}
	}

	return area;
}

int main()
{

	// 종이의 x, y 범위 입력
	cin >> n >> m;

	//  종이 내부값 입력
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> paper[i][j];
		}
	}

	int count = 0;
	int maxArea = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (paper[i][j] == 1 && !visited[i][j])
			{
				++count;
				int area = bfs(i, j);
				if (area > maxArea)
				{
					maxArea = area;
				}
			}
		}
	}

	cout << count << '\n' << maxArea << '\n';

	return 0;
}