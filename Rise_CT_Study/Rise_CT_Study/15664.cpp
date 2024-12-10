#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> input; // 입력 배열
vector<int> arr; // 선택한 수열
vector<bool> isUsed; // 사용 여부 확인용

void func(int level, int start)
{
	if (level == m) // 수열의 길이가 M이면 출력
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int last_used = -1; // 같은 레벨에서 이전에 선택한 수를 저장
	for (int i = start; i < n; i++)
	{
		if (!isUsed[i] && input[i] != last_used) // 사용하지 않았고 이전에 선택한 값과 다른 경우만 선택
		{
			arr[level] = input[i];
			isUsed[i] = true;
			func(level + 1, i);
			isUsed[i] = false;
			last_used = input[i]; // 현재 선택한 값을 last_used에 저장
		}
	}
}

int main()
{
	cin >> n >> m;

	input.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
	}

	sort(input.begin(), input.end());

	arr.resize(m); // 수열의 길이는 M
	isUsed.resize(n); // 새로운 크기의 isUsed 배열 초기화

	func(0, 0); // 0번째부터 시작
	return 0;
}
