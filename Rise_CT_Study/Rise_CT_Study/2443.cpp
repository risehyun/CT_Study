#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = n; i > 0; i--) 
    {
        for (int j = 0; j < n - i; j++) 
        {
            cout << ' ';
        }

        int star = i;

        for (int k = 0; k < 2 * i - 1; k++) 
        {
            cout << "*";
        }

        cout << '\n';

    }

	return 0;
}