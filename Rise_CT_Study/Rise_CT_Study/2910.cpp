#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define X first
#define Y second

int n, c;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.X > b.X;
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<pair<int, int>> arr; // pair : {cnt, num}
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        bool chk = false;
        for (auto& a : arr) {
            if (a.Y == x) {
                chk = true;
                a.X++;
                break;
            }
        }
        if (!chk) arr.push_back({ 1, x });
    }
    stable_sort(arr.begin(), arr.end(), cmp);

    for (auto b : arr)
        while (b.X--) cout << b.Y << ' ';
}