#include <iostream>
using namespace std;

int n, x, input;

int main()
{
	ios::sync_with_stdio(false);
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