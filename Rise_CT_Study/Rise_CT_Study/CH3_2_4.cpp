#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int binaryToDecimal(const string& binary)
{
	int decimal = 0;
	int length = binary.length();

	for (int i = 0; i < length; ++i)
	{
		// 뒤에서부터 체크하면서 2의 자릿수 제곱 연산을 한 결과를 하나씩 더함
		if (binary[length - i - 1] == '1')
		{
			decimal += pow(2, i);
		}
	}

	return decimal;
}

string decimalToBinary(int decimal)
{

	string binary = "";

	while (decimal > 0)
	{
		binary = to_string(decimal % 2) + binary;
		decimal /= 2;
	}

	return binary.empty() ? "0" : binary;
}

int main()
{
	int choice = 0;

	cout << "1. 2진수를 10진수로 변환\n";
	cout << "2. 10진수를 2진수로 변환\n";
	cout << "선택하세요 : ";
	cin >> choice;

	if (choice == 1)
	{
		string binary = "";
		cout << "2진수를 입력하세요: ";
		cin >> binary;

		int decimal = binaryToDecimal(binary);
		cout << "10진수 : " << decimal << endl;
	}
	else if (choice == 2)
	{
		int decimal = 0;
		cout << "10진수를 입력하세요 : ";
		cin >> decimal;

		string binary = decimalToBinary(decimal);
		cout << "2진수 : " << binary << endl;
	}
	else
	{
		cout << "잘못된 선택입니다." << endl;
	}

	return 0;
}