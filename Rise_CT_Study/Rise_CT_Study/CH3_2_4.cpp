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
		// �ڿ������� üũ�ϸ鼭 2�� �ڸ��� ���� ������ �� ����� �ϳ��� ����
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

	cout << "1. 2������ 10������ ��ȯ\n";
	cout << "2. 10������ 2������ ��ȯ\n";
	cout << "�����ϼ��� : ";
	cin >> choice;

	if (choice == 1)
	{
		string binary = "";
		cout << "2������ �Է��ϼ���: ";
		cin >> binary;

		int decimal = binaryToDecimal(binary);
		cout << "10���� : " << decimal << endl;
	}
	else if (choice == 2)
	{
		int decimal = 0;
		cout << "10������ �Է��ϼ��� : ";
		cin >> decimal;

		string binary = decimalToBinary(decimal);
		cout << "2���� : " << binary << endl;
	}
	else
	{
		cout << "�߸��� �����Դϴ�." << endl;
	}

	return 0;
}