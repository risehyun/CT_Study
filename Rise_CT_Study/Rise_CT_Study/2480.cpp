#include <iostream>

using namespace std;

int main()
{
	int dice[7] = { 0, };
	int number = 0;
	int max = 0;
	int result = 0;

	for (int i = 0; i < 3; i++)
	{
		cin >> number;
		dice[number]++;
	}

	for (int i = 1; i < 7; i++)
	{
		if (dice[i] > 0)
		{
			max = i;
		}

		if (dice[i] == 3)
		{
			result = 10000 + i * 1000;
			break;
		}
		else if (dice[i] == 2)
		{
			result = 1000 + i * 100;
			break;
		}
	}

	if (result == 0)
	{
		result = max * 100;
	}

	cout << result;


	return 0;
}