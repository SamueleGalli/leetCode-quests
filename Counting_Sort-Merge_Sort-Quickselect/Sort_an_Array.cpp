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

/*
TODO Merge sort (Ricorsione di sottoarray da unire)*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
    }
};

void print_vector(const vector<int> &nums)
{
    cout << "nums = {";
    for (size_t i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << endl;
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
}