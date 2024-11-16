#include <iostream>
#include <random>
using namespace std;

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 99);

	int number = distrib(gen);

	while (true)
	{
		cout << "입력 : ";

		int answer = 0;
		cin >> answer;

		if (answer > number)
		{
			cout << "너무 커요!" << '\n';
		}
		else if (answer < number)
		{
			cout << "너무 작아요!" << '\n';
		}
		else
		{
			cout << "정답!";
			break;
		}
	}

	return 0;
}