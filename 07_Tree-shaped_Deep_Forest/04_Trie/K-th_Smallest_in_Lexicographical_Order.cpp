/*
Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

Example 1:

    Input: n = 13, k = 2
    Output: 10
        Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

    Input: n = 1, k = 1
    Output: 1

Constraints:
* 1 <= k <= n <= 10^9
*/

using namespace std;

#include <iostream>
#include <vector>

//TODO QUASI FATTO?
class Solution
{
private:
    pair<bool, long long> in_range(long long start, int n, int k)
    {
        long long size = 1;
        long long sub = 0;
        long long end = start;
        long long parzial = 0;

        while (size <= k && start <= n && start * 10 <= n)
        {
            start *= 10;
            end = (end * 10) + 9;
            sub = end - n;
            parzial = (end - start) + 1;

            if (n <= end)
                size += parzial - sub;
            else if (end <= n)
                size += parzial;
        }
        return {size >= k, size};
    }

    pair<long long, long long> valid_optimization(long long n, long long k, long long start, const long long &prefix_size)
    {
        long long to_go = 0;
        long long new_start = start + to_go;
        long long current_size = in_range(start, n, k).second;

        while (k > current_size)
        {
            to_go++;
            k -= current_size;
            start++;
            current_size = in_range(start, n, k).second;
        }

        while (n > 0 && n != new_start)
            n /= 10;

        if (to_go > 1 && n == new_start)
            to_go--;
        return {k - (to_go * prefix_size), start + to_go};
    }

    int prefix_lexic(int &n, int k, long long start)
    {
        if (k == 0)
            return (start);

        pair<bool, long long> check_branch = in_range(start, n, k);

        if (check_branch.first)
        {
            for (int i = 0; i < 10; i++)
            {
                long long next_prefix = start * 10 + i;

                if (next_prefix > n)
                    return (prefix_lexic(n, k - 1, start + 1));

                check_branch = in_range(next_prefix, n, k);

                if (check_branch.first)
                    return (prefix_lexic(n, k - 1, next_prefix));
                else
                    k -= check_branch.second;
            }
        }
        else
        {
            pair<long long, long long> optimize = valid_optimization(n, k - 1, start * 10, in_range(start * 10, n, k).second);
            return (prefix_lexic(n, optimize.first, optimize.second));
        }
        return (-1);
    }

public:
    int
    findKthNumber(int n, int k)
    {
        return (prefix_lexic(n, k - 1, 1));
    }
};

int main()
{
    Solution s;
    int result;
    int n;
    int k;

    n = 13;
    k = 2;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 1;
    k = 1;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 2;
    k = 2;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 10;
    k = 3;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 13;
    k = 11;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 25;
    k = 15;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 100;
    k = 90;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 100;
    k = 11;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 213;
    k = 100;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 999;
    k = 500;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 1000;
    k = 500;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 1000213;
    k = 50;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 523;
    k = 50;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 1000000000;
    k = 1000000000;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;
}