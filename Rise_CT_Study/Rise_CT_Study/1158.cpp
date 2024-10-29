#include <iostream>
#include <list>
using namespace std;

int N, K;

int main()
{
	cin >> N >> K;

	list<int> circle;

	for (int i = 1; i <= N; i++)
	{
		circle.push_back(i);
	}

	list<int>::iterator iter = circle.begin();

	cout << '<';

	while (!circle.empty())
	{
		for (int i = 0; i < K - 1; i++)
		{
			iter++;

			if (iter == circle.end())
			{
				iter = circle.begin();
			}
		}

		cout << *iter;

		iter = circle.erase(iter);

		if (iter == circle.end()) 
		{
			iter = circle.begin();
		}

		if (!circle.empty()) 
		{
			cout << ", ";
		}
	}

	cout << '>';

	return 0;
}