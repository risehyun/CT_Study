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
		cout << input << "월은 봄입니다.";
		break;

	case 6:
	case 7:
	case 8:
		cout << input << "월은 여름입니다.";
		break;

	case 9:
	case 10:
	case 11:
		cout << input << "월은 가을입니다.";
		break;

	case 12:
	case 1:
	case 2:
		cout << input << "월은 겨울입니다.";
		break;

	default:
		cout << "잘못된 숫자를 입력했습니다.";
		break;
	}


	return 0;
}