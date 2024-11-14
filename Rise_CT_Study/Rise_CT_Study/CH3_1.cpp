// 초를 시분초로 바꾸어 출력

#include <iostream>
using namespace std;

int main()
{
	int input = 0, h = 0, m = 0, s = 0;

	cin >> input;

	h = input / 3600;
	input = input % 3600;

	m = input / 60;
	input = input % 60;

	s = input;

	if (h > 0)
	{
		cout << h << "시간 ";
	}
	if (m > 0)
	{
		cout << m << "분 ";
	}
	if (s > 0)
	{
		cout << s << "초";
	}

	return 0;
}