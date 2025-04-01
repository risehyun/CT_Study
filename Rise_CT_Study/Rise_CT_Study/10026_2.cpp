#include <iostream>
#include <queue>
using namespace std;

#define X first
#define Y second

int n;

char board[101][101];
bool visited[101][101];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void bfs(int i, int j)
{
    queue<pair<int, int>> Q;
    Q.push({ i,j });
    visited[i][j] = 1;

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            {
                continue;
            }
            if (visited[nx][ny] == 1 || board[i][j] != board[nx][ny])
            {
                continue;
            }

            visited[nx][ny] = 1;
            Q.push({ nx,ny });
        }
    }
}

int area()
{
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                cnt++;
                bfs(i, j);
            }
        }
    }
    return cnt;
}

int main()
{
	cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> board[y][x];
		}
	}

    int not_g = area(); //적록색약이 아닌사람

    // 적록색약인 사람을 구하기위한 방문배열 초기화
    for (int i = 0; i < n; i++)
    {
        fill(visited[i], visited[i] + n, false);
    }

    // 적록색약은 초록과 빨강을 구분 못하므로 초록이면 빨강으로 바꿔줌
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (board[i][j] == 'G')
                board[i][j] = 'R';
        }
    }

    int is_g = area(); //적록색약인 사람
    cout << not_g << " " << is_g;
    return 0;



	return 0;
}