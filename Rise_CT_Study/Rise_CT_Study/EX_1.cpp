#include <iostream>
using namespace std;

// 시간복잡도 : O(n)

int func1(int n)
{
	int sum = 0;

	for (int i = 3; i <= n; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	return sum;

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cout << func1(16) << '\n';
	cout << func1(34567) << '\n';
	cout << func1(27639) << '\n';

	return 0;
}