#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int K = 0, sum = 0;
	cin >> K;

	stack<int> s;

	while (K--)
	{
		int input = 0;
		cin >> input;

		if (input == 0 && !s.empty())
		{
			s.pop();
		}
		else
		{
			s.push(input);
		}
	}

	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}

	cout << sum;

	return 0;
}