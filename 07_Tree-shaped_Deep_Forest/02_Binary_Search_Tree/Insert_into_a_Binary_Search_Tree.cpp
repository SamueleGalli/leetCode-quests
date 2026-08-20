/*
You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

Example 1:

    Input: root = [4,2,7,1,3], val = 5
    Output: [4,2,7,1,3,5]
        Explanation: Another accepted tree is:

Example 2:

    Input: root = [40,20,60,10,30,50,70], val = 25
    Output: [40,20,60,10,30,50,70,null,null,25]

Example 3:

    Input: root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
    Output: [4,2,7,1,3,5]

Constraints:

* The number of nodes in the tree will be in the range [0, 104].
* -10^8 <= Node.val <= 10^8
* All the values Node.val are unique.
* -10^8 <= val <= 10^8
* It's guaranteed that val does not exist in the original BST.
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
private:
    void inserting(TreeNode *&root, const int &val)
    {
        if (!root)
        {
            root = new TreeNode(val);
            return;
        }
        if (val > root->val)
        {
            if (!root->right)
            {
                root->right = new TreeNode(val);
                return;
            }
            return (inserting(root->right, val));
        }
        else if (val < root->val)
        {
            if (!root->left)
            {
                root->left = new TreeNode(val);
                return;
            }
            return (inserting(root->left, val));
        }
    }

public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        inserting(root, val);
        return (root);
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

    head = s.insertIntoBST(head, val);
    cout << "-----------------------------------------------------------\n";
    if (head)
        print_tree(head);
    else
        cout << "NULL\n";
    cout << "-----------------------------------------------------------\n";

    delete_tree(head);
    head = nullptr;
}

int main()
{
    vector<optional<int>> my_tree;

    my_tree = {4, 2, 7, 1, 3};
    testcase(my_tree, 5);

    my_tree = {40, 20, 60, 10, 30, 50, 70};
    testcase(my_tree, 25);

    my_tree = {4, 2, 7, 1, 3, nullopt, nullopt, nullopt, nullopt, nullopt, nullopt};
    testcase(my_tree, 5);

    my_tree = {};
    testcase(my_tree, 5);
}