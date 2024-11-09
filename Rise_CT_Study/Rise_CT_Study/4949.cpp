#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        int flag = 0;
        stack<char> s; 

        string input = "";
        getline(cin, input);  // 전체 입력을 받는다. '.'도 포함된다.

        if (input == ".")  // 입력이 온점(.)만 있을 경우 종료
        {
            break;
        }

        // 입력 문자열에서 괄호에 대한 처리를 시작
        for (char c : input)
        {
            if (c == ')')
            {
                if (s.empty() || s.top() != '(')
                {
                    flag = 1;
                    break;
                }
                else
                {
                    s.pop();
                }
            }
            else if (c == ']')
            {
                if (s.empty() || s.top() != '[')
                {
                    flag = 1;
                    break;
                }
                else
                {
                    s.pop();
                }
            }
            else if (c == '(' || c == '[')  // 열린 괄호일 경우
            {
                s.push(c);
            }
        }

        // 스택이 비어있지 않으면 짝이 맞지 않으므로
        if (!s.empty())
        {
            flag = 1;
        }

        if (flag == 1)
        {
            cout << "no" << '\n';
        }
        else
        {
            cout << "yes" << '\n';
        }
    }

    return 0;
}
