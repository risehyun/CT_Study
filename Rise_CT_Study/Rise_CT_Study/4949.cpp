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
        getline(cin, input);  // ��ü �Է��� �޴´�. '.'�� ���Եȴ�.

        if (input == ".")  // �Է��� ����(.)�� ���� ��� ����
        {
            break;
        }

        // �Է� ���ڿ����� ��ȣ�� ���� ó���� ����
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
            else if (c == '(' || c == '[')  // ���� ��ȣ�� ���
            {
                s.push(c);
            }
        }

        // ������ ������� ������ ¦�� ���� �����Ƿ�
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
