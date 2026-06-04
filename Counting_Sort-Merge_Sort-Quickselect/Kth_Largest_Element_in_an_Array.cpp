/*
Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?



Example 1:

    Input: nums = [3,2,1,5,6,4], k = 2
    Output: 5

Example 2:

    Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
    Output: 4

Constraints:

* 1 <= k <= nums.length <= 10^5
* -10^4 <= nums[i] <= 10^4
*/

/*
TODO fixare l'ulitmo errore
TODO dare un occhi a quicksort
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        if (nums.empty() || k > static_cast<int>(nums.size()) || k < 1)
            return (0);

        int j = nums.size() - 1, i = 0;
        srand(time(nullptr));

        while (1)
        {
            if (i >= j)
                return (nums[i]);
            int pivot = nums[(rand() % (j - i + 1)) + i];
            while (1)
            {
                while (nums[i] < pivot)
                    i++;
                while (nums[j] > pivot)
                    j--;
                if (i >= j)
                    break;
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
            if (j < nums.size() - k)
                i = i + 1;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int k;
    int result;

    nums = {3, 2, 1, 5, 6, 4};
    k = 2;
    result = s.findKthLargest(nums, k);
    cout << "result = " << result << endl;

    nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    k = 4;
    result = s.findKthLargest(nums, k);
    cout << "result = " << result << endl;

    nums = {-1, -1};
    k = 2;
    result = s.findKthLargest(nums, k);
    cout << "result = " << result << endl;

    nums = {};
    k = 2;
    result = s.findKthLargest(nums, k);
    cout << "result = " << result << endl;

    nums = {-1, -2, 3, 50};
    k = 8;
    result = s.findKthLargest(nums, k);
    cout << "result = " << result << endl;
}