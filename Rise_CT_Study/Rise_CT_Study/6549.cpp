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

        if (n == 0) break; // 종료 조건

        vector<int> heights(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> heights[i];
        }

        stack<int> s;
        long long maxArea = 0;

        for (int i = 0; i < n; i++) {
            // 스택에 있는 직사각형보다 현재 직사각형이 낮다면 넓이 계산
            while (!s.empty() && heights[s.top()] > heights[i]) 
            {
                int h = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : (i - s.top() - 1);
                maxArea = max(maxArea, (long long)h * width);
            }
            s.push(i); // 현재 인덱스 푸시
        }

        // 스택에 남아있는 직사각형 처리
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
