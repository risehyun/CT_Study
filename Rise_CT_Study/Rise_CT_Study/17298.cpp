#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> nge(N, -1);  // 결과 배열을 -1로 초기화
    stack<int> s;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = N - 1; i >= 0; i--) 
    {
        // 현재 A[i]보다 작거나 같은 값은 오큰수가 될 수 없으므로 제거
        while (!s.empty() && s.top() <= A[i]) 
        {
            s.pop();
        }
        // 스택이 비어 있지 않다면 스택의 top이 오큰수
        if (!s.empty()) 
        {
            nge[i] = s.top();
        }
        // 현재 값을 스택에 push
        s.push(A[i]);
    }

    for (int i = 0; i < N; i++) 
    {
        cout << nge[i] << ' ';
    }

    return 0;
}