#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board;

void fillPattern(int x, int y, int size) 
{
    if (size == 1) 
    { // 기저 사례: 1x1 영역에 별 하나
        board[x][y] = '*';
        return;
    }

    int newSize = size / 3; // 다음 크기
    for (int i = 0; i < 3; ++i) 
    {
        for (int j = 0; j < 3; ++j) 
        {
            if (i == 1 && j == 1) 
            {
                // 가운데 영역은 공백 처리
                continue;
            }
            // 나머지 8개 영역에 대해 재귀 호출
            fillPattern(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main() 
{
    int N;
    cin >> N;

    // N x N 보드 초기화
    board.resize(N, vector<char>(N, ' '));

    // 패턴 생성
    fillPattern(0, 0, N);

    // 결과 출력
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
