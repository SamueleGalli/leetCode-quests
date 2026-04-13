/*
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.



Example 1:

    Input: nums = [4,3,2,7,8,2,3,1]
    Output: [5,6]

Example 2:

    Input: nums = [1,1]
    Output: [2]



Constraints:

    * n == nums.length
    * 1 <= n <= 105
    * 1 <= nums[i] <= n



Follow up: Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/

using namespace std;

#include <vector>
#include <iostream>

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> result;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[abs(nums[i]) - 1] > 0)
                nums[abs(nums[i]) - 1] *= -1;
        }
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                result.push_back(i + 1);
        }
        return (result);
    }
};

void print_array(const vector<int> &result)
{
    cout << "\n--------------------------\nresult{";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < result.size())
            cout << " , ";
    }
    cout << "}\n-----------------------------------\n";
}

int main()
{
    Solution s;
    vector<int> result;
    vector<int> nums;

    nums = {1, 1};
    result = s.findDisappearedNumbers(nums);
    print_array(result);

    
    nums = {4, 3, 2, 7, 8, 2, 3, 1};
    result = s.findDisappearedNumbers(nums);
    print_array(result);
}