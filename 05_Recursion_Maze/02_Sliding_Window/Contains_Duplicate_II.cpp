/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.



Example 1:

    Input: nums = [1,2,3,1], k = 3
    Output: true

Example 2:

    Input: nums = [1,0,1,1], k = 1
    Output: true

Example 3:

    Input: nums = [1,2,3,1,2,3], k = 2
    Output: false


Constraints:

* 1 <= nums.length <= 105
* -109 <= nums[i] <= 109
* 0 <= k <= 105
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_set<int> seen;
        int left = 0;
        int right = 0;
        while (right < static_cast<int>(nums.size()))
        {
            if (right - left > k)
            {
                seen.erase(nums[left]);
                left++;
            }
            else
            {
                if (seen.count(nums[right]))
                    return (true);
                seen.insert(nums[right]);
                right++;
            }
        }
        return (false);
    }
};

void testcase(vector<int> &nums, int k, bool excepted)
{
    Solution s;
    bool result;

    result = s.containsNearbyDuplicate(nums, k);
    if (result == excepted)
        cout << "correct result\n";
    else
        cout << "incorrect result excepted ( " << excepted << ")\n";
}

int main()
{
    vector<int> nums;

    testcase(nums = {1, 2, 3, 1}, 3, true);

    testcase(nums = {1, 0, 1, 1}, 1, true);

    testcase(nums = {1, 2, 3, 1, 2, 3}, 2, false);
}