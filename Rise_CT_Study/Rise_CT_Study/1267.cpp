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

        // �� ��ȭ �ð��� ���� ���� ������� �ν� ������� ���������� ���
        y_total += (input / 30 + 1) * 10; // ���� ����� ��� ���
        m_total += (input / 60 + 1) * 15; // �ν� ����� ��� ���
    }

    if (y_total < m_total) cout << "Y " << y_total;
    else if (m_total < y_total) cout << "M " << m_total;
    else cout << "Y M " << y_total;

    return 0;
}