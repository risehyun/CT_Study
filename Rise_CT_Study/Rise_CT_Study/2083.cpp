#include <iostream>
using namespace std;

int main()
{
	string name = "";
	int age = 0;
	int kg = 0;

	while (true)
	{
		cin >> name >> age >> kg;

		if (name == "#" && age == 0 && kg == 0)
		{
			break;
		}

		if (age > 17 || kg >= 80)
		{
			cout << name << " Senior" << '\n';
		}
		else
		{
			cout << name << " Junior" << '\n';
		}

	}

	return 0;
}