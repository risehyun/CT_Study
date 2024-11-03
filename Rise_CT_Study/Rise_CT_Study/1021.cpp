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

    // �־��� ũ�� N��ŭ ���� ���Ҹ� ���������� ä����
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

        // ���ϴ� ���� �̾Ƴ��� ���� �� �� ��� ����
        dq.pop_front();
    }

    cout << count << '\n';

    return 0;
}