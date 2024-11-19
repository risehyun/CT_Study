#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 출력 배열을 채우는 재귀 함수
void drawTriangle(vector<string>& canvas, int x, int y, int size) 
{
    if (size == 3) 
    { // 기본 삼각형 패턴
        canvas[x][y] = '*';
        canvas[x + 1][y - 1] = '*';
        canvas[x + 1][y + 1] = '*';
        for (int i = -2; i <= 2; ++i) 
        {
            canvas[x + 2][y + i] = '*';
        }
        return;
    }

    int half = size / 2;
    // 위쪽 삼각형
    drawTriangle(canvas, x, y, half);
    // 아래 왼쪽 삼각형
    drawTriangle(canvas, x + half, y - half, half);
    // 아래 오른쪽 삼각형
    drawTriangle(canvas, x + half, y + half, half);
}

int main() 
{
    int N;
    cin >> N;

    // 출력용 2D 배열 초기화
    vector<string> canvas(N, string(2 * N - 1, ' '));

    // 재귀적으로 삼각형 그리기
    drawTriangle(canvas, 0, N - 1, N);

    // 결과 출력
    for (const auto& line : canvas) 
    {
        cout << line << '\n';
    }

    return 0;
}