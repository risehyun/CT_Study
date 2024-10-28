#include <iostream>
using namespace std;

// 시간복잡도 O(lgN)
int func4(int n)
{
	int value = 1;

	while (2 * value <= n) value *= 2;

	return value;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << func4(5) << '\n';
	cout << func4(97615282) << '\n';
	cout << func4(1024) << '\n';

	return 0;
}