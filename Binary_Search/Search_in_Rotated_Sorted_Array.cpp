/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly left rotated at an unknown index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be left rotated by 3 indices and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.



Example 1:

    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4

Example 2:

    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1

Example 3:

    Input: nums = [1], target = 0
    Output: -1

Constraints:

* 1 <= nums.length <= 5000
* -10^4 <= nums[i] <= 10^4
* All values of nums are unique.
* nums is an ascending array that is possibly rotated.
* -10^4 <= target <= 10^4
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
        int high = nums.size() - 1;
        int med;

        while (low <= high)
        {
            med = (low + high) / 2;
            if (nums[med] == target)
                return (med);
            else if (nums[low] <= nums[med])
            {
                if (target <= nums[med] && target >= nums[low])
                    high = med - 1;
                else
                    low = med + 1;
            }
            else
            {
                if (target <= nums[high] && target >= nums[med])
                    low = med + 1;
                else
                    high = med - 1;
            }
        }
        return (-1);
    }
};

void tescase(vector<int> &nums, int target, int excepted)
{
    Solution s;
    int result = s.search(nums, target);
    cout << "result = (" << result << ") excepted = (" << excepted << ")\n\n";
}

int main()
{
    vector<int> nums;

    tescase(nums = {4, 5, 6, 7, 0, 1, 2}, 0, 4);
    tescase(nums = {4, 5, 6, 7, 0, 1, 2}, 3, -1);
    tescase(nums = {1}, 0, -1);
    tescase(nums = {-1}, -1, 0);
    tescase(nums = {9, 10, 12, -1, 0, 2, 4, 5, 6, 7}, 6, 8);
    tescase(nums = {9, 10, 12, -1, 0, 2, 4, 5, 6, 7}, -1, 3);
}