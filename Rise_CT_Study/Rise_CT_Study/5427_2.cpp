#include <iostream>
#include <queue>
using namespace std;

int t, h, w;

char map[1001][1001];

int fireMove[1001][1001];
int charMove[1001][1001];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

queue<pair<int, int>> qFire;
queue<pair<int, int>> qChar;

bool isEscapable;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		cin >> w >> h;

		isEscapable = false;
		while (!qFire.empty()) qFire.pop();
		while (!qChar.empty()) qChar.pop();

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				fireMove[y][x] = 0;
				charMove[y][x] = 0;
				map[y][x] = 0;
			}
		}

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				char input;

				cin >> input;

				if (input == '@')
				{
					// queue 안에 해당 y,x 좌표값을 넣고 bfs를 돌림.
					qChar.push({ y, x });
					charMove[y][x] = 1;
				}
				else if (input == '*')
				{
					qFire.push({ y, x });
					fireMove[y][x] = 1;
				}
				else if (input == '#')
				{
					charMove[y][x] = -1;
					fireMove[y][x] = -1;
				}
				else if (input == '.')
				{
					charMove[y][x] = 0;
					fireMove[y][x] = 0;
				}
			}
		}

		// 불의 확산 BFS를 먼저 구한다.
		while (!qFire.empty()) 
		{
			auto v = qFire.front();
			qFire.pop();

			for (int dir = 0; dir < 4; dir++) 
			{
				int ny = v.first + dy[dir];
				int nx = v.second + dx[dir];

				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				if (fireMove[ny][nx] != 0 || map[ny][nx] == '#') continue;

				fireMove[ny][nx] = fireMove[v.first][v.second] + 1;
				qFire.push({ ny, nx });
			}
		}

		// 상근이 이동 BFS
		while (!qChar.empty() && (!isEscapable))
		{
			auto v = qChar.front();
			qChar.pop();

			if (v.first == 0 || v.first == h - 1 || v.second == 0 || v.second == w - 1) {
				cout << charMove[v.first][v.second] << '\n';
				isEscapable = true;
				break;
			}

			for (int dir = 0; dir < 4; dir++) 
			{
				int ny = v.first + dy[dir];
				int nx = v.second + dx[dir];

				if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
				if (charMove[ny][nx] != 0 || map[ny][nx] == '#') continue;

				// 불이 도달하지 않았거나 상근이가 더 빨리 도착하는 경우만 이동 가능
				if (fireMove[ny][nx] != 0 && fireMove[ny][nx] <= charMove[v.first][v.second] + 1) continue;

				charMove[ny][nx] = charMove[v.first][v.second] + 1;
				qChar.push({ ny, nx });
			}
		}


		if (!isEscapable) 
		{
			cout << "IMPOSSIBLE\n";
		}
	}


	return 0;
}