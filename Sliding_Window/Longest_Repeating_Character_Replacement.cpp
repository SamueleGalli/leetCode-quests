/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

    Input: s = "ABAB", k = 2
    Output: 4
        Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

    Input: s = "AABABBA", k = 1
    Output: 4
        Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
        The substring "BBBB" has the longest repeating letters, which is 4.
        There may exists other ways to achieve this answer too.


Constraints:

* 1 <= s.length <= 10^5
* s consists of only uppercase English letters.
* 0 <= k <= s.length
*/

using namespace std;

#include <iostream>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int freq = 0;
        int result = 0;
        int left = 0;
        int window = 0;
        int occurence[26] = {0};
        for (int right = 0; static_cast<size_t>(right) < s.size(); right++)
        {
            window++;
            occurence[s[right] - 'A']++;
            freq = max(freq, occurence[s[right] - 'A']);
            while (window - freq > k)
            {
                occurence[s[left] - 'A']--;
                left++;
                window--;
            }
            result = max(result, window);
        }
        return (result);
    }
};

void testcase(string word, int k, int excepted)
{
    Solution s;
    int result;

    result = s.characterReplacement(word, k);
    if (result == excepted)
        cout << "result correct (" << result << ")\n\n";
    else
        cout << "result incorrect (" << result << " instead of " << excepted << ")\n\n";
}

int main()
{
    testcase("ABAB", 2, 4);
    testcase("AABABBA", 1, 4);
    testcase("ABBBABBABABABAAABBBABABABABBBA", 3, 10);
}