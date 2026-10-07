/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:

    Input: strs = ["flower","flow","flight"]
    Output: "fl"

Example 2:

    Input: strs = ["dog","racecar","car"]
    Output: ""
        Explanation: There is no common prefix among the input strings.

Constraints:

* 1 <= strs.length <= 200
* 0 <= strs[i].length <= 200
* strs[i] consists of only lowercase English letters if it is non-empty.
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

    void return_result(Node *root, string &result)
    {
        while (!root->isword)
        {
            int count = -1;
            for (size_t i = 0; i < 26; i++)
            {
                if (root->child[i])
                {
                    if (count == -1)
                        count = i;
                    else
                        return;
                }
            }
            if (count == -1)
                break;
            result.push_back(root->child[count]->c);
            root = root->child[count];
        }
        return;
    }

public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Node *root = new Node('\0');
        string result = "";

        for (string &word : strs)
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
    vector<string> strs;

    strs = {"flower", "flow", "flight"};
    result = s.longestCommonPrefix(strs);
    if (result == "")
        cout << "result e vuoto\n";
    else
        cout << "result = " << result << endl;

    strs = {"dog", "racecar", "car"};
    result = s.longestCommonPrefix(strs);
    if (result == "")
        cout << "result e vuoto\n";
    else
        cout << "result = " << result << endl;
}