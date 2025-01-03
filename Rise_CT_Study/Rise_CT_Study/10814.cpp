// stable_sort = https://modoocode.com/323

#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int n;

vector<pair<int, string>> members;
pair<int, string> member;

bool compare(pair<int, string>a, pair<int, string>b)
{
	return a.first < b.first;
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> member.first >> member.second;

		members.push_back(member);
	}

	stable_sort(members.begin(), members.end(), compare);

	for (int i = 0; i < n; i++)
	{
		cout << members[i].first << ' ' << members[i].second << '\n';
	}

	return 0;
}