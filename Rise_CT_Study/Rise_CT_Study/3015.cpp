#include <iostream>
#include <stack>
using namespace std;

struct e { int h, cnt; };

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0; 
    stack<e> S;

    cin >> n;

    long long ans = 0;

    while (n--) 
    {
        int x = 0; 
        int cnt = 1;

        cin >> x;

        while (!S.empty() && S.top().h <= x) 
        {
            ans += S.top().cnt; // t보다 크거나 같은 사람(k)
 
            if (S.top().h == x)
            {
                cnt += S.top().cnt;
            }

            S.pop();
        }
        if (!S.empty())
        {
            ans++; // x앞에 x보다 큰 사람
        }

        S.push({ x, cnt });
    }

    cout << ans;

    return 0;
}