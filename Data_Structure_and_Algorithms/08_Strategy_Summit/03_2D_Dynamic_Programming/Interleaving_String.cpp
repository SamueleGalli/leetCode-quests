/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

Example 1:

    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
    Output: true
        Explanation: One way to obtain s3 is:
        Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
        Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
        Since s3 can be obtained by interleaving s1 and s2, we return true.

Example 2:

    Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
    Output: false
        Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.

Example 3:

    Input: s1 = "", s2 = "", s3 = ""
    Output: true


Constraints:

* 0 <= s1.length, s2.length <= 100
* 0 <= s3.length <= 200
* s1, s2, and s3 consist of lowercase English letters.


* Follow up: Could you solve it using only O(s2.length) additional memory space?
*/

using namespace std;

#include <iostream>
#include <vector>

/*
There are two main ways to solve this problem:
    * Top-Down = the classic slower approach, using recursion with i and j.
    * Bottom-Up = the optimized approach, with less memory, using the previous values from i - 1 and j - 1.

The latter is the one I have studied more carefully, using the three strings like a map with rows and columns, where each cell uses previous values to perform the new check
If there is a mismatch at position (i, j), that path becomes invalid, so all the cells from j to the end of s2 become invalid for that row
*/

class Solution
{
private:
    vector<bool> memo;

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return (false);
        size_t pos = 0;

        vector<bool> memo(s2.size() + 1, false);
        memo[0] = true;

        for (size_t i = 0; i <= s1.size(); i++)
        {
            for (size_t j = 0; j <= s2.size(); j++)
            {
                if (i == 0 && j == 0)
                    continue;

                pos = i + j - 1;

                if ((i > 0 && memo[j] && s1[i - 1] == s3[pos]) ||
                    (j > 0 && memo[j - 1] && s2[j - 1] == s3[pos]))
                    memo[j] = true;
                else
                    memo[j] = false;
            }
        }
        return (memo[s2.size()]);
    }
};

void testcase(string s1, string s2, string s3)
{
    Solution s;
    bool result;

    result = s.isInterleave(s1, s2, s3);
    cout << boolalpha << "result = " << result << endl;
}

int main()
{
    testcase("aabcc", "dbbca", "aadbbcbcac");
    testcase("aabcc", "dbbca", "aadbbbaccc");
    testcase("a", "", "a");
    testcase("", "", "");
}