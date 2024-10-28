#include <iostream>

using namespace std;

// 시간복잡도 0(루트n)

int func3(int n)
{
	for (int i = 0; i <= n; i++)
	{
		if (i * i == n) return 1;
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout << func3(9) << '\n';
	cout << func3(693953651) << '\n';
	cout << func3(756580036);

	return 0;
}