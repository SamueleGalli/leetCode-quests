/*
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:

    Input: c = 5
    Output: true
        Explanation: 1 * 1 + 2 * 2 = 5

Example 2:

Input: c = 3
Output: false

Constraints:

* 0 <= c <= 2^31 - 1
*/

using namespace std;

#include <iostream>
#include <cmath>

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long int high, med, low;
        int target;
        int num = sqrt(c);

        for (int take = 0; take <= num; take++)
        {
            target = c - (take * take);
            low = 0;
            high = sqrt(target);
            while (low <= high)
            {
                med = (low + high) / 2;
                if (med * med > target)
                    high = med - 1;
                else if (med * med < target)
                    low = med + 1;
                else
                    return (true);
            }
        }
        return (false);
    }
};

int main()
{
    Solution s;
    int c;
    bool result;

    c = 5;
    result = s.judgeSquareSum(c);
    cout << boolalpha << result << "\n--------------------------------------------------------------------\n\n";

    c = 3;
    result = s.judgeSquareSum(c);
    cout << boolalpha << result << "\n--------------------------------------------------------------------\n\n";

    c = 40;
    result = s.judgeSquareSum(c);
    cout << boolalpha << result << "\n--------------------------------------------------------------------\n\n";

    c = 30;
    result = s.judgeSquareSum(c);
    cout << boolalpha << result << "\n--------------------------------------------------------------------\n\n";

    c = 110;
    result = s.judgeSquareSum(c);
    cout << boolalpha << result << "\n--------------------------------------------------------------------\n\n";

    c = 35553;
    result = s.judgeSquareSum(c);
    cout << boolalpha << result << "\n--------------------------------------------------------------------\n\n";

    c = 305000;
    result = s.judgeSquareSum(c);
    cout << boolalpha << result << "\n--------------------------------------------------------------------\n\n";

    c = 25;
    result = s.judgeSquareSum(c);
    cout << boolalpha << result << "\n--------------------------------------------------------------------\n\n";

    c = 99999999;
    result = s.judgeSquareSum(c);
    cout << boolalpha << result << "\n--------------------------------------------------------------------\n\n";
}