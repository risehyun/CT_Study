#include <iostream>
using namespace std;

int arr[10];
bool isUsed[10];
int n, m;

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
		if (isUsed[i] == false)
		{
			arr[level] = i;
			isUsed[i] = true;
			func(level + 1);
			isUsed[i] = false;
		}
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