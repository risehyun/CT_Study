#include <iostream>
#include <deque>
using namespace std;

int main()
{
	int N = 0;
	deque<int> d;
	string command = "";
	
	cin >> N;

	while (N--)
	{
		cin >> command;

		if (command == "push_front")
		{
			int input = 0;
			cin >> input;

			d.push_front(input);
		}
		else if (command == "push_back")
		{
			int input = 0;
			cin >> input;

			d.push_back(input);
		}
		else if (command == "pop_front")
		{
			if (!d.empty())
			{
				cout << d.front() << '\n';
				d.pop_front();
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else if (command == "pop_back")
		{
			if (!d.empty())
			{
				cout << d.back() << '\n';
				d.pop_back();
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else if (command == "size")
		{
			cout << d.size() << '\n';
		}
		else if (command == "empty")
		{
			if (!d.empty())
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
			if (!d.empty())
			{
				cout << d.front() << '\n';
			}
			else 
			{
				cout << -1 << '\n';
			}
		}
		else if (command == "back")
		{
			if (!d.empty())
			{
				cout << d.back() << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}
	}

	return 0;
}