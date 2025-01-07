#include <iostream>
using namespace std;

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
int tmp[1000001]; // merge �Լ����� ����Ʈ 2���� ��ģ ����� �ӽ÷� �����ϰ� ���� ����

// mid = (st+en)/2��� �� �� arr[st:mid], arr[mid:en]�� �̹� ������ �Ǿ��ִ� ������ �� arr[st:mid]�� arr[mid:en]�� ��ģ��.
void merge(int st, int en) 
{
	int mid = (st + en) / 2;
	int lidx = st; // arr[st:mid]���� ���� ���� ���� ����ϴ� index
	int ridx = mid; // arr[mid:en]���� ���� ���� ���� ����ϴ� index

	for (int i = st; i < en; i++) 
	{
		if (ridx == en) tmp[i] = arr[lidx++];
		else if (lidx == mid) tmp[i] = arr[ridx++];
		else if (arr[lidx] <= arr[ridx]) tmp[i] = arr[lidx++];
		else tmp[i] = arr[ridx++];
	}
	for (int i = st; i < en; i++) arr[i] = tmp[i]; // tmp�� �ӽ������ص� ���� a�� �ٽ� �ű�
}

// arr[st:en]�� �����ϰ� �ʹ�.
void merge_sort(int st, int en) 
{
	if (en == st + 1)
	{
		return; // ���̰� 1�� ���
	}

	int mid = (st + en) / 2;
	merge_sort(st, mid); // arr[st:mid]�� �����Ѵ�.
	merge_sort(mid, en); // arr[mid:en]�� �����Ѵ�.
	merge(st, en); // arr[st:mid]�� arr[mid:en]�� ��ģ��.
}

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';  // -53 3 12 15 16 22 23 25 46 357

	return 0;
}