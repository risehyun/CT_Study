#include <iostream>
using namespace std;

int freq[2000001];
int n;
int num;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		freq[num + 1000000]++;
	}

	for (int i = 0; i <= 2000000; i++) 
	{
		while (freq[i]--) 
		{ // cnt[i]¹ø ¹Ýº¹
			cout << i - 1000000 << '\n';
		}
	}

	return 0;
}
