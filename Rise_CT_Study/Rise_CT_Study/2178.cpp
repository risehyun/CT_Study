#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

string board[102];
int dist[102][102];
int n, m;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> board[i];
	}
	for (int i = 0; i < n; i++)
	{
		fill(dist[i], dist[i] + m, -1);
	}

	queue<pair<int, int>> Q;
	Q.push({ 0, 0 });
	dist[0][0] = 0;

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

            if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
            {
                continue;
            }

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({ nx,ny });
        }
    }

    // 항상 도착위치로 이동할 수 있는 경우에만 입력이 주어지는 것이 출력 조건이다.
    // 즉, 처음부터 도착해있는 경우는 없으므로 문제의 특성상 최소한의 거리
    // 1이 보장되어야 하므로 +1이 정답이 된다.
    cout << dist[n - 1][m - 1] + 1; 

    return 0;
}