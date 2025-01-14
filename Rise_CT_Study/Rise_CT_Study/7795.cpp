#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> v(n + m);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            v[i] = { a, 0 };
        }
        for (int i = n; i < n + m; i++) {
            int b;
            cin >> b;
            v[i] = { b, 1 };
        }
        sort(v.begin(), v.end());
        int cnt = 0; // ������� ���� b�� ����
        int ans = 0;
        for (int i = 0; i < n + m; i++) {
            if (v[i].second == 0) // ���� ���� ���� A�� ���� ��
                ans += cnt;
            else // ���� ���� ���� B�� ���� ��
                cnt++;
        }
        cout << ans << '\n';
    }
}