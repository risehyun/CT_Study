#include <iostream>
using namespace std;

void func(int n, int depth) 
{

    string indent(depth * 4, '_');

    cout << indent << "\"����Լ��� ������?\"" << '\n';
    if (n == 0) 
    {
        cout << indent << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << '\n';
    }
    else 
    {
        cout << indent << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << '\n';
        cout << indent << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << '\n';
        cout << indent << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << '\n';

        func(n - 1, depth + 1);
    }
    cout << indent << "��� �亯�Ͽ���." << '\n';
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;

    cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << '\n';
    func(n, 0);

    return 0;
}
