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
		cout << "�Է� : ";

		int answer = 0;
		cin >> answer;

		if (answer > number)
		{
			cout << "�ʹ� Ŀ��!" << '\n';
		}
		else if (answer < number)
		{
			cout << "�ʹ� �۾ƿ�!" << '\n';
		}
		else
		{
			cout << "����!";
			break;
		}
	}

	return 0;
}