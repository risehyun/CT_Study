#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

bool isPuyo; // �ѿ䰡 �������� ����
bool vis[12][6]; // �ʵ� �湮 ����
string board[12]; // �ʵ� ����
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int ans;

// vis �迭 �ʱ�ȭ
void resetVis() {
    for (int i = 0; i < 12; ++i)
        for (int j = 0; j < 6; ++j)
            vis[i][j] = false;
}

// bfs Ž���� ������� ���� ���� �ѿ並 ����� �Լ�
void puyo(int x, int y) {
    bool doErase = false; // �ѿ並 �������ϴ��� ����
    vis[x][y] = true;
    char color = board[x][y];
    queue<pair<int, int> > q;
    vector<pair<int, int>> tmp; // tmp: 4�� �̻��� ��� �ѿ並 ����� ���� ��ġ�� �����ϴ� vector
    q.push({ x, y }); tmp.push_back({ x, y });
    while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;
            // �� ĭ�̰ų� ���� �ٸ� ��� ����
            if (vis[nx][ny] || board[nx][ny] == '.' || board[nx][ny] != color) continue;
            vis[nx][ny] = true;
            q.push({ nx, ny }); tmp.push_back({ nx, ny });
        }
    }

    // 4�� �̻� ����Ǿ� ���� ��� ����� �ѿ� ����
    if (tmp.size() >= 4) {
        isPuyo = true;
        for (auto cur : tmp)
            board[cur.first][cur.second] = '.';
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 12; ++i)
        cin >> board[i];
    do {
        isPuyo = false; // �ѿ䰡 �������� ����
        for (int i = 0; i < 6; ++i) {
            // �ʵ��� �� ĭ�� ��� �ѿ� ���� �ø�
            for (int j = 10; j >= 0; --j) {
                int tmp = j;
                // �� ĭ�� ��� ��ġ ����
                while (tmp < 11 && board[tmp + 1][i] == '.') {
                    swap(board[tmp][i], board[tmp + 1][i]);
                    ++tmp;
                }
            }
        }
        // �ʵ� ���� ������ �ϴ� ��� �ѿ� ó��
        for (int i = 0; i < 12; ++i)
            for (int j = 0; j < 6; ++j)
                if (!vis[i][j] && board[i][j] != '.')
                    puyo(i, j);

        if (isPuyo) ++ans; // ���� �� �߰�
        resetVis();
    } while (isPuyo); // �� �̻� �ѿ䰡 ������ ���� ������ �ݺ�
    cout << ans;
}