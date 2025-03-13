#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int bucket[4] = { 0, };
	int count = 0;
	int turn = 3;

	while (turn--)
	{

		for (int i = 0; i < 4; i++)
		{
			cin >> bucket[i];

			if (bucket[i] == 0)
			{
				count++;
			}
		}

		switch (count)
		{
		case 0:
			cout << 'E' << '\n';
			break;

		case 1:
			cout << 'A' << '\n';
			break;

		case 2:
			cout << 'B' << '\n';
			break;

		case 3:
			cout << 'C' << '\n';
			break;

		case 4:
			cout << 'D' << '\n';
			break;
		}

		count = 0;

	}

	return 0;
}