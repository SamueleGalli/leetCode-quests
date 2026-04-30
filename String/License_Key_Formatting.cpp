/*
You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.

We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

Return the reformatted license key.



Example 1:

    Input: s = "5F3Z-2e-9-w", k = 4
    Output: "5F3Z-2E9W"
        Explanation: The string s has been split into two parts, each part has 4 characters.
        Note that the two extra dashes are not needed and can be removed.

Example 2:

    Input: s = "2-5g-3-J", k = 2
    Output: "2-5G-3J"
        Explanation: The string s has been split into three parts, each part has 2 characters except the first part as it could be shorter as mentioned above.



Constraints:

    * 1 <= s.length <= 105
    * s consists of English letters, digits, and dashes '-'.
    * 1 <= k <= 104
*/

using namespace std;

#include <iostream>
#include <algorithm>

class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string result;
        int c = 0;

        size_t i = s.size();
        do
        {
            i--;
            if (s[i] >= 97 && s[i] <= 122)
                s[i] = s[i] - 32;
            if (s[i] != '-')
            {
                result.push_back(s[i]);
                c++;
            }
            if (c == k)
            {
                result.push_back('-');
                c = 0;
            }
        } while (i > 0);
        reverse(result.begin(), result.end());
        if (result[0] == '-')
        {
            result.erase(result.begin());
        }
        return (result);
    }
};

int main()
{
    Solution s;
    string word;
    string result;
    int k;

    word = "5F3Z-2e-9-w";
    k = 4;
    result = s.licenseKeyFormatting(word, k);
    cout << "result = " << result << endl;

    word = "2-5g-3-J";
    k = 2;
    result = s.licenseKeyFormatting(word, k);
    cout << "result = " << result << endl;

    word = "2-4A0r7-4k";
    k = 4;
    result = s.licenseKeyFormatting(word, k);
    cout << "result = " << result << endl;

    word = "5F3Z-2e-9-w";
    k = 4;
    result = s.licenseKeyFormatting(word, k);
    cout << "result = " << result << endl;

    word = "--a-a-a-a--";
    k = 2;
    result = s.licenseKeyFormatting(word, k);
    cout << "result = " << result << endl;


    word = "-";
    k = 2;
    result = s.licenseKeyFormatting(word, k);
    cout << "result = " << result << endl;
}
