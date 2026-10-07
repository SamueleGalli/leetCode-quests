/*A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

Example 1:

    Input: n = 1, k = 3
    Output: "c"
        Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".

Example 2:

    Input: n = 1, k = 4
    Output: ""
        Explanation: There are only 3 happy strings of length 1.

Example 3:

    Input: n = 3, k = 9
    Output: "cab"
        Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"


Constraints:

* 1 <= n <= 10
* 1 <= k <= 100
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    void get_happy_string(string &word, vector<string> &result,
                          const vector<char> &options, size_t n, size_t k)
    {
        if (result.size() == k)
            return;
        if (word.size() == n)
        {
            result.push_back(word);
            return;
        }
        for (char letter : options)
        {
            if (word.empty() || word.back() != letter)
            {
                word += letter;
                get_happy_string(word, result, options, n, k);
                word.pop_back();
            }
        }
    }

public:
    string getHappyString(int n, int k)
    {
        vector<string> result;
        string word;
        const vector<char> options = {'a', 'b', 'c'};

        result.reserve(3 << (n - 1));
        word.reserve(102);

        get_happy_string(word, result, options, static_cast<size_t>(n), static_cast<size_t>(k));

        if (static_cast<size_t>(k) <= result.size())
            return (result[k - 1]);
        else
            return "";
    }
};

int main()
{
    Solution s;
    string result;
    int n;
    int k;

    n = 1;
    k = 3;
    result = s.getHappyString(n, k);
    cout << "result = (" << result << ")\n";

    n = 1;
    k = 4;
    result = s.getHappyString(n, k);
    cout << "result = (" << result << ")\n";

    n = 3;
    k = 9;
    result = s.getHappyString(n, k);
    cout << "result = (" << result << ")\n";
}