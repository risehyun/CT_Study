#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define X first
#define Y second

int n;
string board[27];
int vis[27][27];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}

	int cnt = 0;
	vector <int> result;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == 0 || vis[i][j] == 1)
			{
				continue;
			}

			queue<pair<int, int>> Q;
			vis[i][j] = 1;

			Q.push({ i, j });
			int width = 1;

			cnt++;

			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();

				for (int dir = 0; dir < 4; dir++)
				{
					int nx = cur.X + dx[dir];
					int ny = cur.Y + dy[dir];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (board[nx][ny] == '0' || vis[nx][ny] == 1)
						continue;
					Q.push({ nx, ny });
					vis[nx][ny] = 1;
					width++;
				}
			}
			result.push_back(width);
		}
	}

	cout << cnt << '\n';
	sort(result.begin(), result.end());

	for (int i : result)
	{
		cout << i << '\n';
	}

	return 0;
}