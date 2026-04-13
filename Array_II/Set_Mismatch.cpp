/*
You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.

You are given an integer array nums representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return them in the form of an array.



Example 1:

    Input: nums = [1,2,2,4]
    Output: [2,3]

Example 2:

    Input: nums = [1,1]
    Output: [1,2]



Constraints:

    * 2 <= nums.length <= 10^4
    * 1 <= nums[i] <= 10^4
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> result;
        int order = 1;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i + 1 < nums.size(); i++)
        {
            if (nums[i] == nums[i + 1])
                result.push_back(nums[i]);
            if (order == nums[i])
                order++;
        }
        if (order == nums[nums.size() - 1])
            order++;
        result.push_back(order);
        return (result);
    }
};

void print_array(const vector<int> &result)
{
    cout << "number duplicated = " << result[0] << endl;
    cout << "number missing = " << result[1] << endl;
    cout << "\n\n\n";
}

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> result;

    nums = {1, 2, 2, 4};
    result = s.findErrorNums(nums);
    print_array(result);

    nums = {1, 1};
    result = s.findErrorNums(nums);
    print_array(result);

    nums = {2, 2};
    result = s.findErrorNums(nums);
    print_array(result);

    nums = {3, 2, 2};
    result = s.findErrorNums(nums);
    print_array(result);

    nums = {3, 2, 3, 4, 6, 5};
    result = s.findErrorNums(nums);
    print_array(result);

    nums = {1,5,3,2,2,7,6,4,8,9};
    result = s.findErrorNums(nums);
    print_array(result);
}