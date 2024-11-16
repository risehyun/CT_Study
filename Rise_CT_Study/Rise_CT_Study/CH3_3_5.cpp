#include <iostream>
using namespace std;

int main()
{
	string str = "";

	cin >> str;

	int length = str.length();
	int idx = length - 1;

	for (int i = 0; i < length; ++i)
	{
		if (str[i] != str[idx])
		{
			cout << "False";
			return 0;
		}
		idx--;
	}

	cout << "True";

	return 0;
}