#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int> input;

	int n;

	cin >> n;

	input.resize(n);

	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	sort(input.begin(), input.end());


	for (int i = 0; i < n; i++)
	{
		cout << input[i] << '\n';
	}

	return 0;
}