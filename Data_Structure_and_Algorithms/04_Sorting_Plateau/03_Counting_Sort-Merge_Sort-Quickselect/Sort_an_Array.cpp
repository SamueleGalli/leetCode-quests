/*
Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:

    Input: nums = [5,2,3,1]
    Output: [1,2,3,5]
    Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

    Input: nums = [5,1,1,2,0,0]
    Output: [0,0,1,1,2,5]
    Explanation: Note that the values of nums are not necessarily unique.

Constraints:

* 1 <= nums.length <= 5 * 10^4
* -5 * 10^4 <= nums[i] <= 5 * 10^4
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    void merge(vector<int> &result, vector<int> &nums,
               size_t start, size_t end, size_t half)
    {
        size_t i = start;
        size_t right_start = half;
        size_t left_start = start;
        while (left_start < half && right_start < end)
        {
            if (nums[left_start] < nums[right_start])
                result[i++] = nums[left_start++];
            else
                result[i++] = nums[right_start++];
        }
        vector<int>::iterator it = copy(nums.begin() + left_start, nums.begin() + half, result.begin() + i);
        copy(nums.begin() + right_start, nums.begin() + end, it);
        copy(result.begin() + start, result.begin() + end, nums.begin() + start);
    }

    void merge_sort(vector<int> &result, vector<int> &nums,
                    size_t start, size_t end)
    {
        if (start + 1 >= end)
            return;
        size_t half = start + ((end - start) / 2);

        merge_sort(result, nums, start, half);
        merge_sort(result, nums, half, end);
        merge(result, nums, start, end, half);
    }

public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> result(nums.size(), 0);
        merge_sort(result, nums, 0, nums.size());
        return (nums);
    }
};

void print_vector(const vector<int> &nums)
{
    cout << "nums = {";
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i];
        if (i + 1 != nums.size())
            cout << ", ";
    }
    cout << "}\n\n";
}

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> result;

    nums = {5, 2, 3, 1};
    result = s.sortArray(nums);
    print_vector(nums);

    nums = {5, 1, 1, 2, 0, 0};
    result = s.sortArray(nums);
    print_vector(nums);

    nums = {};
    result = s.sortArray(nums);
    print_vector(nums);

    nums = {1, 2, 2, 2, 3, 3, 1};
    result = s.sortArray(nums);
    print_vector(nums);

    nums = {3, 2, 1};
    result = s.sortArray(nums);
    print_vector(nums);

    nums = {2, 2, 2};
    result = s.sortArray(nums);
    print_vector(nums);
}