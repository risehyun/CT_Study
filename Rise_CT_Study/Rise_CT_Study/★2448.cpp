#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ��� �迭�� ä��� ��� �Լ�
void drawTriangle(vector<string>& canvas, int x, int y, int size) 
{
    if (size == 3) 
    { // �⺻ �ﰢ�� ����
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
    // ���� �ﰢ��
    drawTriangle(canvas, x, y, half);
    // �Ʒ� ���� �ﰢ��
    drawTriangle(canvas, x + half, y - half, half);
    // �Ʒ� ������ �ﰢ��
    drawTriangle(canvas, x + half, y + half, half);
}

int main() 
{
    int N;
    cin >> N;

    // ��¿� 2D �迭 �ʱ�ȭ
    vector<string> canvas(N, string(2 * N - 1, ' '));

    // ��������� �ﰢ�� �׸���
    drawTriangle(canvas, 0, N - 1, N);

    // ��� ���
    for (const auto& line : canvas) 
    {
        cout << line << '\n';
    }

    return 0;
}