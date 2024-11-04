#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;

    deque<pair<int, int>> dq; // {��, �ε���} ���� ����
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;

        // ���� �ڿ������� ���� ������ ū �� ����
        while (!dq.empty() && dq.back().first >= input)
        {
            dq.pop_back();
        }

        dq.push_back({ input, i });

        // ���� �տ� �ִ� ���� �����̵� ������ ������ ����� ����
        if (dq.front().second <= i - L)
        {
            dq.pop_front();
        }

        // ���� �������� �ּڰ� ���
        cout << dq.front().first << ' ';
    }

    return 0;
}
