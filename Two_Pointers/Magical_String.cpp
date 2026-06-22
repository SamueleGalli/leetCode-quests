/*
A magical string s consists of only '1' and '2' and obeys the following rule:

Concatenating the sequence of lengths of its consecutive groups of identical characters '1' and '2' generates the string s itself.
The first few elements of s is s = "1221121221221121122……". If we group the consecutive 1's and 2's in s, it will be "1 22 11 2 1 22 1 22 11 2 11 22 ......" and counting the occurrences of 1's or 2's in each group yields the sequence "1 2 2 1 1 2 1 2 2 1 2 2 ......".

You can see that concatenating the occurrence sequence gives us s itself.

Given an integer n, return the number of 1's in the first n number in the magical string s.



Example 1:

Input: n = 6
Output: 3
Explanation: The first 6 elements of magical string s is "122112" and it contains three 1's, so return 3.
Example 2:

Input: n = 1
Output: 1


Constraints:

* 1 <= n <= 10^5
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int magicalString(int n)
    {
        string s = "122";
        s.reserve(n);
        int one = 1;
        size_t start = 0;
        size_t end = 2;
        while (s.size() < static_cast<size_t>(n))
        {
            int times = s[end] - '0';
            if (static_cast<int>(s.size()) + times > n)
                times--;
            if (s[start] == '1')
            {
                s.append(times, '1');
                one += times;
            }
            else
                s.append(times, '2');
            start++;
            end += times;
        }
        cout << "s = " << s << endl;
        return (one);
    }
};

int main()
{
    Solution s;
    int n;
    int result;

    n = 6;
    result = s.magicalString(n);
    cout << "result = " << result << endl;

    n = 1;
    result = s.magicalString(n);
    cout << "result = " << result << endl;

    n = 20;
    result = s.magicalString(n);
    cout << "result = " << result << endl;

    n = 10;
    result = s.magicalString(n);
    cout << "result = " << result << endl;

    n = 4;
    result = s.magicalString(n);
    cout << "result = " << result << endl;
}