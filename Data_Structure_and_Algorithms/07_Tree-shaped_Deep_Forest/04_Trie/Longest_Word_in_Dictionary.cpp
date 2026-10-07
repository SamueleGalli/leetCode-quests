/*
Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.
If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.
Note that the word should be built from left to right with each additional character being added to the end of a previous word.

Example 1:

    Input: words = ["w","wo","wor","worl","world"]
    Output: "world"
        Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".

Example 2:

    Input: words = ["a","banana","app","appl","ap","apply","apple"]
    Output: "apple"
        Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".

Constraints:

* 1 <= words.length <= 1000
* 1 <= words[i].length <= 30
* words[i] consists of lowercase English letters.
*/

using namespace std;

#include <iostream>
#include <vector>

class Node
{
    friend class Solution;

private:
    char c;
    Node *child[26];
    bool isword = false;

public:
    Node(char c) : c(c)
    {
        for (size_t i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};

class Solution
{
private:
    void cleanup(Node *&root)
    {
        while (root)
        {
            for (size_t i = 0; i < 26; i++)
            {
                if (root->child[i])
                    cleanup(root->child[i]);
            }
            delete (root);
            root = nullptr;
        }
    }

    void add_to_Trie(Node *root, string &word)
    {
        for (char &c : word)
        {
            int index = c - 'a';

            if (!root->child[index])
                root->child[index] = new Node(c);
            root = root->child[index];
        }
        root->isword = true;
    }

    void return_result(Node *root, string &result, string temp = "")
    {
        for (size_t i = 0; i < 26; i++)
        {
            if (root->child[i] && root->child[i]->isword)
            {
                temp.push_back(root->child[i]->c);
                return_result(root->child[i], result, temp);
                temp.pop_back();
            }
        }

        if ((temp.size() > result.size()) ||
            (temp.size() == result.size() && temp < result))
            result = temp;
    }

public:
    string longestWord(vector<string> &words)
    {
        Node *root = new Node('\0');
        string result = "";

        for (string &word : words)
            add_to_Trie(root, word);

        return_result(root, result);
        cleanup(root);
        return (result);
    }
};

int main()
{
    Solution s;
    string result;
    vector<string> words;

    words = {"w", "wo", "wor", "worl", "world"};
    result = s.longestWord(words);
    if (result == "")
        cout << "result e vuoto\n";
    else
        cout << "result = " << result << endl;

    words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    result = s.longestWord(words);
    if (result == "")
        cout << "result e vuoto\n";
    else
        cout << "result = " << result << endl;

    words = {"flower", "flow", "flight"};
    result = s.longestWord(words);
    if (result == "")
        cout << "result e vuoto\n";
    else
        cout << "result = " << result << endl;

    words = {"dog", "racecar", "car"};
    result = s.longestWord(words);
    if (result == "")
        cout << "result e vuoto\n";
    else
        cout << "result = " << result << endl;
}