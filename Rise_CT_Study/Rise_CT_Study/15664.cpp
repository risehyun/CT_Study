#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> input; // �Է� �迭
vector<int> arr; // ������ ����
vector<bool> isUsed; // ��� ���� Ȯ�ο�

void func(int level, int start)
{
	if (level == m) // ������ ���̰� M�̸� ���
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int last_used = -1; // ���� �������� ������ ������ ���� ����
	for (int i = start; i < n; i++)
	{
		if (!isUsed[i] && input[i] != last_used) // ������� �ʾҰ� ������ ������ ���� �ٸ� ��츸 ����
		{
			arr[level] = input[i];
			isUsed[i] = true;
			func(level + 1, i);
			isUsed[i] = false;
			last_used = input[i]; // ���� ������ ���� last_used�� ����
		}
	}
}

int main()
{
	cin >> n >> m;

	input.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	sort(input.begin(), input.end());

	arr.resize(m); // ������ ���̴� M
	isUsed.resize(n); // ���ο� ũ���� isUsed �迭 �ʱ�ȭ

	func(0, 0); // 0��°���� ����
	return 0;
}
