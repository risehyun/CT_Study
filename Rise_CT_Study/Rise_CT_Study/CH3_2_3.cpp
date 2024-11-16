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
        // 증가하는 구간의 시작을 찾음
        if (my_array[i] > my_array[i - 1]) 
        {
            // 중복 값을 추가하는 것을 막기 위한 예외처리
            if (result.empty() || result.back() != my_array[i - 1]) 
            {
                result.push_back(my_array[i - 1]); // 이전 값을 추가
            }
            result.push_back(my_array[i]); // 현재 값을 추가
        }
    }

    // 결과 출력
    for (int num : result) 
    {
        cout << num << " ";
    }

    return 0;
}