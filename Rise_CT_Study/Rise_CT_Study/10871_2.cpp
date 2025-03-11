#include <iostream>
using namespace std;

int input, n, x;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> x;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		if (input < x)
		{
			cout << input << ' ';
		}
	}

	return 0;
}