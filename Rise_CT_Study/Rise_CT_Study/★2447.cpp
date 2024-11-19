#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board;

void fillPattern(int x, int y, int size) 
{
    if (size == 1) 
    { // ���� ���: 1x1 ������ �� �ϳ�
        board[x][y] = '*';
        return;
    }

    int newSize = size / 3; // ���� ũ��
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (i == 1 && j == 1) 
            {
                // ��� ������ ���� ó��
                continue;
            }
            // ������ 8�� ������ ���� ��� ȣ��
            fillPattern(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main() 
{
    int N;
    cin >> N;

    // N x N ���� �ʱ�ȭ
    board.resize(N, vector<char>(N, ' '));

    // ���� ����
    fillPattern(0, 0, N);

    // ��� ���
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}
