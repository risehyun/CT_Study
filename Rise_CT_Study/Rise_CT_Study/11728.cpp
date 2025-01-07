// 배열 합치기
#include <iostream>
#include <vector>
using namespace std;

vector<int> a;
vector<int> b;
vector<int> result;
int n, m, nIndex, mIndex;

int main()
{
    cin >> n >> m;

    a.resize(n);
    b.resize(m);

    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) 
    {
        cin >> b[i];
    }

    // 두 배열을 병합
    while (nIndex < n && mIndex < m) 
    {
        if (a[nIndex] <= b[mIndex]) 
        {
            result.push_back(a[nIndex]);
            nIndex++;
        }
        else 
        {
            result.push_back(b[mIndex]);
            mIndex++;
        }
    }

    // 남은 원소 처리
    while (nIndex < n) 
    {
        result.push_back(a[nIndex]);
        nIndex++;
    }

    while (mIndex < m) 
    {
        result.push_back(b[mIndex]);
        mIndex++;
    }

    for (int num : result) 
    {
        cout << num << ' ';
    }

    return 0;
}