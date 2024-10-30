#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int N = 0;
	stack<int> s;

	cin >> N;

	while (N--)
	{
		string command;

		cin >> command;

		if (command == "push")
		{
			int input;
			cin >> input;

			s.push(input);
		}
		else if (command == "pop")
		{
			if (!s.empty())
			{
				cout << s.top() << '\n';
				s.pop();
			}
			else
			{
				cout << -1 << '\n';
			}
		}
		else if (command == "size")
		{
			cout << s.size() << '\n';;
		}
		else if (command == "empty")
		{
			if (!s.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << 1 << '\n';
			}
		}
		else if (command == "top")
		{
			if (!s.empty())
			{
				cout << s.top() << '\n';
			}
			else
			{
				cout << -1 << '\n';
			}
		}

	}

	return 0;

}