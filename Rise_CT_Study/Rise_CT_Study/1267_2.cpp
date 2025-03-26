#include <iostream>
using namespace std;

int n, input, ySum, mSum;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;

		ySum += (input / 30 + 1) * 10;
		mSum += (input / 60 + 1) * 15;
	}

	if (ySum < mSum)
	{
		cout << "Y " << ySum;
	}
	else if (ySum > mSum)
	{
		cout << "M " << mSum;
	}
	else
	{
		cout << "Y M " << ySum;
	}

	return 0;
}