#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int board[51][51];
bool vis[51][51];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1};

int T;
int M;
int N;
int K;

queue<pair<int, int>> q;

void bfs(int x, int y) 
{
    vis[x][y] = true;
    q.push({ x,y });
    while (!q.empty()) 
    {
        auto cur = q.front(); 
        q.pop();

        for (int dir = 0; dir < 4; dir++) 
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            {
                continue;
            }
            if (vis[nx][ny] || board[nx][ny] != 1)
            {
                continue;
            }

            vis[nx][ny] = true;
            q.push({ nx,ny });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) 
    {
        cin >> M >> N >> K;
        int x, y;

        for (int i = 0; i < K; i++) 
        {
            cin >> x >> y;
            board[y][x] = 1;
        }

        int res = 0;

        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++) 
            {
                if (board[i][j] == 1 && !vis[i][j]) 
                {
                    bfs(i, j);
                    res++;
                }
            }
        }

        cout << res << '\n';

        for (int i = 0; i < N; i++) 
        {
            fill(board[i], board[i] + M, 0);
            fill(vis[i], vis[i] + M, false);
        }
    }

    return 0;
}