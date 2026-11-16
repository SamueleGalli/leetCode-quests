/*
You are given the root of a binary search tree (BST) and an integer val.
Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

Example 1:

    Input: root = [4,2,7,1,3], val = 2
    Output: [2,1,3]

Example 2:

    Input: root = [4,2,7,1,3], val = 5
    Output: []

Constraints:

* The number of nodes in the tree is in the range [1, 5000].
* 1 <= Node.val <= 10^7
* root is a binary search tree.
* 1 <= val <= 10^7
*/

using namespace std;

#include <iostream>
#include <vector>
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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return (nullptr);
        TreeNode *finded = nullptr;
        if (root->val == val)
            return (root);
        if (val < root->val)
        {
            finded = searchBST(root->left, val);
            if (finded)
                return (finded);
        }
        if (val > root->val)
        {
            finded = searchBST(root->right, val);
            if (finded)
                return (finded);
        }
        return (finded);
    }
};

void create_tree(const vector<optional<int>> &my_tree,
                 queue<TreeNode *> &node_list, size_t i = 1)
{
    size_t list_size = node_list.size();
    while (list_size > 0)
    {
        TreeNode *head = node_list.front();

        if (i >= my_tree.size())
            return;
        if (my_tree[i].has_value())
        {
            head->left = new TreeNode(my_tree[i].value());
            node_list.push(head->left);
        }

        i++;

        if (i >= my_tree.size())
            return;

        if (my_tree[i].has_value())
        {
            head->right = new TreeNode(my_tree[i].value());
            node_list.push(head->right);
        }
        i++;
        node_list.pop();
        list_size--;
    }
    if (!node_list.empty())
        create_tree(my_tree, node_list, i);
}

void print_tree(TreeNode *&head, int depth = 0)
{
    if (!head)
        return;
    print_tree(head->left, depth + 1);
    cout << string(depth, '\t') << head->val << endl;
    print_tree(head->right, depth + 1);
}

void delete_tree(TreeNode *head)
{
    if (!head)
        return;
    delete_tree(head->left);
    delete_tree(head->right);
    delete (head);
}

void testcase(vector<optional<int>> &my_tree, int val)
{
    TreeNode *head;
    TreeNode *result;
    Solution s;
    queue<TreeNode *> node_list;

    if (my_tree.empty())
    {
        head = nullptr;
        cout << "NULL\n";
    }
    else
    {
        head = new TreeNode(my_tree[0].value());
        node_list.push(head);
        create_tree(my_tree, node_list);
    }

    print_tree(head);

    result = s.searchBST(head, val);
    cout << "-----------------------------------------------------------\n";
    if (result)
        print_tree(result);
    else
        cout << "NULL\n";
    cout << "-----------------------------------------------------------\n";

    delete_tree(head);
    result = nullptr;
}

int main()
{
    vector<optional<int>> my_tree;

    my_tree = {4, 2, 7, 1, 3};
    testcase(my_tree, 2);

    my_tree = {4, 2, 7, 1, 3};
    testcase(my_tree, 5);

    my_tree = {};
    testcase(my_tree, 8);
}