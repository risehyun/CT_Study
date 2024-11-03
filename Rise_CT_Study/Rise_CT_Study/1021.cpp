#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = 0, M = 0, count = 0;
    int index = 0;
    deque<int> dq;

    cin >> N >> M;

    // 주어진 크기 N만큼 덱에 원소를 순차적으로 채워줌
    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }

    while (M--)
    {
        int input = 0;
        cin >> input;

        index = find(dq.begin(), dq.end(), input) - dq.begin();

        while (dq.front() != input)
        {
            if (index < (int)dq.size() - index)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            count++;
        }

        // 원하는 값을 뽑아내기 위해 맨 앞 요소 제거
        dq.pop_front();
    }

    cout << count << '\n';

    return 0;
}