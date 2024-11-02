#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

void push(int x)
{
	q.push(x);
}

void pop()
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

void size()
{
	cout << q.size() << '\n';
}

void empty()
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

void front()
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

void back()
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

int main()
{
	int N = 0;
	cin >> N;

	while (N--)
	{
		string command = "";
		cin >> command;

		if (command == "push")
		{
			int input = 0;
			cin >> input;

			push(input);
		}
		else if (command == "pop")
		{
			pop();
		}
		else if (command == "size")
		{
			size();
		}
		else if (command == "front")
		{
			front();
		}
		else if (command == "back")
		{
			back();
		}
		else
		{
			empty();
		}
	}

	return 0;
}