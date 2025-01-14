#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string name;
int kor, eng, math;

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<tuple<int, int, int, string>> students;
    while (N--) {
        cin >> name >> kor >> eng >> math;
        students.push_back({ -kor, eng, -math, name });
    }
    sort(students.begin(), students.end());
    for (auto& s : students)
        cout << get<3>(s) << '\n';
}