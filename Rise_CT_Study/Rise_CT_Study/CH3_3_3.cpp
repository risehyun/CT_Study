#include <iostream>
using namespace std;

int main()
{
	int input = 0;
	cin >> input;

	switch (input)
	{
	case 3 :
	case 4:
	case 5:
		cout << input << "���� ���Դϴ�.";
		break;

	case 6:
	case 7:
	case 8:
		cout << input << "���� �����Դϴ�.";
		break;

	case 9:
	case 10:
	case 11:
		cout << input << "���� �����Դϴ�.";
		break;

	case 12:
	case 1:
	case 2:
		cout << input << "���� �ܿ��Դϴ�.";
		break;

	default:
		cout << "�߸��� ���ڸ� �Է��߽��ϴ�.";
		break;
	}


	return 0;
}