/*
Given two strings a and b, return the minimum number of times you should repeat string a so that string b is a substring of it. If it is impossible for b​​​​​​ to be a substring of a after repeating it, return -1.

Notice: string "abc" repeated 0 times is "", repeated 1 time is "abc" and repeated 2 times is "abcabc".



Example 1:

    Input: a = "abcd", b = "cdabcdab"
    Output: 3
        Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

Example 2:

    Input: a = "a", b = "aa"
    Output: 2



Constraints:

    * 1 <= a.length, b.length <= 104
    * a and b consist of lowercase English letters.

*/

using namespace std;

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Solution
{
public:
    int repeatedStringMatch(string a, string b)
    {
        string total = a;
        size_t r = 1;
        while (total.size() < b.size())
        {
            total += a;
            r++;
        }
        if (r > 0 && total.find(b) != string::npos)
            return (static_cast<int>(r));
        else if ((total += a).find(b) != string::npos)
            return (static_cast<int>(r + 1));
        else if ((total += a).find(b) != string::npos)
            return (static_cast<int>(r + 2));
        return (-1);
    }
};

struct testcase
{
    string a;
    string b;
    int result;
};

int main()
{
    Solution s;
    int result;

    vector<testcase> test =
        {
            {"a", "aa", 2},
            {"a", "ba", -1},
            {"a", "a", 1},
            {"a", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", 78},
            {"aa", "a", 1},
            {"ba", "ab", 2},
            {"abc", "cabc", 2},
            {"abc", "cabcabca", 4},
            {"abc", "abcabcabcabd", -1},
            {"abc", "abcabcabcabcabc", 5},
            {"abcd", "cdabcdab", 3},
            {"abcd", "abcdabcdabcdabcd", 4},
            {"abcde", "eab", 2},
        };

    for (testcase t : test)
    {
        result = s.repeatedStringMatch(t.a, t.b);
        if (result == t.result)
            cout << "this test is correct(" << result << ")";
        else
            cout << "incorrect answer(" << result << ")";
        cout << "\n---------------------------------------\n";
    }
}
