#include <iostream>
#include <string>
using namespace std;

int main()
{
	string input = "", result = "";
	int n = 0;
	int bucket[26] = { 0, };

	cin >> n;

	while (n--)
	{
		cin >> input;
		bucket[input[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (bucket[i] >= 5)
		{
			result += i + 'a';
		}
	}

	if (result.size())
	{
		cout << result << '\n';
	}
	else
	{
		cout << "PREDAJA" << '\n';
	}

	return 0;
}