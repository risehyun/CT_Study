#include <iostream>
#include <cmath>

int main()
{
	int sum = 0;

	for (int i = 1; i < 100; ++i)
	{
		sum += pow(i, 2);
	}

	std::cout << sum;

	return 0;
}