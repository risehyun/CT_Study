#include <iostream>
using namespace std;

void func1(int n)
{
	if (n == 0)
	{
		return;
	}

	cout << n << ' ';
	func1(n - 1);
}

int func2(int n)
{
	if (n == 0)
	{
		return 0;
	}
	return n + func2(n - 1);
}

int main()
{

	func1(5);
	int result = func2(5);

	cout << result;

	return 0;
}