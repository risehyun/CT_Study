#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers;
int input;
int sumValue;
int minValue = 101;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 7; i++)
	{
		cin >> input;

		if (input % 2 == 1)
		{
			numbers.push_back(input);
			sumValue += input;

			if (input < minValue)
			{
				minValue = input;
			}
		}
	}

	if (sumValue == 0)
	{
		cout << -1;
	}
	else
	{
		cout << sumValue << '\n';
		cout << minValue << '\n';
	}

	return 0;
}