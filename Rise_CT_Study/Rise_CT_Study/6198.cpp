#include <iostream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int count;
    stack<int> s;
    long long answer = 0;
    cin >> count;

    for (int i = 0; i < count; i++) 
    {
        int height;
        cin >> height;

        if (s.empty()) 
        { 
            s.push(height); 
            continue; 
        }

        while (!s.empty() && s.top() <= height)
        {
            s.pop();
        }

        answer += s.size();

        s.push(height);
    }

    cout << answer;

    return 0;
}