#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> dq; // {값, 인덱스} 쌍을 저장
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;

        // 덱의 뒤에서부터 현재 값보다 큰 값 제거
        while (!dq.empty() && dq.back().first >= input)
        {
            dq.pop_back();
        }

        dq.push_back({ input, i });

        // 덱의 앞에 있는 값이 슬라이딩 윈도우 범위를 벗어나면 제거
        if (dq.front().second <= i - L)
        {
            dq.pop_front();
        }

        // 현재 윈도우의 최솟값 출력
        cout << dq.front().first << ' ';
    }

    return 0;
}
