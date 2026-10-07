/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:

    Input: s = "leetcode", wordDict = ["leet","code"]
    Output: true
        Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

    Input: s = "applepenapple", wordDict = ["apple","pen"]
    Output: true
        Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
        Note that you are allowed to reuse a dictionary word.

Example 3:

    Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
    Output: false

Constraints:

* 1 <= s.length <= 300
* 1 <= wordDict.length <= 1000
* 1 <= wordDict[i].length <= 20
* s and wordDict[i] consist of only lowercase English letters.
* All the strings of wordDict are unique.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    bool check_equal(const string &word, const string &s, size_t i)
    {
        if (i + word.size() > s.size())
            return (false);

        for (size_t j = 0; j < word.size() && i < s.size(); j++)
        {
            if (word[j] != s[i])
                return (false);
            i++;
        }
        return (true);
    }

    bool break_in_word(const string &s, const vector<string> &wordDict,
                       vector<int> &memo, size_t i = 0)
    {

        if (i == s.size())
            return (true);

        if (memo[i] == 1)
            return (true);
        else if (memo[i] == -1)
            return (false);

        for (const string &word : wordDict)
        {
            if (check_equal(word, s, i))
            {
                if (break_in_word(s, wordDict, memo, i + word.size()))
                {
                    memo[i] = 1;
                    return (true);
                }
            }
        }

        memo[i] = -1;
        return (false);
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        vector<int> memo(s.size(), 0);
        return (break_in_word(s, wordDict, memo));
    }
};

void testcase(string word, vector<string> wordDict)
{
    Solution s;
    bool result;

    result = s.wordBreak(word, wordDict);
    cout << boolalpha << "result = " << result << endl;
}

int main()
{
    /*  testcase("leetcode", {"leet", "code"});
     testcase("applepenapple", {"apple", "pen"});
     testcase("catsandog", {"cats", "dog", "sand", "and", "cat"});
     testcase("cars", {"car", "ca", "rs"}); */
    testcase("bb", {"car", "a", "b", "bbb", "bbbb"});
}