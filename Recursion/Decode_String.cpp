/*
Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

The test cases are generated so that the length of the output will never exceed 105.

Example 1:

    Input: s = "3[a]2[bc]"
    Output: "aaabcbc"

Example 2:

    Input: s = "3[a2[c]]"
    Output: "accaccacc"

Example 3:

    Input: s = "2[abc]3[cd]ef"
    Output: "abcabccdcdcdef"


Constraints:

* 1 <= s.length <= 30
* s consists of lowercase English letters, digits, and square brackets '[]'.
* s is guaranteed to be a valid input.
* All the integers in s are in the range [1, 300].
*/

using namespace std;

#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

class Solution
{
private:
    int get_num(const string &s, size_t &i, size_t j)
    {
        while (s[i] != '[')
            i++;
        return (stoi(s.substr(j, i - j)));
    }
    string decoder(const string &s, size_t &i)
    {
        string repeat = "";
        string decoded = "";
        int num = 0;

        num = get_num(s, i, i);
        i++;
        while (isalpha(s[i]))
            repeat += s[i++];

        if (s[i] != ']')
            repeat += decoder(s, i);
        while (num > 0)
        {
            decoded += repeat;
            num--;
        }
        i++;
        while (isalpha(s[i]))
            decoded += s[i++];
        if (isdigit(s[i]))
            decoded += decoder(s, i);
        return (decoded);
    }

public:
    string decodeString(string s)
    {
        string result;

        for (size_t i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
                result += decoder(s, i);
            else if (s[i] != '[' && s[i] != ']')
                result += s[i];
        }
        return (result);
    }
};

int main()
{
    Solution s;
    string word;
    string result;

    word = "3[a]2[bc]";
    result = s.decodeString(word);
    cout << "result = " << result << endl;

    word = "3[a2[c]]";
    result = s.decodeString(word);
    cout << "result = " << result << endl;

    word = "2[abc]3[cd]ef";
    result = s.decodeString(word);
    cout << "result = " << result << endl;

    word = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";
    result = s.decodeString(word);
    cout << "result = " << result << endl;
}