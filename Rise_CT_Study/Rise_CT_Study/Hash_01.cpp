/*
    [해시] 폰켓몬
*/

#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> type;

    for (int i = 0; i < nums.size(); i++) 
    {
        type.insert(nums[i]);
    }

    if (nums.size() / 2 < type.size())
    {
        answer = nums.size() / 2;
    }
    else
    {
        answer = type.size();
    }

    return answer;
}