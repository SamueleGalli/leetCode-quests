/*
We define the usage of capitals in a word to be right when one of the following cases holds:

    * All letters in this word are capitals, like "USA".
    * All letters in this word are not capitals, like "leetcode".
    * Only the first letter in this word is capital, like "Google".

Given a string word, return true if the usage of capitals in it is right.



Example 1:

    Input: word = "USA"
    Output: true

Example 2:

    Input: word = "FlaG"
    Output: false



Constraints:

    * 1 <= word.length <= 100
    * word consists of lowercase and uppercase English letters.

*/

using namespace std;

#include <iostream>

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int c = 0;
        for (size_t i = 0; i < word.size(); i++)
        {
            if (word[i] >= 65 && word[i] <= 90)
                c++;
        }
        cout << "c = " << c << endl;
        if (c == static_cast<int>(word.size()) ||
            (c == 1 && isupper(word[0])) || c == 0)
            return (true);
        else
            return (false);
    }
};

int main()
{
    Solution s;
    string word;
    bool result;

    word = "USA";
    result = s.detectCapitalUse(word);
    cout << boolalpha << "result = " << result << endl;

    word = "FlaG";
    result = s.detectCapitalUse(word);
    cout << boolalpha << "result = " << result << endl;
}