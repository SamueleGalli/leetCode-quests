/*
Given the root of a binary tree, return the length of the longest path, where each node in the path has the same value. This path may or may not pass through the root.
The length of the path between two nodes is represented by the number of edges between them.

Example 1:

    Input: root = [5,4,5,1,1,null,5]
    Output: 2
        Explanation: The shown image shows that the longest path of the same value (i.e. 5).

Example 2:
    Input: root = [1,4,5,4,4,null,5]
    Output: 2
        Explanation: The shown image shows that the longest path of the same value (i.e. 4).

Constraints:
* The number of nodes in the tree is in the range [0, 104].
* -1000 <= Node.val <= 1000
* The depth of the tree will not exceed 1000.
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
    int max_path;
    int longest_path(TreeNode *&root)
    {
        int left_path = 0;
        int right_path = 0;

        if (root)
        {
            if (root->left)
            {
                left_path = longest_path(root->left);
                if (root->val == root->left->val)
                    left_path++;
                else
                    left_path = 0;
            }
            if (root->right)
            {
                right_path += longest_path(root->right);
                if (root->val == root->right->val)
                    right_path++;
                else
                    right_path = 0;
            }
        }
        max_path = max(max_path, left_path + right_path);
        return (max(left_path, right_path));
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        max_path = 0;
        longest_path(root);
        return (max_path);
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

void testcase(vector<optional<int>> &my_tree)
{
    TreeNode *head = new TreeNode(my_tree[0].value());
    Solution s;
    queue<TreeNode *> node_list;
    int result;

    node_list.push(head);
    create_tree(my_tree, node_list);
    print_tree(head);

    result = s.longestUnivaluePath(head);
    cout << "-----------------------------------------------------------\n";
    cout << "result = " << result << endl;
    cout << "-----------------------------------------------------------\n";

    delete_tree(head);
    head = nullptr;
}

int main()
{
    vector<optional<int>> my_tree;

    my_tree = {5, 4, 5, 1, 1, nullopt, 5};
    testcase(my_tree);

    my_tree = {1, 4, 5, 4, 4, nullopt, 5};
    testcase(my_tree);

    my_tree = {5, 5, 5, 5};
    testcase(my_tree);

    my_tree = {1, nullopt, 1, 1, 1, 1, 1, 1};
    testcase(my_tree);

    my_tree = {5, 4, 5, 4, 4, 5, 3, 4, 4, nullopt, nullopt, nullopt, 4, nullopt, nullopt, 4, nullopt, nullopt, 4, nullopt, 4, 4, nullopt, nullopt, 4, 4};
    testcase(my_tree);
}