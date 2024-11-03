#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    while (t--)
    {
        string p;
        int n;
        string arr;
        deque<int> dq;
        bool isReversed = false;  // ������ ����
        bool error = false;

        cin >> p >> n >> arr;

        // �迭 �Է� �Ľ�
        stringstream ss(arr.substr(1, arr.size() - 2));
        string num;
        while (getline(ss, num, ',')) {
            if (!num.empty()) dq.push_back(stoi(num));
        }

        // �Լ� ����
        for (char cmd : p) {
            if (cmd == 'R') {
                isReversed = !isReversed;
            }
            else if (cmd == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (isReversed) {
                    dq.pop_back();
                }
                else {
                    dq.pop_front();
                }
            }
        }

        // ��� ���
        if (error) {
            cout << "error\n";
        }
        else {
            cout << '[';
            while (!dq.empty()) {
                if (isReversed) {
                    cout << dq.back();
                    dq.pop_back();
                }
                else {
                    cout << dq.front();
                    dq.pop_front();
                }
                if (!dq.empty()) cout << ',';
            }
            cout << "]\n";
        }
    }

    return 0;
}