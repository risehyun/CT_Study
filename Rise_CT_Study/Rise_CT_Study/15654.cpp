#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> arr;
vector<int> input;
vector<bool> isUsed;

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
		if (!isUsed[i])
		{
			arr[level] = input[i];
			isUsed[i] = true;
			func(level + 1);
			isUsed[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;

	input.resize(n);
	arr.resize(n);
	isUsed.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	sort(input.begin(), input.end());

	func(0);

	return 0;
}