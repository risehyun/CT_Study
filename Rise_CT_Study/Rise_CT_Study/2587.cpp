#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers(5);
int sumValue;
int avgValue;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for (int i = 0; i < 5; i++)
	{
		cin >> numbers[i];
		sumValue += numbers[i];
	}

	sort(numbers.begin(), numbers.end());

	avgValue = sumValue / 5;

	cout << avgValue << '\n';
	cout << numbers[2];

	return 0;
}