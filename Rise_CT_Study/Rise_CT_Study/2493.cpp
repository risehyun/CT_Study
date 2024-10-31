#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	vector<int> input(N);
	vector<int> result(N, 0);
	stack<pair<int, int>> s;

	for (int i = 0; i < N; i++)
	{
		cin >> input[i];

		// pop �ϱ� ������ empty üũ ���ֱ�
		while (!s.empty() && s.top().first < input[i])
		{
			s.pop();
		}

		if (!s.empty())
		{
			result[i] = s.top().second + 1;
		}

		s.push({ input[i], i });
	}

	for (int i = 0; i < N; i++) 
	{
		cout << result[i] << " ";
	}

	return 0;

}