/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].


Example 1:

    Input: nums = [1,3,2,3,1]
    Output: 2
        Explanation: The reverse pairs are:
        (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
        (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1
Example 2:

    Input: nums = [2,4,3,5,1]
    Output: 3
        Explanation: The reverse pairs are:
        (1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
        (2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
        (3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1


Constraints:

* 1 <= nums.length <= 5 * 10^4
* -2^31 <= nums[i] <= 2^31 - 1
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    vector<int> give_me_total(vector<int> &left, vector<int> &right,
                              int &result, size_t i = 0, size_t j = 0, size_t k = 0)
    {
        vector<int> total(right.size() + left.size());
        while (i < left.size() && j < right.size())
        {
            if (left[i] > static_cast<long int>(right[j]) * 2)
            {
                result += static_cast<int>(left.size()) - i;
                j++;
            }
            else
                i++;
        }
        i = 0;
        j = 0;
        while (i < left.size() && j < right.size())
        {
            if (left[i] < right[j])
                total[k++] = left[i++];
            else
                total[k++] = right[j++];
        }
        while (i < left.size())
            total[k++] = left[i++];
        while (j < right.size())
            total[k++] = right[j++];
        return (total);
    }
    vector<int> pairs(size_t start, size_t end, vector<int> &nums, int &result)
    {
        if (start == end)
            return {nums[start]};

        size_t medium = (start + end ) / 2;
        vector<int> left = pairs(start, medium, nums, result);
        medium++;
        vector<int> right = pairs(medium, end, nums, result);

        return (give_me_total(left, right, result));
    }

public:
    int reversePairs(vector<int> &nums)
    {
        int result = 0;
        pairs(0, nums.size() - 1, nums, result);
        return (result);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int result;

    nums = {1, 3, 2, 3, 1};
    result = s.reversePairs(nums);
    cout << "result = " << result << endl;

    nums = {2, 4, 3, 5, 1};
    result = s.reversePairs(nums);
    cout << "result = " << result << endl;
}