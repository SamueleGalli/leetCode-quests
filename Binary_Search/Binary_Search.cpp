/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

    Input: nums = [-1,0,3,5,9,12], target = 9
    Output: 4
        Explanation: 9 exists in nums and its index is 4

Example 2:

    Input: nums = [-1,0,3,5,9,12], target = 2
    Output: -1
        Explanation: 2 does not exist in nums so return -1


Constraints:

* 1 <= nums.length <= 10^4
* -10^4 < nums[i], target < 10^4
* All the integers in nums are unique.
* nums is sorted in ascending order.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = static_cast<int>(nums.size()) - 1;
        int med;
        while (low <= high)
        {
            med = (low + high) / 2;
            if (nums[med] == target)
                return (med);
            else if (nums[med] < target)
                low = med + 1;
            else
                high = med - 1;
        }
        return (-1);
    }
};

void test(vector<int> &nums, int target, int excepted)
{
    Solution s;
    int result = s.search(nums, target);
    cout << "result(" << result << ") -> excepted(" << excepted << ")\n\n";
}

int main()
{
    vector<int> nums;

    test(nums = {-1, 0, 3, 5, 9, 12}, 9, 4);
    test(nums = {-1, 0, 3, 5, 9, 12}, 2, -1);
    test(nums = {-1}, 3, -1);
    test(nums = {-1}, -1, 0);
    test(nums = {5}, 2, -1);
}