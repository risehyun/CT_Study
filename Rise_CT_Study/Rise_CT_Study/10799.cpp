#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<char> s;
	string input;
	int count = 0;

	cin >> input;

	for (size_t i = 0; i < input.length(); ++i)
	{
		if (input[i] == '(')
		{
			s.push(input[i]);
		}
		else // ´Ý´Â °ýÈ£ÀÎ °æ¿ì
		{
			s.pop();

			if (input[i - 1] == '(')
			{
				count += s.size();
			}
			else
			{
				count++;
			}
		}
	}

	cout << count;


	return 0;
}