#include <iostream>

using namespace std;

int arr[10001];
int input, n;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr[input]++;
	}

	for (int i = 1; i <= 10000; i++)
	{
		while (arr[i])
		{
			cout << i << '\n';
			arr[i]--;
		}
	}

	return 0;
}