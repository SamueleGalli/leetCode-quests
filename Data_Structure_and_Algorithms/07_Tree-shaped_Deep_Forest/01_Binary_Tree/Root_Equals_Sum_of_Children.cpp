/*
You are given the root of a binary tree that consists of exactly 3 nodes: the root, its left child, and its right child.
Return true if the value of the root is equal to the sum of the values of its two children, or false otherwise.

Example 1:

    Input: root = [10,4,6]
    Output: true
        Explanation: The values of the root, its left child, and its right child are 10, 4, and 6, respectively.
        10 is equal to 4 + 6, so we return true.

Example 2:

    Input: root = [5,3,1]
    Output: false
        Explanation: The values of the root, its left child, and its right child are 5, 3, and 1, respectively.
        5 is not equal to 3 + 1, so we return false.

Constraints:

* The tree consists only of the root, its left child, and its right child.
* -100 <= Node.val <= 100
*/

using namespace std;

#include <vector>
#include <iostream>

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool checkTree(TreeNode *root)
    {
        if (root->val == root->left->val + root->right->val)
            return (true);
        return (false);
    }
};

void Create_Tree(TreeNode *Head, const vector<int> &nodes)
{
    Head->left = new TreeNode(nodes[1]);
    Head->right = new TreeNode(nodes[2]);
}

void Print_Tree(TreeNode *head)
{
    cout << "\t(" << head->val << ")\n";
    cout << "(" << head->left->val << ")\t\t(" << head->right->val << ")\n";
}

void Delete_Tree(TreeNode *&Head)
{
    delete (Head->left);
    delete (Head->right);
    delete (Head);
}

void testcase(vector<int> &nodes)
{
    Solution s;
    TreeNode *head = new TreeNode(nodes[0]);
    bool result;
    Create_Tree(head, nodes);
    Print_Tree(head);
    result = s.checkTree(head);
    cout << boolalpha << "result = " << result << endl;
    Delete_Tree(head);
}

int main()
{
    vector<int> nodes;

    nodes = {10, 4, 6};
    testcase(nodes);

    nodes = {5, 3, 1};
    testcase(nodes);
}