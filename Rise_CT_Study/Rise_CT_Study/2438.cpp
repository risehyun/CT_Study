#include <iostream>
using namespace std;

int n;

int main()
{
	cin >> n;

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < y + 1; x++)
		{
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}