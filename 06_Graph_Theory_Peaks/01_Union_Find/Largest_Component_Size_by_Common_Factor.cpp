/*
You are given an integer array of unique positive integers nums. Consider the following graph:

There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

Example 1:

    Input: nums = [4,6,15,35]
    Output: 4

Example 2:


    Input: nums = [20,50,9,63]
    Output: 2

Example 3:

    Input: nums = [2,3,6,7,4,12,21,39]
    Output: 8


Constraints:

* 1 <= nums.length <= 2 * 10^4
* 1 <= nums[i] <= 10^5
* All the values of nums are unique.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    int largestComponentSize(vector<int> &nums)
    {
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int result;

    nums = {4, 6, 15, 35};
    result = s.largestComponentSize(nums);
    cout << "result = " << result << endl;

    nums = {20, 50, 9, 63};
    result = s.largestComponentSize(nums);
    cout << "result = " << result << endl;

    nums = {2, 3, 6, 7, 4, 12, 21, 39};
    result = s.largestComponentSize(nums);
    cout << "result = " << result << endl;
}