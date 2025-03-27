#include <iostream>
#include <queue>
#include <string>
using namespace std;

int maze[102][102];
int dist[102][102];
int n, m;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs() {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });
    dist[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny] != 0) continue;
            if (maze[nx][ny] == 0) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    return dist[n - 1][m - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < m; j++) {
            maze[i][j] = line[j] - '0';
        }
    }

    cout << bfs() << '\n';

    return 0;
}
