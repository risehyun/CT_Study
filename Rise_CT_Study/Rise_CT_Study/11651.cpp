#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int>> points;
pair<int, int> point;
int n;

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> point.second >> point.first;
		points.push_back(point);
	}

	sort(points.begin(), points.end());

	for (int i = 0; i < n; i++)
	{
		cout << points[i].second << ' ' << points[i].first << '\n';
	}

	return 0;
}