#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n = 0;
	queue<int> q;

	cin >> n;

	// ť ä���
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (q.size() > 1)
	{
		// �켱 ���� ���� �ִ� ī�带 ������.
		q.pop();

		// ���� ���� �ִ� ī�带 ���� �Ʒ��� �ű��. (push �ѵ� pop)
		q.push(q.front());
		q.pop();
	}

	cout << q.front() << '\n';

	return 0;
}