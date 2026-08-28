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

//TODO calcola quanti blocchi sorpassare per ottimizzare e non andare in loop o overflow

class Solution
{
private:
    pair<bool, long long> in_range(long long start, int n, int k)
    {
        int size = 1;
        long long sub = 0;
        long long end = 0;

        while (size <= k && start <= n)
        {
            end = start + 9;
            sub = end - n;

            if (n <= end)
                size += 10 - sub;
            else if (end <= n)
                size += 10;

            if (start > n / 10)
                break;

            start *= 10;
        }
        return {size >= k, size};
    }

    int prefix_lexic(int &n, int k, long long start)
    {
        if (k == 0)
            return (start);

        long long prefix_size = in_range(start * 10, n, k).second;

        if (k < prefix_size)
        {
            for (int i = 0; i < 10; i++)
            {
                long long next_prefix = start * 10 + i;

                if (next_prefix > n)
                    break;

                pair<bool, long long> check_branch = in_range(next_prefix, n, k);

                if (check_branch.first)
                    return (prefix_lexic(n, k - 1, next_prefix));
                else
                    k -= check_branch.second;
            }
        }
        else
            return (prefix_lexic(n, k - prefix_size, start + 1));
        return (-1);
    }

public:
    int findKthNumber(int n, int k)
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

    /*     n = 13;
        k = 2;
        result = s.findKthNumber(n, k);
        cout << "result = " << result << endl;

        n = 1;
        k = 1;
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
    cout << "result = " << result << endl;*/

    n = 1000000000;
    k = 1000000000;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;
}