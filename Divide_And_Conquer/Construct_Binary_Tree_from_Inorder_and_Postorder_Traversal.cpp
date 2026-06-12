/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.



Example 1:

    Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    Output: [3,9,20,null,null,15,7]

Example 2:

    Input: inorder = [-1], postorder = [-1]
    Output: [-1]


Constraints:

* 1 <= inorder.length <= 3000
* postorder.length == inorder.length
* -3000 <= inorder[i], postorder[i] <= 3000
* inorder and postorder consist of unique values.
* Each value of postorder also appears in inorder.
* inorder is guaranteed to be the inorder traversal of the tree.
* postorder is guaranteed to be the postorder traversal of the tree.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <optional>

/*
TODO Implementa Print
TODO Implementa Testcase
TODO Risolvi problema
*/
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
    }
};

void create_Tree(TreeNode *&head, vector<optional<int>> &Tree, size_t &i)
{
    if (i == Tree.size())
        return;

    TreeNode *Node;

    if (Tree[i] != nullopt)
        Node = new TreeNode(Tree[i].value());
    else
    {
        head = nullptr;
        i++;
        return;
    }

    head = Node;
    i++;
    create_Tree(head->left, Tree, i);
    create_Tree(head->right, Tree, i);
}

void Delete_Tree(TreeNode *&head)
{
    if (!head)
        return;

    Delete_Tree(head->left);
    Delete_Tree(head->right);
    delete (head);
    head = nullptr;
}

int main()
{
    Solution s;
    TreeNode *head = nullptr;
    TreeNode *new_head = nullptr;
    vector<optional<int>> Tree;
    vector<int> inorder;
    vector<int> postorder;
    size_t i = 0;

    //Tescase(vettore albero,head,vettore inorder, vettore postorder);
    Tree = {3, 9, nullopt, nullopt, 20, 15, 7, nullopt, nullopt};
    create_Tree(head, Tree, i);
    new_head = s.buildTree(inorder, postorder);
    // print(head);
    Delete_Tree(head);
    // print(new_head);
    Delete_Tree(new_head);
}
