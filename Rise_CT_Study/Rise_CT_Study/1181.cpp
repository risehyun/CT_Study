#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(string str1, string str2)
{
	// ���̰� ���� ��� ���� ������ �����ϰ�
	if (str1.size() == str2.size())
	{
		return str1 < str2;
	}
	// ���̰� �ٸ� ��� ª�� ������ �����Ѵ�.
	else
	{
		return str1.size() < str2.size();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n = 0;
	cin >> n;

	vector<string> str;
	string input;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		str.push_back(input);
	}

	sort(str.begin(), str.end(), compare);
	str.erase(unique(str.begin(), str.end()), str.end());

	vector<string>::iterator iter;

	for (iter = str.begin(); iter != str.end(); ++iter)
	{
		cout << *iter << '\n';
	}

	return 0;
}