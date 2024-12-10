#include <iostream>
using namespace std;

bool isUsed1[40]; // 열 (세로) 체크
bool isUsed2[40]; // '/' 방향 대각선 체크
bool isUsed3[40]; // '\' 방향 대각선 체크

int cnt = 0;
int n;

void func(int cur)
{
	// 퀸을 놓는데 성공한 경우
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