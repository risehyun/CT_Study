#include <iostream>
using namespace std;

int main()
{
	
	char my_string[] = "Hello\0, World!";

	// char�� 1����Ʈ�̱� ������ / sizeof(char)�� ���� �ʿ䰡 X
	int maxIndex = sizeof(my_string);

	for (int i = 0; i < maxIndex; i++)
	{
		if (my_string[i] == '\0')
		{
			break;
		}

		cout << my_string[i];
	}
	cout << endl;


	// �ε����� ������� �ʾƵ� null ���� ���η� �ݺ����� ���� ���� �ִ�.
	for (int i = 0; my_string[i] != '\0'; i++)
	{
		cout << my_string[i];
	}
	cout << endl;

	int i = 0;

	// '\0'�� �ݵ�� �������� ����ȴٸ� sizeof(my_string)�� �������� ���� �ʾƵ� �ȴ�.
	while (my_string[i] != '\0')
	{
		cout << my_string[i];
		i++;
	}

	/*
	int i = 0;

	while (true)
	{
		if (i > 9)
		{
			break;
		}
		else
		{
			cout << i << ' ';
		}

		i++;
	}
	*/

	return 0;
}