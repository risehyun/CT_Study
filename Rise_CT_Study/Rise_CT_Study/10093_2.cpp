#include <iostream>

using namespace std;

long long a;
long long b;

int main()
{
	cin >> a >> b;

	if (a < b)
	{
		swap(a, b);
	}

	if (a == b || b - a == 1)
	{
		cout << 0;
	}
	else
	{
		cout << a - b - 1 << '\n';
		for (long long i = b + 1; i < a; i++)
		{
			cout << i << ' ';
		}
	}

	return 0;
}