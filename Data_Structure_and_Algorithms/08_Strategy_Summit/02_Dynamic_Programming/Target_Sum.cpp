/*
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:

    Input: nums = [1,1,1,1,1], target = 3
    Output: 5
        Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
        -1 + 1 + 1 + 1 + 1 = 3
        +1 - 1 + 1 + 1 + 1 = 3
        +1 + 1 - 1 + 1 + 1 = 3
        +1 + 1 + 1 - 1 + 1 = 3
        +1 + 1 + 1 + 1 - 1 = 3

Example 2:

    Input: nums = [1], target = 1
    Output: 1

Constraints:

* 1 <= nums.length <= 20
* 0 <= nums[i] <= 1000
* 0 <= sum(nums[i]) <= 1000
* -1000 <= target <= 1000
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        unordered_map<int, int> cases;
        unordered_map<int, int> temp;

        target = abs(target);

        cases[abs(nums[0])]++;
        cases[-abs(nums[0])]++;

        for (size_t i = 1; i < nums.size(); i++)
        {
            temp.clear();
            for (pair<const int, int> &this_case : cases)
            {
                int sum = this_case.first;
                temp[sum + abs(nums[i])] += this_case.second;
                temp[sum - abs(nums[i])] += this_case.second;
            }
            cases = temp;
        }
        return (cases[target]);
    }
};

int main()
{
    Solution s;
    int result;
    int target;
    vector<int> nums;

    nums = {1, 1, 1, 1, 1};
    target = 3;
    result = s.findTargetSumWays(nums, target);
    cout << "result = " << result << endl;

    nums = {1};
    target = 1;
    result = s.findTargetSumWays(nums, target);
    cout << "result = " << result << endl;

    nums = {1, 2, 3, 4};
    target = 4;
    result = s.findTargetSumWays(nums, target);
    cout << "result = " << result << endl;
}