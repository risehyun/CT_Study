#include <iostream>
using namespace std;

int main()
{
	int num = 1;

	for (int y = 0; y < 5; ++y)
	{
		for (int x = 0; x < y+1; x++)
		{
			cout << num << ' ';
			num++;
		}
		cout << '\n';
	}

	return 0;
}