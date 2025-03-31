#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100001; // �ִ� ���� ����

int bfs(int start, int target) {
    vector<int> visited(MAX, -1); // �湮 üũ�� �ð��� ���ÿ� ����
    queue<int> q;

    visited[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == target) {
            return visited[curr];
        }

        // �̵� ������ �� ���� ���
        for (int next : {curr - 1, curr + 1, curr * 2}) {
            if (next >= 0 && next < MAX && visited[next] == -1) {
                visited[next] = visited[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1; // ���� �Ұ����� ��� (���� ���ǻ� ���� �� ����)
}

int main() 
{
    int N, K;
    cin >> N >> K;

    cout << bfs(N, K) << endl;
    return 0;
}
