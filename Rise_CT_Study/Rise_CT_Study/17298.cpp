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
    vector<int> nge(N, -1);  // ��� �迭�� -1�� �ʱ�ȭ
    stack<int> s;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = N - 1; i >= 0; i--) 
    {
        // ���� A[i]���� �۰ų� ���� ���� ��ū���� �� �� �����Ƿ� ����
        while (!s.empty() && s.top() <= A[i]) 
        {
            s.pop();
        }
        // ������ ��� ���� �ʴٸ� ������ top�� ��ū��
        if (!s.empty()) 
        {
            nge[i] = s.top();
        }
        // ���� ���� ���ÿ� push
        s.push(A[i]);
    }

    for (int i = 0; i < N; i++) 
    {
        cout << nge[i] << ' ';
    }

    return 0;
}