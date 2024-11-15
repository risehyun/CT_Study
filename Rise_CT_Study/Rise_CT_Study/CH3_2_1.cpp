#include <iostream>
using namespace std;

int main()
{
	int my_array[] = { 1, 2, 3, 4, 5, 4, 3, 2, 1 };

	int maxIndex = sizeof(my_array) / sizeof(int);

	for (int i = 0; i < maxIndex; i++)
	{
		cout << my_array[i];
	}

	return 0;
}