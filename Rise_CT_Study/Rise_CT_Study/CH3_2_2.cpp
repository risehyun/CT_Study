#include <iostream>
using namespace std;

int main()
{
	
	char my_string[] = "Hello\0, World!";

	// char는 1바이트이기 때문에 / sizeof(char)를 해줄 필요가 X
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


	// 인덱스를 사용하지 않아도 null 문자 여부로 반복문을 돌릴 수도 있다.
	for (int i = 0; my_string[i] != '\0'; i++)
	{
		cout << my_string[i];
	}
	cout << endl;

	int i = 0;

	// '\0'이 반드시 존재함이 보장된다면 sizeof(my_string)을 조건으로 걸지 않아도 된다.
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