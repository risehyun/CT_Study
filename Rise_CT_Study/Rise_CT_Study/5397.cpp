#include <iostream>
#include <list>
#include <string>
using namespace std;

int main()
{
	int testcase = 0;
	cin >> testcase;

	while (testcase--)
	{
		string str;
		cin >> str;

		list<char> inputs;
		list<char>::iterator cursor = inputs.end();

		for (char ch : str)
		{
			if (ch == '<' && cursor != inputs.begin())
			{
				cursor--;
			}
			else if (ch == '>' && cursor != inputs.end())
			{
				cursor++;
			}
			else if (ch == '-' && cursor != inputs.begin())
			{
				cursor--;
				cursor = inputs.erase(cursor);
			}
			else
			{
				inputs.insert(cursor, ch);
			}
		}

		for (char ch : inputs)
		{
			cout << ch;
		}

		cout << '\n';

	}

	return 0;
}