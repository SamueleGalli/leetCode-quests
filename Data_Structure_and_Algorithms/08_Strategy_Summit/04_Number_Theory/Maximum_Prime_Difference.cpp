/*
You are given an integer array nums.
Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.

Example 1:

    Input: nums = [4,2,9,5,3]
    Output: 3
        Explanation: nums[1], nums[3], and nums[4] are prime. So the answer is |4 - 1| = 3.

Example 2:

    Input: nums = [4,8,2,8]
    Output: 0
        Explanation: nums[2] is prime. Because there is just one prime number, the answer is |2 - 2| = 0.

Constraints:

* 1 <= nums.length <= 3 * 105
* 1 <= nums[i] <= 100
* The input is generated such that the number of prime numbers in the nums is at least one.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <math.h>
/*
There are two approaches to this problem:
* The easiest but slower approach is to check the remainder of the division from 2 to nums[i]
* The more efficient approach is to use the square root of nums[i] and check the remainder from 2 to the square root
*/

class Solution
{
private:
    bool is_prime(int num)
    {
        for (int factor = 2; static_cast<float>(factor) <= sqrt(num); factor++)
        {
            if (num % factor == 0)
                return (false);
        }
        return (true);
    }

public:
    int maximumPrimeDifference(vector<int> &nums)
    {
        int end = -1;
        int start = -1;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (is_prime(nums[i]) && nums[i] != 1)
            {
                if (start == -1)
                    start = static_cast<int>(i);
                else
                    end = static_cast<int>(i);
            }
        }
        if (start != -1 && end != -1)
            return (end - start);
        return (0);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int result;

    nums = {4, 2, 9, 5, 3};
    result = s.maximumPrimeDifference(nums);
    cout << "result = " << result << "\n\n";

    nums = {4, 8, 2, 8};
    result = s.maximumPrimeDifference(nums);
    cout << "result = " << result << "\n\n";

    nums = {1, 7};
    result = s.maximumPrimeDifference(nums);
    cout << "result = " << result << "\n\n";

    nums = {2, 2};
    result = s.maximumPrimeDifference(nums);
    cout << "result = " << result << "\n\n";
}