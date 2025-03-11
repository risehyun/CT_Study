#include <iostream>

using namespace std;

int score;

void print(int _score)
{
	if (_score >= 90 && _score <= 100)
	{
		cout << 'A';
	}
	else if (_score >= 80 && _score <= 89)
	{
		cout << 'B';
	}
	else if (_score >= 70 && _score <= 79)
	{
		cout << 'C';
	}
	else if (_score >= 60 && _score <= 69)
	{
		cout << 'D';
	}
	else
	{
		cout << 'F';
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> score;

	print(score);

	return 0;
}