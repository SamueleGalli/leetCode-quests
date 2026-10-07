/*
Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

    * For example, if s = "abcde", then it will be "bcdea" after one shift.

 

Example 1:

    Input: s = "abcde", goal = "cdeab"
    Output: true

Example 2:

    Input: s = "abcde", goal = "abced"
    Output: false

 

Constraints:

    * 1 <= s.length, goal.length <= 100
    * s and goal consist of lowercase English letters.

*/

using namespace  std;

#include <string>
#include <iostream>

class Solution {
public:
    bool rotateString(string s, string goal) {
        string c;
        const size_t s_size = s.size();

        for (size_t i = 0;i < s_size;i++)
        {
            if (s == goal)
                return (true);
            else
            {
                c = s[0];
                s.erase(s.begin());
                s.append(c);
            }
        }
        return (false);
    }
};

int main()
{
    Solution s;
    string word;
    string goal;
    bool result;

    word = "abcde";
    goal = "cdeab";
    result = s.rotateString(word,goal);
    cout << boolalpha << "result = " << result << "\n--------------------------------------\n";

    word = "abcde";
    goal = "abced";
    result = s.rotateString(word,goal);
    cout << boolalpha << "result = " << result << "\n--------------------------------------\n";
}