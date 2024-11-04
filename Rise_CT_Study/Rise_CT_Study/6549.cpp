#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) 
    {
        int n;
        cin >> n;

        if (n == 0) break; // ���� ����

        vector<int> heights(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> heights[i];
        }

        stack<int> s;
        long long maxArea = 0;

        for (int i = 0; i < n; i++) {
            // ���ÿ� �ִ� ���簢������ ���� ���簢���� ���ٸ� ���� ���
            while (!s.empty() && heights[s.top()] > heights[i]) 
            {
                int h = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                maxArea = max(maxArea, (long long)h * width);
            }
            s.push(i); // ���� �ε��� Ǫ��
        }

        // ���ÿ� �����ִ� ���簢�� ó��
        while (!s.empty()) 
        {
            int h = heights[s.top()];
            s.pop();
            int width = s.empty() ? n : (n - s.top() - 1);
            maxArea = max(maxArea, (long long)h * width);
        }

        cout << maxArea << '\n';
    }

    return 0;
}
