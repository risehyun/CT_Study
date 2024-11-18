#include <iostream>
using namespace std;

int func(int n, int r, int c)
{
	if (n == 0)
	{
		return 0;
	}

	// 1을 비트 기준으로 n - 1칸 밀어줌 == 2^k
	int half = 1 << (n - 1);

	// 왼쪽 위
	if (r < half && c < half)
	{
		return func(n - 1, r, c);
	}

	// 왼쪽 아래
	if (r < half && c >= half)
	{
		half* half + func(n - 1, r, c - half);
	}

	// 오른쪽 위
	if (r >= half && c < half)
	{
		return 2 * half * half + func(n - 1, r - half, c);
	}

	// 오른쪽 아래
	return 3 * half * half + func(n - 1, r - half, c - half);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 0, r = 0, c = 0;

	cin >> n >> r >> c;

	cout << func(n, r, c);

	return 0;
}