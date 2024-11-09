#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 0;
	cin >> n;

	while (n--)
	{
		stack<char> s;
		string input = "";
		int flag = 0;

		cin >> input;

		for (char c : input)
		{
			if (c == ')')
			{
				if (!s.empty())
				{
					s.pop();
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else
			{
				s.push(c);
			}
		}

		if (!s.empty() || flag == 1)
		{
			cout << "NO" << '\n';
		}
		else
		{
			cout << "YES" << '\n';
		}

	}

	return 0;
}