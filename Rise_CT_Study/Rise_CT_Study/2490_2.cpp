#include <iostream>
using namespace std;

int result, input;
string res = "DCBAE";

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int r = 0; r < 3; r++)
	{
		result = 0;

		for (int c = 0; c < 4; c++)
		{
			cin >> input;
			result += input;
		}
		cout << res[result] << '\n';
	}

	return 0;
}