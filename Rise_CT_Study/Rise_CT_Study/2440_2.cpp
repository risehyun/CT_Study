#include <iostream>
using namespace std;

int n;

int main()
{
	cin >> n;

	for (int y = 0; y < n; y++)
	{
		for (int x = n - y; x > 0; x--)
		{
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}