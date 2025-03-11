#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int input;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 3; i++)
	{
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < 3; i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}