#include <iostream>
using namespace std;

int main()
{
	int input = 0;

	while (true)
	{
		cin >> input;

		if (input == 0)
		{
			break;
		}

		for (int i = 1; i < 10; ++i)
		{
			cout << input << " X " << i << " = " << input * i << '\n';
		}
	}

	return 0;
}