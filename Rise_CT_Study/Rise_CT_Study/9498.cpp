#include <iostream>

using namespace std;

int score;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> score;

	if (score >= 90 && score <= 100)
	{
		cout << 'A';
	}
	else if (score >= 89 && score <= 80)
	{
		cout << 'B';
	}
	else if (score >= 79 && score <= 70)
	{
		cout << 'C';
	}
	else if (score >= 69 && score <= 60)
	{
		cout << 'D';
	}
	else
	{
		cout << 'F';
	}

	return 0;
}