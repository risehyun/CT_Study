#include <iostream>
#include <algorithm>
using namespace std;

int n;
// 따로 정렬하는 연산을 줄이기 위해 처음부터 끝시작, 시작 시간으로 입력받도록 함
pair<int, int> s[100005];

int main() 
{
    ios::sync_with_stdio(0);

    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> s[i].second >> s[i].first;
    }

    sort(s, s + n);

    int ans = 0;
    int t = 0;

    for (int i = 0; i < n; i++) 
    {
        if (t > s[i].second)
        {
            continue;
        }

        ans++;
        t = s[i].first;
    }

    cout << ans;

    return 0;
}