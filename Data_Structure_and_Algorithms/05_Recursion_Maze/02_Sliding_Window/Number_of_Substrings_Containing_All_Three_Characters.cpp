/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.



Example 1:

    Input: s = "abcabc"
    Output: 10
        Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

Example 2:

    Input: s = "aaacb"
    Output: 3
        Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb".

Example 3:

    Input: s = "abc"
    Output: 1


Constraints:

* 3 <= s.length <= 5 x 10^4
* s only consists of a, b or c characters.
*/

using namespace std;

#include <iostream>
#include <unordered_map>

/*TODO aggiornamento sfasato di poco*/

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        unordered_map<char, int> occurences;
        size_t left = 0;
        size_t right = 0;
        int count = 0;
        while (right < s.size())
        {
            occurences[s[right]]++;
            right++;
            while (occurences.size() == 3)
            {
                occurences[s[left]]--;
                if (occurences[s[left]] == 0)
                    occurences.erase(s[left]);
                left++;
            }
            count += left;
        }
        return (count);
    }
};

int main()
{
    Solution s;
    string sequence;
    int result;

    sequence = "abcabc";
    result = s.numberOfSubstrings(sequence);
    cout << "result = " << result << " == " << "10\n\n";

    sequence = "aaacb";
    result = s.numberOfSubstrings(sequence);
    cout << "result = " << result << " == " << "3\n\n";

    sequence = "abc";
    result = s.numberOfSubstrings(sequence);
    cout << "result = " << result << " == " << "1\n\n";

    sequence = "aaabc";
    result = s.numberOfSubstrings(sequence);
    cout << "result = " << result << " == " << "3\n\n";

    sequence = "acbbcac";
    result = s.numberOfSubstrings(sequence);
    cout << "result = " << result << " == " << "11\n\n";
}