#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<vector<int>> image;

bool check(int x, int y, int size) 
{
    int target = image[x][y];
    for (int i = x; i < x + size; ++i) 
    {
        for (int j = y; j < y + size; ++j) 
        {
            if (image[i][j] != target) 
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
        cout << image[x][y];
        return;
    }

    // ������ 4����Ͽ� ��������� ȣ��
    int newSize = size / 2;
    cout << "(";
    solve(x, y, newSize); // �»��
    solve(x, y + newSize, newSize); // ����
    solve(x + newSize, y, newSize); // ���ϴ�
    solve(x + newSize, y + newSize, newSize); // ���ϴ�
    cout << ")";
}

int main() {
    cin >> n;
    image.resize(n, vector<int>(n));

    for (int i = 0; i < n; ++i) 
    {
        string line;
        cin >> line;
        for (int j = 0; j < n; ++j) 
        {
            image[i][j] = line[j] - '0';
        }
    }

    solve(0, 0, n);

    return 0;
}
