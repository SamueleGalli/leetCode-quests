/*
Given two integers n and k, return the kth lexicographically smallest integer in the range [1, n].

Example 1:

    Input: n = 13, k = 2
    Output: 10
        Explanation: The lexicographical order is [1, 10, 11, 12, 13, 2, 3, 4, 5, 6, 7, 8, 9], so the second smallest number is 10.
Example 2:

    Input: n = 1, k = 1
    Output: 1

Constraints:
* 1 <= k <= n <= 109
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
public:
    int findKthNumber(int n, int k)
    {
    }
};

int main()
{
    Solution s;
    int result;
    int n;
    int k;

    n = 13;
    k = 2;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;

    n = 1;
    k = 1;
    result = s.findKthNumber(n, k);
    cout << "result = " << result << endl;
}