#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string n = "";
	int arr[10] = { 0, };
	int result = 0;

	cin >> n;

	for (char c : n)
	{
		arr[c - '0']++;
	}

	arr[6] = (arr[6] + arr[9] + 1) / 2;

	for (int i = 0; i < 9; i++)
	{
		result = max(result, arr[i]);
	}

	cout << result << endl;

	return 0;
}