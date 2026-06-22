/*
Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

    Input: nums = [-1,2,1,-4], target = 1
    Output: 2
        Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:

    Input: nums = [0,0,0], target = 1
    Output: 0
        Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:

* 3 <= nums.length <= 500
* -1000 <= nums[i] <= 1000
* -10^4 <= target <= 10^4
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];

        for (size_t i = 0; i < nums.size() - 2; i++)
        {
            size_t left = i + 1;
            size_t right = nums.size() - 1;
            while (left < right)
            {
                int new_sum = nums[left] + nums[right] + nums[i];
                if (abs(new_sum - target) < abs(sum - target))
                    sum = new_sum;
                if (new_sum == target)
                    return (new_sum);
                else if (new_sum < target)
                {
                    left++;
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                }
                else
                {
                    right--;
                    while (left < right && nums[right + 1] == nums[right])
                        right--;
                }
            }
        }
        return (sum);
    }
};

void testcase(vector<int> &nums, int target, int excepted)
{
    Solution s;
    int result;
    if ((result = s.threeSumClosest(nums, target)) == excepted)
        cout << "Correct result\n";
    else
        cout << "Incorrect result (" << result << ")\n";
}

int main()
{
    vector<int> nums;

    testcase(nums = {-1, 2, 1, -4}, 1, 2);

    testcase(nums = {0, 0, 0}, 1, 0);
}