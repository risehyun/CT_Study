#include <iostream>
using namespace std;

int arr[10];
int n, m;

void func(int level, int start)
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

	for (int i = start; i <= n; i++)
	{
		arr[level] = i;
		func(level + 1, i);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	func(0, 1);

	return 0;
}