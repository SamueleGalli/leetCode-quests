/*
Given an integer array arr and an integer k, modify the array by repeating it k times.
For example, if arr = [1, 2] and k = 3 then the modified array will be [1, 2, 1, 2, 1, 2].
Return the maximum sub-array sum in the modified array. Note that the length of the sub-array can be 0 and its sum in that case is 0.
As the answer can be very large, return the answer modulo 10^9 + 7.

Example 1:

    Input: arr = [1,2], k = 3
    Output: 9

Example 2:

    Input: arr = [1,-2,1], k = 5
    Output: 2

Example 3:

    Input: arr = [-1,-2], k = 7
    Output: 0

Constraints:

* 1 <= arr.length <= 10^5
* 1 <= k <= 10^5
* -10^4 <= arr[i] <= 10^4
*/

using namespace std;

#include <iostream>
#include <vector>

/*
In this code i get the prefix and suffix sum by prefix_sum idea,
then the total sum,
finally temp and sum:
    * temp = parzial_max_range
    * temp = (current_element, current_element + previous_max_sum)
    * sum = total_max_range
    * sum = range_with_max_sum(sum, temp);

k == 1 (max in the subarray)
k == 2 (end + start or max in the subarray)
k > 2 (max in the subarray or end + start + whole block)

*/

class Solution
{
private:
    struct sum
    {
        int best_sum = 0;
        int left = 0;
        int right = 0;
    };

    int formatting(long long result)
    {
        return (result % 1000000007);
    }

public:
    int kConcatenationMaxSum(vector<int> &arr, int k)
    {
        sum Sum;
        int prefix_sum = 0;
        int suffix_sum = 0;
        int temp = 0;

        size_t j = arr.size() - 1;

        for (size_t i = 0; i < arr.size(); i++)
        {
            temp = max(arr[i], arr[i] + temp);
            Sum.best_sum = max(Sum.best_sum, temp);
            prefix_sum += arr[i];
            suffix_sum += arr[j--];
            Sum.left = max(suffix_sum, Sum.left);
            Sum.right = max(prefix_sum, Sum.right);
        }

        int half = Sum.left + Sum.right;
        long long big_chunk = 0;
        if (prefix_sum > 0)
            big_chunk = static_cast<long long>(prefix_sum) * (k - 2);

        if (k == 1)
            return (formatting(Sum.best_sum));
        else if (k == 2)
            return (formatting(max(Sum.best_sum, half)));
        else
            return (formatting(max(static_cast<long long>(Sum.best_sum), static_cast<long long>(half) + big_chunk)));
    }
};

int main()
{
    Solution s;
    vector<int> arr;
    int k;
    int result;

    arr = {1, 2};
    k = 3;
    result = s.kConcatenationMaxSum(arr, k);
    cout << "result = " << result << endl;

    arr = {1, -2, 1};
    k = 5;
    result = s.kConcatenationMaxSum(arr, k);
    cout << "result = " << result << endl;

    arr = {-11, -2};
    k = 7;
    result = s.kConcatenationMaxSum(arr, k);
    cout << "result = " << result << endl;

    arr = {10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000};
    k = 100000;
    result = s.kConcatenationMaxSum(arr, k);
    cout << "result = " << result << endl;
}