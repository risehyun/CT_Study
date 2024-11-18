#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> paper;
int cnt[3];

bool check(int x, int y, int size)
{
	int target = paper[x][y];

	for (int i = x; i < x + size; ++i)
	{
		for (int j = y; j < y + size; ++j)
		{
			if (paper[i][j] != target)
			{
				return false;
			}
		}
	}
	return true;
}

void solve(int x, int y, int size) 
{
	if (check(x, y, size))
	{
		if (paper[x][y] == -1)
		{
			++cnt[0];
		}
		else if (paper[x][y] == 0)
		{
			++cnt[1];
		}
		else
		{
			++cnt[2];
		}
	}
	else 
	{
		int newSize = size / 3;
		for (int i = 0; i < 3; ++i) 
		{
			for (int j = 0; j < 3; ++j) 
			{
				solve(x + i * newSize, y + j * newSize, newSize);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n = 0;
	cin >> n;

	paper.resize(n, vector<int>(n));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> paper[i][j];
		}
	}

	solve(0, 0, n);

	for (int i = 0; i < 3; ++i)
	{
		cout << cnt[i] << '\n';
	}

	return 0;
}