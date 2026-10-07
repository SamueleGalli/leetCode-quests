/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:

    Input: nums = [1,2,3,1]
    Output: 4
        Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
        Total amount you can rob = 1 + 3 = 4.

Example 2:

    Input: nums = [2,7,9,3,1]
    Output: 12
        Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
        Total amount you can rob = 2 + 9 + 1 = 12.

Constraints:

* 1 <= nums.length <= 100
* 0 <= nums[i] <= 400
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    vector<int> memo;
    int get_next_max(size_t i, const vector<int> &nums)
    {
        if (i >= nums.size())
            return (0);

        if (memo[i] > -1)
            return (memo[i]);

        int max_found = max(nums[i] + get_next_max(i + 2, nums),
                            get_next_max(i + 1, nums));
        memo[i] = max_found;
        return (max_found);
    }

public:
    int rob(vector<int> &nums)
    {
        memo.clear();
        memo.resize(nums.size(), -1);
        return (get_next_max(0, nums));
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int result;

    nums = {1, 2, 3, 1};
    result = s.rob(nums);
    cout << "result = " << result << endl;

    nums = {2, 7, 9, 3, 1};
    result = s.rob(nums);
    cout << "result = " << result << endl;

    nums = {10, 1, 1, 10};
    result = s.rob(nums);
    cout << "result = " << result << endl;

    nums = {114, 117, 207, 117, 235, 82, 90, 67, 143, 146, 53, 108, 200, 91, 80, 223, 58, 170, 110, 236, 81, 90, 222, 160, 165, 195, 187, 199, 114, 235, 197, 187, 69, 129, 64, 214, 228, 78, 188, 67, 205, 94, 205, 169, 241, 202, 144, 240};
    result = s.rob(nums);
    cout << "result = " << result << endl;
}