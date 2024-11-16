#include <iostream>

int main()
{
	int scores[] = { 20, 40, 80, 60, 99 };
	int maxIndex = sizeof(scores) / sizeof(scores[0]);
	float avg = 0.0f;

	for (int i = 0; i < maxIndex; i++)
	{
		avg += scores[i];
	}

	avg /= maxIndex;

	std::cout << avg;

	return 0;
}