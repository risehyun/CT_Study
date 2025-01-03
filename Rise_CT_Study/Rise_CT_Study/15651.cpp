#include <iostream>
using namespace std;

int n, m;
int arr[10];

void func(int level)
{
	if (level == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		arr[level] = i;
		func(level + 1);
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	func(0);

	return 0;
}