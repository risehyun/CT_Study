// �ʸ� �ú��ʷ� �ٲپ� ���

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
		cout << h << "�ð� ";
	}
	if (m > 0)
	{
		cout << m << "�� ";
	}
	if (s > 0)
	{
		cout << s << "��";
	}

	return 0;
}