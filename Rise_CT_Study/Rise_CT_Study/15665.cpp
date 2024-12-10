#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int input[10];
vector<bool> chk(10002);

void func(int level)
{
	if (level == m) // ������ ���̰� M�̸� ���
	{
		for (int i = 0; i < m; i++)
		{
			cout << input[arr[i]] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		arr[level] = i;
		func(level + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	int idx = 0; // ���� ������ �ε���. �ߺ��� ���� ������ ����.

	while (n--) 
	{
		cin >> input[idx];

		if (chk[input[idx]]) // �̹� ������ ���� ���� ��� �Ѿ
		{
			continue;
		}

		chk[input[idx]] = true; // �׷��� ���� ��� ���� num �迭�� �߰�
		idx++;
	}
	// ���� num���� �ߺ����� ���� ���鸸 ���ְ� ���̴� idx.
	n = idx; // ���� ������� ����� ǥ���� ����ϱ� ���� n = idx�� ��.

	sort(input, input + n);
	func(0);

	return 0;
}
