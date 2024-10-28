#include <iostream>
using namespace std;

int a[1000001] = {};
bool occur[2000001];
int n, x;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> x;

    for (int i = 0; i < n; i++) 
    {
        int value = x - a[i];
        if (value > 0 && occur[value]) ans++;
        occur[a[i]] = true;
    }
    cout << ans;
}