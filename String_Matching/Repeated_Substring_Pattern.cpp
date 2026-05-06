/*
Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.



Example 1:

    Input: s = "abab"
    Output: true
        Explanation: It is the substring "ab" twice.

Example 2:

    Input: s = "aba"
    Output: false

Example 3:

    Input: s = "abcabcabcabc"
    Output: true
        Explanation: It is the substring "abc" four times or the substring "abcabc" twice.



Constraints:

    * 1 <= s.length <= 104
    * s consists of lowercase English letters.

*/
/*
Ho provato 3 metodi:
1)il mio metodo
2)il mio metodo ottimizzazione il piu possibile
3)e il KMP con Last prefix suffix
*/
using namespace std;

#include <string>
#include <iostream>
#include <vector>

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        vector<int> LPS(s.size(), 0);
        size_t len = 0;

        for (size_t i = 1; i < s.size();)
        {
            if (s[i] == s[len])
            {
                len++;
                LPS[i++] = len;
            }
            else
            {
                if (len > 0)
                    len = LPS[len - 1];
                else
                    i++;
            }
        }
        if (LPS.back() != 0 && s.size() % (s.size() - LPS.back()) == 0)
            return (true);
        else
            return (false);
    }
};

int main()
{
    Solution s;
    bool result;
    string word;

    word = "abab";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "aba";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "abcabcabcabc";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "ababba";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "abaabaa";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "abaababaab";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "aaaaab";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "abcabcabcab";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "ababa";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "abacaba";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "abcabc";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "aaaaa";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "abcdeabcdeabcde";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";

    word = "aaaabaaaab";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";
    
    word = "abac";
    result = s.repeatedSubstringPattern(word);
    cout << boolalpha << "result = " << result << "\n--------------------------------------------\n\n";
}
