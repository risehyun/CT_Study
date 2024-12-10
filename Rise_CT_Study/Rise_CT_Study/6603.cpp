#include <iostream>
using namespace std;

int k;
int input[20]; 
int arr[10];

void func(int cnt, int cur) 
{
    if (cnt == 6) 
    {
        for (int i = 0; i < 6; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = cur; i < k; i++) 
    {
        arr[cnt] = input[i];
        func(cnt + 1, i + 1);
    }
}

int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) 
    {
        cin >> k;

        if (k == 0)
        {
            break;
        }

        for (int i = 0; i < k; i++)
        {
            cin >> input[i];
        }

        func(0, 0);

        cout << '\n';
    }
}