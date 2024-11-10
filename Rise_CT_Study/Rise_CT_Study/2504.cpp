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
            num *= 2; // �Ұ�ȣ�� ������ ������ �� 2�� ����
            s.push(input[i]);
        }
        else if (input[i] == '[')
        {
            num *= 3; // ���ȣ�� ������ ������ �� 3�� ����
            s.push(input[i]);
        }
        else if (input[i] == ')')
        {
            // �ùٸ��� ���� ��� �̹Ƿ� 0 ����ϰ� ���α׷� ����
            if (s.empty() || s.top() != '(')
            {
                cout << 0;
                return 0;
            }
            if (input[i - 1] == '(')
            {
                sum += num; // ���� ��ȣ�� ���� ��ȣ���ٸ� sum�� �� �߰�
            }

            s.pop();  // ���� �Ұ�ȣ ����
            num /= 2; // �Ұ�ȣ ���� ��������� 2�� ����

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
                // ���� ��ȣ�� ���� ��ȣ���ٸ� sum�� �� �߰�
                sum += num;
            }

            s.pop();  // ���� ���ȣ ����
            num /= 3; // ���ȣ ���� ��������� 3�� ����

        }
    }

    // s�� ����ٸ� ��ü ����� �����ٴ� �ǹ��̹Ƿ� �״�� sum �� ��� ���
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