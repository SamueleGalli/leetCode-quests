/*
Given an integer array nums of length n, you want to create an array ans of length 2n where ans[i] == nums[i] and ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

Specifically, ans is the concatenation of two nums arrays.

Return the array ans.

 

Example 1:

    Input: nums = [1,2,1]
    Output: [1,2,1,1,2,1]
    Explanation: The array ans is formed as follows:
    - ans = [nums[0],nums[1],nums[2],nums[0],nums[1],nums[2]]
    - ans = [1,2,1,1,2,1]

Example 2:

    Input: nums = [1,3,2,1]
    Output: [1,3,2,1,1,3,2,1]
    Explanation: The array ans is formed as follows:
    - ans = [nums[0],nums[1],nums[2],nums[3],nums[0],nums[1],nums[2],nums[3]]
    - ans = [1,3,2,1,1,3,2,1]

 

Constraints:

    * n == nums.length
    * 1 <= n <= 1000
    * 1 <= nums[i] <= 1000

*/

using namespace std;

#include <vector>
#include <iostream>

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans;
        size_t i = 0;
        for (;i < nums.size();i++)
        {
            ans.push_back(nums[i]);
        }
        i = 0;
        for (;i < nums.size();i++)
        {
            ans.push_back(nums[i]);
        }
        return (ans);
    }
};

void print_array(vector<int> &result)
{
    cout << "result\n";
    for (size_t i = 0;i < result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "\n\n";
}

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> result;

    nums = {1,2,1};
    result = s.getConcatenation(nums);
    print_array(result);

    nums = {1,3,2,1};
    result = s.getConcatenation(nums);
    print_array(result);
}