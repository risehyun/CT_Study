#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long a[100005];

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    int cnt = 0;

    long long mxval = -(1ll << 62) - 1; // 1�� long long���� ����ȯ���� �ʰ� 1 << 62�� �ۼ��� int overflow �߻�

    int mxcnt = 0;

    for (int i = 0; i < n; i++) 
    {
        if (i == 0 || a[i - 1] == a[i]) cnt++; // i�� 0�� ��� ���� ���� true�̱� ������ a[i-1]�� �������� ����
        else 
        {
            if (cnt > mxcnt) 
            {
                mxcnt = cnt;
                mxval = a[i - 1];
            }
            cnt = 1;
        }
    }
    if (cnt > mxcnt) mxval = a[n - 1]; // ���� ������ ���� �� �� �����ߴ����� ������ Ȯ��, �� ó���� ������ ���� ������ ���� ���� Ƚ���� �˻����� �ʰ� ��
    cout << mxval;
}