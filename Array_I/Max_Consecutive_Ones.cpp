/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.



Example 1:

    Input: nums = [1,1,0,1,1,1]
    Output: 3
    tion: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:

    Input: nums = [1,0,1,1,0,1]
    Output: 2



Constraints:

    * 1 <= nums.length <= 105
    * nums[i] is either 0 or 1.

*/

using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int occurence = 0;
        int result = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                occurence++;
            else
            {
                result = max(result, occurence);
                occurence = 0;
            }
        }
        result = max(result, occurence);
        return (result);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int result;

    nums = {1, 1, 0, 1, 1, 1};
    result = s.findMaxConsecutiveOnes(nums);
    cout << "reuslt = " << result << "\n\n\n";

    nums = {1, 0, 1, 1, 0};
    result = s.findMaxConsecutiveOnes(nums);
    cout << "reuslt = " << result << "\n\n\n";
}