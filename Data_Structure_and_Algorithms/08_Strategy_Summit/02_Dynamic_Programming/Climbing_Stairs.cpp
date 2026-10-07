/*
You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

    Input: n = 2
    Output: 2
        Explanation: There are two ways to climb to the top.
        1. 1 step + 1 step
        2. 2 steps

Example 2:

    Input: n = 3
    Output: 3
        Explanation: There are three ways to climb to the top.
        1. 1 step + 1 step + 1 step
        2. 1 step + 2 steps
        3. 2 steps + 1 step

Constraints:

* 1 <= n <= 45
*/

/*
Explanation step(n) = step(n - 1) + step(n - 2)
    exemple:
        * step_1 = 1;
        * step_2 = 2;
    step(4) = step(3) + ste(2);
    so:
        * step_1 = 2;
        * step_2 = 3;
*/

using namespace std;

#include <iostream>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return (1);
        else if (n == 2)
            return (2);

        int first_case = 1;
        int second_case = 2;
        int result = 0;

        for (int step = 2; step < n; step++)
        {
            result = (first_case + second_case);

            first_case = second_case;
            second_case = result;
        }
        return (result);
    }
};

int main()
{
    int result;
    int n;
    Solution s;

    n = 2;
    result = s.climbStairs(n);
    cout << "result = " << result << endl;

    n = 3;
    result = s.climbStairs(n);
    cout << "result = " << result << endl;

    n = 4;
    result = s.climbStairs(n);
    cout << "result = " << result << endl;

    n = 44;
    result = s.climbStairs(n);
    cout << "result = " << result << endl;
}