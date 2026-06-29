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
/*
TODO almost done
*/
class Solution
{
public:
    string shortestPalindrome(string s)
    {
        long long order = 0;
        long long inverted = 0;
        long long base = 1;
        int j = s.size() - 1;
        size_t start = 0;
        size_t i = 0;
        string attach;

        while (i < s.size() && j >= 0)
        {
            order = (order * 31) + s[i];
            inverted = inverted + (base * s[j]);
            if (inverted == order)
                start = i;
            i++;
            j--;
            base = base * 31;
        }
        attach = s.substr(start + 1);
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