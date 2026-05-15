/*
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.



Example 1:

    Input: nums = [1,2,0]
    Output: 3
        Explanation: The numbers in the range [1,2] are all in the array.

Example 2:

    Input: nums = [3,4,-1,1]
    Output: 2
        Explanation: 1 is in the array but 2 is missing.

Example 3:

    Input: nums = [7,8,9,11,12]
    Output: 1
        Explanation: The smallest positive integer 1 is missing.


Constraints:

* 1 <= nums.length <= 10^5
* -2^31 <= nums[i] <= 2^31 - 1
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int val = 0;
        size_t i = 0;
        while (i < nums.size())
        {
            if ((nums[i] > 0 && static_cast<size_t>(nums[i]) <= nums.size()) &&
            nums[i] != nums[nums[i] - 1])
            {
                val = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = val;
            }
            else
                i++;
        }
        val = 1;
        i = 0;
        while (i < nums.size())
        {
            if (nums[i] != val)
                break;
            i++;
            val++;
        }
        return (val);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int result;

    nums = {1, 2, 0};
    result = s.firstMissingPositive(nums);
    cout << "result = " << result << endl;

    nums = {3, 4, -1, 1};
    result = s.firstMissingPositive(nums);
    cout << "result = " << result << endl;

    nums = {7, 8, 9, 11, 12};
    result = s.firstMissingPositive(nums);
    cout << "result = " << result << endl;

    nums = {101, 112, 9, 11, 12};
    result = s.firstMissingPositive(nums);
    cout << "result = " << result << endl;

    nums = {1, 1};
    result = s.firstMissingPositive(nums);
    cout << "result = " << result << endl;
}