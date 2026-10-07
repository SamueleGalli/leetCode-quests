/*
You are building a string s of length n one character at a time, prepending each new character to the front of the string. The strings are labeled from 1 to n, where the string with length i is labeled si.

For example, for s = "abaca", s1 == "a", s2 == "ca", s3 == "aca", etc.
The score of si is the length of the longest common prefix between si and sn (Note that s == sn).

Given the final string s, return the sum of the score of every si.



Example 1:

    Input: s = "babab"
    Output: 9
    Explanation:
        For s1 == "b", the longest common prefix is "b" which has a score of 1.
        For s2 == "ab", there is no common prefix so the score is 0.
        For s3 == "bab", the longest common prefix is "bab" which has a score of 3.
        For s4 == "abab", there is no common prefix so the score is 0.
        For s5 == "babab", the longest common prefix is "babab" which has a score of 5.
        The sum of the scores is 1 + 0 + 3 + 0 + 5 = 9, so we return 9.

Example 2:

    Input: s = "azbazbzaz"
    Output: 14
    Explanation:
        For s2 == "az", the longest common prefix is "az" which has a score of 2.
        For s6 == "azbzaz", the longest common prefix is "azb" which has a score of 3.
        For s9 == "azbazbzaz", the longest common prefix is "azbazbzaz" which has a score of 9.
        For all other si, the score is 0.
        The sum of the scores is 2 + 3 + 9 = 14, so we return 14.


Constraints:

* 1 <= s.length <= 10^5
* s consists of lowercase English letters.
*/

using namespace std;

#include <iostream>
#include <vector>
/*
    suffix = (prefix[i + medium - 1] - (prefix[i - 1] * powers[medium] % MOD + MOD)) % MOD;
    prova la stringa con la meta destra da i (prefix[i + medium - 1])
    tolgo la parte d i - 1 dal totale moltiplicando per tolgiere solo l'inzio e non il resto(prefix[i - 1] * powers[medium])
    es.  1234->1200 e non il "34" che mi serve
    e infine formatto per evitare out of bound e rendo positivo ((% MOD + MOD) % MOD)
*/

class Solution
{
private:
    int MOD = 1000000007;

    int binary_search(const string &s, size_t i, const vector<long long> &prefix, const vector<long long> &powers)
    {
        int medium;
        int low = 1;
        int high = static_cast<int>(s.size() - i);
        int dim = 0;

        while (low <= high)
        {
            medium = (low + high) / 2;
            if (prefix[medium - 1] == (prefix[i + medium - 1] -
                                       (prefix[i - 1] * powers[medium] % MOD) +
                                       MOD) %
                                          MOD)
            {
                dim = medium;
                low = medium + 1;
            }
            else
                high = medium - 1;
        }
        return (dim);
    }

public:
    long long sumScores(string s)
    {
        vector<long long> prefix(s.size(), s[0] % MOD);
        vector<long long> powers(s.size(), 1);
        long long result = static_cast<int>(s.size());

        for (size_t i = 1; i < s.size(); i++)
        {
            prefix[i] = ((prefix[i - 1] * 31) + s[i]) % MOD;
            powers[i] = (powers[i - 1] * 31) % MOD;
        }

        for (size_t i = 1; i < s.size(); i++)
            result += binary_search(s, i, prefix, powers);
        return (result);
    }
};

int main()
{
    Solution s;
    string word;
    long long result;

    word = "babab";
    result = s.sumScores(word);
    cout << "result = " << result << endl;

    word = "azbazbzaz";
    result = s.sumScores(word);
    cout << "result = " << result << endl;
}