#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	int number = 0, minValue = 0;
	int sum = 0;
	vector<int> odds;

	for (int i = 0; i < 7; i++)
	{
		cin >> number;

		if (number % 2 == 1)
		{
			odds.push_back(number);
			sum += number;
		}
	}

	if (sum == 0)
	{
		sum = -1;
		cout << sum;
	}
	else
	{
		minValue = *min_element(odds.begin(), odds.end());
		cout << sum << '\n' << minValue;
	}

	return 0;
}