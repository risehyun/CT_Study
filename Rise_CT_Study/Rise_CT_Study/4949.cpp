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
        stack<char> s;  // stack에는 괄호 문자를 넣어야 하므로 타입을 'int'가 아닌 'char'로 변경

        string input = "";
        getline(cin, input);  // 전체 입력을 받는다. '.'도 포함된다.

        if (input == ".")  // 입력이 온점(.)만 있을 경우 종료
        {
            break;
        }

        // 온점을 마지막에 포함하지 않도록 제거
        if (input.back() == '.')
        {
            input.pop_back();  // 마지막 온점 제거
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
