#include <iostream>
using namespace std;

int n, input, y_total, m_total;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> input;

        // 각 통화 시간에 대해 영식 요금제와 민식 요금제를 개별적으로 계산
        y_total += (input / 30 + 1) * 10; // 영식 요금제 요금 계산
        m_total += (input / 60 + 1) * 15; // 민식 요금제 요금 계산
    }

    if (y_total < m_total) cout << "Y " << y_total;
    else if (m_total < y_total) cout << "M " << m_total;
    else cout << "Y M " << y_total;

    return 0;
}