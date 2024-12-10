#include <iostream>
using namespace std;

bool isUsed1[40]; // �� (����) üũ
bool isUsed2[40]; // '/' ���� �밢�� üũ
bool isUsed3[40]; // '\' ���� �밢�� üũ

int cnt = 0;
int n;

void func(int cur)
{
	// ���� ���µ� ������ ���
	if (cur == n)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (isUsed1[i] || isUsed2[i + cur] || isUsed3[cur - i + n - 1])
		{
			continue;
		}

		isUsed1[i] = true;
		isUsed2[i + cur] = true;
		isUsed3[cur - i + n - 1] = true;
		func(cur + 1);
		isUsed1[i] = false;
		isUsed2[i + cur] = false;
		isUsed3[cur - i + n - 1] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	func(0);

	cout << cnt;

	return 0;
}