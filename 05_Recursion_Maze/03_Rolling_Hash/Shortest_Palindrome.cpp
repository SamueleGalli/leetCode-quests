/*
You are given a string s. You can convert s to a palindrome by adding characters in front of it.

Return the shortest palindrome you can find by performing this transformation.



Example 1:

    Input: s = "aacecaaa"
    Output: "aaacecaaa"

Example 2:

    Input: s = "abcd"
    Output: "dcbabcd"


Constraints:

* 0 <= s.length <= 5 * 10^4
* s consists of lowercase English letters only.
*/

using namespace std;

#include <iostream>
#include <algorithm>

class Solution
{
private:
    int MOD = 1000000007;

public:
    string shortestPalindrome(string s)
    {
        long long order = 0;
        long long inverted = 0;
        long long base = 1;
        size_t start = s.size();
        string attach;

        for (size_t i = 0; i < s.size(); i++)
        {
            order = ((order * 31) + s[i]) % MOD;
            inverted = ((base * s[i]) + inverted) % MOD;
            if (inverted == order)
                start = i + 1;
            base = (base * 31) % MOD;
        }
        if (start == 0)
            return (s);
        attach = s.substr(start);
        reverse(attach.begin(), attach.end());
        s = attach + s;
        return (s);
    }
};

int main()
{
    Solution s;
    string word;
    string result;

    word = "aacecaaa";
    result = s.shortestPalindrome(word);
    cout << "result = " << result << endl;

    word = "abcd";
    result = s.shortestPalindrome(word);
    cout << "result = " << result << endl;
}