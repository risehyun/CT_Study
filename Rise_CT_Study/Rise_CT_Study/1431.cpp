#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string st;
vector<string> v;

// 비교 함수 인자로 stl 혹은 클래스 객체를 전달하는 경우엔 reference를 사용하는 것이 좋다
bool cmp(string& a, string& b) {
    int lena = a.size(), lenb = b.size();
    int suma = 0, sumb = 0;
    if (lena != lenb) return lena < lenb;

    for (int i = 0; i < lena; i++) 
    { // 숫자만 더한다. 
        if (isdigit(a[i])) suma += (a[i] - '0');
    }
    for (int i = 0; i < lenb; i++) 
    {
        if (isdigit(b[i])) sumb += (b[i] - '0');
    }
    if (suma != sumb) return suma < sumb;

    return a < b; // 사전순
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st;
        v.push_back(st);
    }
    sort(v.begin(), v.end(), cmp);
    for (auto i : v) cout << i << '\n';
}