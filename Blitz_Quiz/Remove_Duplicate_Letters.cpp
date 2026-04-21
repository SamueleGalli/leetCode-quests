/*
Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

 

Example 1:

    Input: s = "bcabc"
    Output: "abc"

Example 2:

    Input: s = "cbacdcbc"
    Output: "acdb"

 

Constraints:

    * 1 <= s.length <= 104
    * s consists of lowercase English letters.

 

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string result;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (find(result.begin(), result.end(), s[i]) == result.end())
            {
                while (!result.empty() && result.back() > s[i])
                {
                    if (find(s.begin() + i + 1 , s.end(), result.back()) != s.end())
                        result.pop_back();
                    else
                        break;
                }
                result.push_back(s[i]);
            }
        }
        return (result);
    }
};

int main()
{
    Solution s;
    string str;
    string result;

    str = "bcabc";
    result = s.removeDuplicateLetters(str);
    cout << "\n\n\n-------------------------------------------\nresulting string = " << result << "\n---------------------------------------------------------\n\n\n";

    str = "cbacdcbc";
    result = s.removeDuplicateLetters(str);
    cout << "\n\n\n-------------------------------------------\nresulting string = " << result << "\n---------------------------------------------------------\n\n\n";

    str = "leetcode";
    result = s.removeDuplicateLetters(str);
    cout << "\n\n\n-------------------------------------------\nresulting string = " << result << "\n---------------------------------------------------------\n\n\n";
}