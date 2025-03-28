#include <iostream>
using namespace std;

int n;

int main()
{

	cin >> n;

	for (int y = 0; y < n; y++)
	{
        for (int x = 0; x < n - y; x++)
        {
            cout << " ";
        }
        for (int x = 0; x < y; x++)
        {
            cout << "*";
        }
		cout << '\n';
	}

	return 0;
}