#include <iostream>
using namespace std;

int main()
{
	int N = 0;

	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = N - y; x > 0; x--)
		{
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}