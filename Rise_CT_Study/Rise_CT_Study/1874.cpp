#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 1;
	int n = 0;
	string result = "";

	stack<int> s;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int input = 0;
		
		cin >> input;

		while (cnt <= input)
		{
			s.push(cnt);
			cnt += 1;
			result += "+\n";
		}

		if (s.top() == input)
		{
			s.pop();
			result += "-\n";
		}
		else
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << result;

	return 0;

}