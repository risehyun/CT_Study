#include <iostream>
#include <vector>
using namespace std;

int main() 
{

    int my_array[] = { 1, 2, 3, 4, 5, 4, 3, 1, 2 };
    int size = sizeof(my_array)/sizeof(my_array[0]);

    vector<int> result;

    for (int i = 1; i < size; ++i) 
    {
        // �����ϴ� ������ ������ ã��
        if (my_array[i] > my_array[i - 1]) 
        {
            // �ߺ� ���� �߰��ϴ� ���� ���� ���� ����ó��
            if (result.empty() || result.back() != my_array[i - 1]) 
            {
                result.push_back(my_array[i - 1]); // ���� ���� �߰�
            }
            result.push_back(my_array[i]); // ���� ���� �߰�
        }
    }

    // ��� ���
    for (int num : result) 
    {
        cout << num << " ";
    }

    return 0;
}