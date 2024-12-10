#include <iostream>
using namespace std;

int n, s;
int cnt = 0;
int arr[30];

void func(int cur, int tot)
{
	if (cur == n)
	{
		if (tot == s)
		{
			cnt++;
		}

		return;
	}

	// 현재 원소를 포함하는 경우
	func(cur + 1, tot);

	// 현재 원소를 포함하지 않는 경우
	func(cur + 1, tot + arr[cur]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> s;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	func(0, 0);

	if (s == 0)
	{
		cnt--;
	}

	cout << cnt;

	return 0;
}