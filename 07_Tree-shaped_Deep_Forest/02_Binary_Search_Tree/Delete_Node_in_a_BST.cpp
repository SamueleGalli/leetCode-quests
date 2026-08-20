/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
* Search for a node to remove.
* If the node is found, delete the node.

Example 1:

    Input: root = [5,3,6,2,4,null,7], key = 3
    Output: [5,4,6,2,null,null,7]
        Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
        One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
        Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

    Input: root = [5,3,6,2,4,null,7], key = 0
    Output: [5,3,6,2,4,null,7]
        Explanation: The tree does not contain a node with value = 0.

Example 3:

    Input: root = [], key = 0
    Output: []


Constraints:

* The number of nodes in the tree is in the range [0, 104].
* -10^5 <= Node.val <= 10^5
* Each node has a unique value.
* root is a valid binary search tree.
* -10^5 <= key <= 10^5


Follow up: Could you solve it with time complexity O(height of tree)?
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
    TreeNode *prev;

    void reorder(TreeNode *to_go, TreeNode *&to_set)
    {
        if (!to_go->left)
        {
            to_go->left = to_set;
            return;
        }
        return (reorder(to_go->left, to_set));
    }

    void exist_prev(TreeNode *&root, TreeNode *&left_node, TreeNode *&right_node)
    {
        TreeNode *take;

        if (left_node && !right_node)
            take = left_node;
        else
            take = right_node;

        if (prev->left == root)
            prev->left = take;
        else if (prev->right == root)
            prev->right = take;
    }

    void not_exist_prev(TreeNode *&root, TreeNode *&left_node, TreeNode *&right_node)
    {
        if (!right_node && !left_node)
        {
            root = nullptr;
            return;
        }
        if (right_node)
            root = right_node;
        else if (left_node)
            root = left_node;
    }

    void deliting_root(TreeNode *&root)
    {
        TreeNode *to_delete = root;

        if (root->right && root->left)
            reorder(root->right, root->left);

        if (prev)
            exist_prev(root, root->left, root->right);
        else
            not_exist_prev(root, root->left, root->right);
        delete (to_delete);
    }

    void find_node_to_delete(TreeNode *&root, const int &key)
    {
        if (!root)
            return;

        if (root->val == key)
        {
            deliting_root(root);
            return;
        }
        if (key < root->val)
        {
            prev = root;
            find_node_to_delete(root->left, key);
        }
        else
        {
            prev = root;
            find_node_to_delete(root->right, key);
        }
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        prev = nullptr;
        find_node_to_delete(root, key);
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

    head = s.deleteNode(head, val);
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

    my_tree = {5, 3, 6, 2, 4, nullopt, 7};
    testcase(my_tree, 3);

    my_tree = {5, 3, 6, 2, 4, nullopt, 7};
    testcase(my_tree, 0);

    my_tree = {};
    testcase(my_tree, 0);

    my_tree = {5, 3, 6, 2, 4, nullopt, 7};
    testcase(my_tree, 7);
}