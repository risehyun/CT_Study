#include <iostream>

using namespace std;

int year;
int result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> year;

	if (year % 4 == 0)
	{
		if ((year % 400 == 0) || (year % 100 != 0))
		{
			result = 1;
		}
	}

	cout << result;

	return 0;
}