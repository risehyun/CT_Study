#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string input = "";
    stack<char> s;

    int sum = 0;
    int num = 1;

    cin >> input;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '(')
        {
            num *= 2; // 소괄호가 나오면 곱해질 값 2배 증가
            s.push(input[i]);
        }
        else if (input[i] == '[')
        {
            num *= 3; // 대괄호가 나오면 곱해질 값 3배 증가
            s.push(input[i]);
        }
        else if (input[i] == ')')
        {
            // 올바르지 않은 경우 이므로 0 출력하고 프로그램 종료
            if (s.empty() || s.top() != '(')
            {
                cout << 0;
                return 0;
            }
            if (input[i - 1] == '(')
            {
                sum += num; // 직전 괄호가 여는 괄호였다면 sum에 값 추가
            }

            s.pop();  // 여는 소괄호 삭제
            num /= 2; // 소괄호 쌍이 사라졌으니 2로 나눔

        }
        else
        { // str[i] == ']'
            if (s.empty() || s.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if (input[i - 1] == '[')
            {
                // 직전 괄호가 여는 괄호였다면 sum에 값 추가
                sum += num;
            }

            s.pop();  // 여는 대괄호 삭제
            num /= 3; // 대괄호 쌍이 사라졌으니 3로 나눔

        }
    }

    // s가 비었다면 전체 계산이 끝났다는 의미이므로 그대로 sum 값 결과 출력
    if (s.empty())
    {
        cout << sum;
    }
    else
    {
        cout << 0;
    }

    return 0;
}