/*
You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.
Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

Example 1:

    Input: n = 12, k = 3
    Output: 3
        Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.

Example 2:

    Input: n = 7, k = 2
    Output: 7
        Explanation: Factors list is [1, 7], the 2nd factor is 7.

Example 3:

    Input: n = 4, k = 4
    Output: -1
        Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.

Constraints:

* 1 <= k <= n <= 1000

Follow up:

* Could you solve this problem in less than O(n) complexity?
*/

using namespace std;

#include <iostream>

/*
if i need to do in the normal way (n % i) where i go from 1 to n
the optimized way first i reduce the value n / i(1 to n) than do the opposite n * i and generate(i,n * i) factors
*/
class Solution
{
public:
    int kthFactor(int n, int k)
    {
        pair<int, int> possibility;
        int divisor = n;

        for (size_t i = 1; divisor > 0; i++)
        {
            divisor = n / i;
            possibility = {i, divisor};
        }
        return (-1);
    }
};

int main()
{
    Solution s;
    int n;
    int k;
    int result;

    n = 12;
    k = 3;
    result = s.kthFactor(n, k);
    cout << "result = " << result << endl;

    n = 7;
    k = 2;
    result = s.kthFactor(n, k);
    cout << "result = " << result << endl;

    n = 4;
    k = 4;
    result = s.kthFactor(n, k);
    cout << "result = " << result << endl;
}