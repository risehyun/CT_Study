#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n = 0;
	queue<int> q;

	cin >> n;

	// 큐 채우기
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (q.size() > 1)
	{
		// 우선 제일 위에 있는 카드를 버린다.
		q.pop();

		// 제일 위에 있는 카드를 제일 아래로 옮긴다. (push 한뒤 pop)
		q.push(q.front());
		q.pop();
	}

	cout << q.front() << '\n';

	return 0;
}