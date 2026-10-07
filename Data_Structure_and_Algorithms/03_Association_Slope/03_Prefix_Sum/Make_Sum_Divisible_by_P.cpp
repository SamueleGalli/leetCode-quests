/*
Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.

Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.

A subarray is defined as a contiguous block of elements in the array.



Example 1:

    Input: nums = [3,1,4,2], p = 6
    Output: 1
        Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.

Example 2:

    Input: nums = [6,3,5,2], p = 9
    Output: 2
        Explanation: We cannot remove a single element to get a sum divisible by 9. The best way is to remove the subarray [5,2], leaving us with [6,3] with sum 9.

Example 3:

    Input: nums = [1,2,3], p = 3
    Output: 0
        Explanation: Here the sum is 6. which is already divisible by 3. Thus we do not need to remove anything.


Constraints:

* 1 <= nums.length <= 10^5
* 1 <= nums[i] <= 10^9
* 1 <= p <= 10^9
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

/*
(nums[i] - nums[j]) % p = r
(fine - inizio) % (nel range p) = (resto totale)
formula invertita
(nums[i] % p) -(nums[j] % p) = r
(-1) * (-(nums[j] % p)) = (-(nums[i] % p) + r) * (-1)
nums[j] * p = nums[i] * p - r
sum = (nums[i] % p) - total_remind;
per normalizzare
sum = ((nums[i] % p) - total_remind + p) % p
*/

class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        unordered_map<int, int> reminder;
        long int prefix_sum, total;
        int total_remind, sum, distance;

        total = 0;

        for (size_t i = 0; i < nums.size(); i++)
            total += nums[i];

        if (total % p == 0)
            return (0);

        total_remind = total % p;
        reminder[0] = -1;
        prefix_sum = 0;
        distance = p;

        for (size_t i = 0; i < nums.size(); i++)
        {
            prefix_sum += nums[i];
            sum = ((prefix_sum % p) - total_remind + p) % p;

            if (reminder.count(sum))
                distance = min(distance, static_cast<int>(i) - reminder[sum]);

            reminder[prefix_sum % p] = static_cast<int>(i);
        }

        if (static_cast<size_t>(distance) == nums.size())
            return (-1);

        return (distance);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int p;
    int result;

    nums = {3, 1, 4, 2};
    p = 6;
    result = s.minSubarray(nums, p);
    cout << "\n\nresult = " << result << "\n\n";

    nums = {6, 3, 5, 2};
    p = 9;
    result = s.minSubarray(nums, p);
    cout << "\n\nresult = " << result << "\n\n";

    nums = {1, 2, 3};
    p = 3;
    result = s.minSubarray(nums, p);
    cout << "\n\nresult = " << result << "\n\n";

    nums = {1, 8, 2, 5};
    p = 7;
    result = s.minSubarray(nums, p);
    cout << "\n\nresult = " << result << "\n\n";

    nums = {5};
    p = 7;
    result = s.minSubarray(nums, p);
    cout << "\n\nresult = " << result << "\n\n";

    nums = {4, 5};
    p = 6;
    result = s.minSubarray(nums, p);
    cout << "\n\nresult = " << result << "\n\n";

    nums = {1000000000, 1000000000, 1000000000};
    p = 3;
    result = s.minSubarray(nums, p);
    cout << "\n\nresult = " << result << "\n\n";
}
