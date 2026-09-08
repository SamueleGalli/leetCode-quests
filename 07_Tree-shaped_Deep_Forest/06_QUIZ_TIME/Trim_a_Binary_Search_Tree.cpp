/*
Given the root of a binary search tree and the lowest and highest boundaries as low and high, trim the tree so that all its elements lies in [low, high]. Trimming the tree should not change the relative structure of the elements that will remain in the tree (i.e., any node's descendant should remain a descendant). It can be proven that there is a unique answer.
Return the root of the trimmed binary search tree. Note that the root may change depending on the given bounds.

Example 1:

    Input: root = [1,0,2], low = 1, high = 2
    Output: [1,null,2]

Example 2:

    Input: root = [3,0,4,null,2,null,null,1], low = 1, high = 3
    Output: [3,2,null,1]

Constraints:

* The number of nodes in the tree is in the range [1, 104].
* 0 <= Node.val <= 104
* The value of each node in the tree is unique.
* root is guaranteed to be a valid binary search tree.
* 0 <= low <= high <= 104
*/

using namespace std;

#include <vector>
#include <iostream>
#include <optional>
#include <queue>

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
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        TreeNode *branch;
        
        if (!root)
            return (nullptr);

        if (root->val > high)
        {
            branch = root->left;
            delete (root);
            return (trimBST(branch, low, high));
        }
        else if (root->val < low)
        {
            branch = root->right;
            delete (root);
            return (trimBST(branch, low, high));
        }
        else
        {
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
             return (root);
        }
    }
};

TreeNode *create_tree(const vector<optional<int>> &Tree, queue<TreeNode *> &list_node)
{
    TreeNode *head = list_node.front();
    TreeNode *temp;
    size_t index = 0;
    while (!list_node.empty())
    {
        temp = list_node.front();
        index++;
        if (index < Tree.size() && Tree[index].has_value())
        {
            temp->left = new TreeNode(Tree[index].value());
            list_node.push(temp->left);
        }
        index++;
        if (index < Tree.size() && Tree[index].has_value())
        {
            temp->right = new TreeNode(Tree[index].value());
            list_node.push(temp->right);
        }
        list_node.pop();
    }
    return (head);
}

void print_tree(TreeNode *root, int depth = 0)
{
    if (!root)
        return;

    print_tree(root->left, depth + 1);
    cout << string(depth, '\t') << "(" << root->val << ")\n\n";
    print_tree(root->right, depth + 1);
}

void delete_tree(TreeNode *&root)
{
    if (!root)
        return;

    delete_tree(root->left);
    delete_tree(root->right);

    delete (root);
}

void testcase(vector<optional<int>> Tree, int low, int high)
{
    Solution s;
    queue<TreeNode *> list_node;
    TreeNode *root;
    TreeNode *result;

    if (!Tree.empty())
    {
        list_node.push(new TreeNode(Tree[0].value()));
        root = create_tree(Tree, list_node);
    }
    else
        root = nullptr;

    print_tree(root);

    result = s.trimBST(root, low, high);
    cout << "the Tree is\n\n";
    print_tree(result);
    cout << "-----------------------------------------------------\n";

    delete_tree(result);
    result = nullptr;
}

int main()
{
    testcase({1, 0, 2}, 1, 2);
    testcase({3, 0, 4, nullopt, 2, nullopt, nullopt, 1}, 1, 3);
}