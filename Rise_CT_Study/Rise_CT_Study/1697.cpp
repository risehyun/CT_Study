#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100001; // 최대 범위 설정

int bfs(int start, int target) {
    vector<int> visited(MAX, -1); // 방문 체크와 시간을 동시에 저장
    queue<int> q;

    visited[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr == target) {
            return visited[curr];
        }

        // 이동 가능한 세 가지 경우
        for (int next : {curr - 1, curr + 1, curr * 2}) {
            if (next >= 0 && next < MAX && visited[next] == -1) {
                visited[next] = visited[curr] + 1;
                q.push(next);
            }
        }
    }
    return -1; // 도달 불가능한 경우 (문제 조건상 나올 일 없음)
}

int main() 
{
    int N, K;
    cin >> N >> K;

    cout << bfs(N, K) << endl;
    return 0;
}
