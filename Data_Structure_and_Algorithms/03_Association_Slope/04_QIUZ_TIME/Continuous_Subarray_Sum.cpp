/*
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

its length is at least two, and
the sum of the elements of the subarray is a multiple of k.
Note that:

A subarray is a contiguous part of the array.
An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.


Example 1:

    Input: nums = [23,2,4,6,7], k = 6
    Output: true
        Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

Example 2:

    Input: nums = [23,2,6,4,7], k = 6
    Output: true
        Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
        42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

Example 3:

    Input: nums = [23,2,6,4,7], k = 13
    Output: false


Constraints:

* 1 <= nums.length <= 10^5
* 0 <= nums[i] <= 10^9
* 0 <= sum(nums[i]) <= 2^31 - 1
* 1 <= k <= 2^31 - 1
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int sum = 0;
        unordered_map<int, int> sub;

        if (nums.size() > 1)
        {
            sub[0] = -1;
            for (size_t i = 0; i < nums.size(); i++)
            {
                sum += nums[i];
                if (sub.count(sum % k) &&
                    static_cast<int>(i) - sub[sum % k] > 1)
                    return (true);
                if (!sub.count(sum % k))
                    sub[sum % k] = static_cast<size_t>(i);
            }
        }
        return (false);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int k;
    bool result;

    nums = {23, 2, 4, 6, 7};
    k = 6;
    result = s.checkSubarraySum(nums, k);
    cout << boolalpha << "result = " << result << "\n\n";

    nums = {23, 2, 6, 4, 7};
    k = 6;
    result = s.checkSubarraySum(nums, k);
    cout << boolalpha << "result = " << result << "\n\n";

    nums = {23, 2, 6, 4, 7};
    k = 13;
    result = s.checkSubarraySum(nums, k);
    cout << boolalpha << "result = " << result << "\n\n";

    nums = {7};
    k = 7;
    result = s.checkSubarraySum(nums, k);
    cout << boolalpha << "result = " << result << "\n\n";

    nums = {1, 0};
    k = 2;
    result = s.checkSubarraySum(nums, k);
    cout << boolalpha << "result = " << result << "\n\n";

    nums = {5, 0, 0, 0};
    k = 3;
    result = s.checkSubarraySum(nums, k);
    cout << boolalpha << "result = " << result << "\n\n";
}