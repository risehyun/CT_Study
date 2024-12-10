#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> input;
vector<int> arr;

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

	for (int i = 0; i < n; i++)
	{
		arr[level] = input[i];
		func(level + 1);
	}
}

int main()
{
	cin >> n >> m;

	input.resize(n);
	arr.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	sort(input.begin(), input.end());

	func(0);

	return 0;
}