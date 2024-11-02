#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	queue<int> q;

	int n = 0;
	string command = "";

	cin >> n;

	while (n--)
	{
		cin >> command;

		if (command == "push")
		{
			int input = 0;
			cin >> input;

			q.push(input);
		}
		else if (command == "pop")
		{
			if (!q.empty())
			{
				cout << q.front() << '\n';
				q.pop();
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else if (command == "size")
		{
			cout << q.size() << '\n';
		}
		else if (command == "empty")
		{
			if (!q.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << 1 << '\n';
			}
		}
		else if (command == "front")
		{
			if (!q.empty())
			{
				cout << q.front() << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else if (command == "back")
		{
			if (!q.empty())
			{
				cout << q.back() << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}