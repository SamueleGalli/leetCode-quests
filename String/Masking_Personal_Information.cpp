/*
You are given a personal information string s, representing either an email address or a phone number. Return the masked personal information using the below rules.

Email address:

An email address is:

    * A name consisting of uppercase and lowercase English letters, followed by
    * The '@' symbol, followed by
    * The domain consisting of uppercase and lowercase English letters with a dot '.' somewhere in the middle (not the first or last character).

To mask an email:

    * The uppercase letters in the name and domain must be converted to lowercase letters.
    * The middle letters of the name (i.e., all but the first and last letters) must be replaced by 5 asterisks "*****".

Phone number:

A phone number is formatted as follows:

    * The phone number contains 10-13 digits.
    * The last 10 digits make up the local number.
    * The remaining 0-3 digits, in the beginning, make up the country code.
    * Separation characters from the set {'+', '-', '(', ')', ' '} separate the above digits in some way.

To mask a phone number:

    * Remove all separation characters.
    * The masked phone number should have the form:
        * "***-***-XXXX" if the country code has 0 digits.
        * "+*-***-***-XXXX" if the country code has 1 digit.
        * "+**-***-***-XXXX" if the country code has 2 digits.
        * "+***-***-***-XXXX" if the country code has 3 digits.
    * "XXXX" is the last 4 digits of the local number.



Example 1:

    Input: s = "LeetCode@LeetCode.com"
    Output: "l*****e@leetcode.com"
        Explanation: s is an email address.
        The name and domain are converted to lowercase, and the middle of the name is replaced by 5 asterisks.

Example 2:

    Input: s = "AB@qq.com"
    Output: "a*****b@qq.com"
        Explanation: s is an email address.
        The name and domain are converted to lowercase, and the middle of the name is replaced by 5 asterisks.
        Note that even though "ab" is 2 characters, it still must have 5 asterisks in the middle.

Example 3:

    Input: s = "1(234)567-890"
    Output: "***-***-7890"
        Explanation: s is a phone number.
        There are 10 digits, so the local number is 10 digits and the country code is 0 digits.
        Thus, the resulting masked number is "***-***-7890".



Constraints:

    * s is either a valid email or a phone number.
    * If s is an email:
        * 8 <= s.length <= 40
        * s consists of uppercase and lowercase English letters and exactly one '@' symbol and '.' symbol.
    * If s is a phone number:
        * 10 <= s.length <= 20
        * s consists of digits, spaces, and the symbols '(', ')', '-', and '+'.

*/

using namespace std;

#include <iostream>
#include <algorithm>
#include <string>

class Solution
{
private:
    void mask_email(string &s, string &result, bool is_domain = false)
    {
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + 32;

            if (i == 0)
            {
                result += s[i];
                result += "*****";
            }
            else if (s[i] == '@')
            {
                result += s[i - 1];
                result += "@";
                is_domain = true;
            }
            else if (is_domain == true)
                result += s[i];
        }
    }
    int count_digit_and_format(string &s)
    {
        string new_s;
        int c = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                new_s += s[i];
                c++;
            }
        }
        s = new_s;
        return (c);
    }

    void mask_number(string &s, string &result)
    {
        int digit = count_digit_and_format(s);
        int country_code = digit - 10;

        if (country_code > 0)
        {
            result += '+';
            result += string(country_code, '*');
            result += '-';
            digit -= country_code;
        }

        for (size_t i = 0 + country_code; i < s.size(); i++)
        {
            if (digit <= 4)
                result += s[i];
            else
                result += '*';
            digit--;
            if (digit == 4 || digit == 7)
                result += '-';
        }
    }

public:
    string maskPII(string s)
    {
        string result;
        if (find(s.begin(), s.end(), '@') != s.end())
            mask_email(s, result);
        else
            mask_number(s, result);
        return (result);
    }
};

int main()
{
    Solution s;
    string result;
    string word;

    word = "LeetCode@LeetCode.com";
    result = s.maskPII(word);
    cout << "result = " << result << endl;

    word = "AB@qq.com";
    result = s.maskPII(word);
    cout << "result = " << result << endl;

    word = "1(234)567-890";
    result = s.maskPII(word);
    cout << "result = " << result << endl;

    word = "123(234)567-890";
    result = s.maskPII(word);
    cout << "result = " << result << endl;
}