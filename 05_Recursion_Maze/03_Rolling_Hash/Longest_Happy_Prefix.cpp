/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Given a string s, return the longest happy prefix of s. Return an empty string "" if no such prefix exists.

Example 1:

    Input: s = "level"
    Output: "l"
        Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

Example 2:

    Input: s = "ababab"
    Output: "abab"
        Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

Constraints:

* 1 <= s.length <= 10^5
* s contains only lowercase English letters.
*/

using namespace std;

#include <iostream>

class Solution
{
private:
    int MOD = 1000000007;

public:
    string longestPrefix(string s)
    {
        long long ordered = 0;
        long long inverted = 0;
        long long base = 1;
        size_t j = s.size() - 1;
        size_t i = 0;
        size_t start = s.size();
        while (i < s.size() - 1)
        {
            ordered = ((ordered * 31) + s[i]) % MOD;
            inverted = ((s[j] * base) + inverted) % MOD;
            if (ordered == inverted)
                start = i;
            base = (base * 31) % MOD;
            i++;
            j--;
        }
        if (start == s.size())
            return ("");
        return (s.substr(0, start + 1));
    }
};

int main()
{
    Solution s;
    string word;
    string result;

    word = "level";
    result = s.longestPrefix(word);
    cout << "result = " << result << endl;

    word = "abab";
    result = s.longestPrefix(word);
    cout << "result = " << result << endl;

    word = "ababab";
    result = s.longestPrefix(word);
    cout << "result = " << result << endl;

    word = "a";
    result = s.longestPrefix(word);
    cout << "result = " << result << endl;
}