/*

Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.

Example 1:

    Input: root = [1,2,3,4,5]
    Output: 3
        Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:

    Input: root = [1,2]
    Output: 1


Constraints:

* The number of nodes in the tree is in the range [1, 104].
* -100 <= Node.val <= 100
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

void testcase(vector<optional<int>> Tree)
{
    Solution s;
    queue<TreeNode *> list_node;
    TreeNode *root;
    int result;

    if (!Tree.empty())
    {
        list_node.push(new TreeNode(Tree[0].value()));
        root = create_tree(Tree, list_node);
    }
    else
        root = nullptr;

    print_tree(root);

    result = s.diameterOfBinaryTree(root);
    cout << "\n\nresult = " << result << endl;

    delete_tree(root);
    root = nullptr;
}

int main()
{
    testcase({1, 2, 3, 4, 5});
    testcase({1, 2});
}