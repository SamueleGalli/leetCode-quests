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
If I need to do it in the normal way, I check (n % i)
where i goes from 1 to n.

In the optimized way I do these steps:
    * Find the total number of divisors.
    * Check both sides, left and right, simultaneously.
    * When I find the result, I return "i" for the left side and "n / i" for the right side.
    * If the cycle ends, I return -1.
    * The cycle ends when I have checked all the valid divisor pairs.
*/

class Solution
{
private:
    int give_total_divisor(int n, int total = 0)
    {
        for (int i = 1; n / i >= i; i++)
        {
            if (n % i != 0)
                continue;

            total++;
            if (n / i != i)
                total++;
        }
        return (total + 1);
    }

public:
    int kthFactor(int n, int k)
    {
        int left = 0;
        int right = give_total_divisor(n);

        for (int i = 1; i <= n; i++)
        {
            if (n % i != 0)
                continue;

            left++;
            right--;

            if (left == k)
                return (i);
            else if (right == k)
                return (n / i);
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

    n = 20;
    k = 4;
    result = s.kthFactor(n, k);
    cout << "result = " << result << endl;
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

    n = 24;
    k = 6;
    result = s.kthFactor(n, k);
    cout << "result = " << result << endl;
}