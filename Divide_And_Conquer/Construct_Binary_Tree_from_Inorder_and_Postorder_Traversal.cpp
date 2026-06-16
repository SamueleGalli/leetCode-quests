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
#include <unordered_map>

/*
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

/*
post-order(left - right - root)
in-order(left - root - right)
*/

class Solution
{
private:
    TreeNode *treefing(const vector<int> &postorder,
                       int start, int end,
                       size_t &selector, unordered_map<int, size_t> &aux)
    {
        if (start > end)
            return (nullptr);

        TreeNode *head;
        int pivot = static_cast<int>(aux[postorder[selector]]);

        head = new TreeNode(postorder[selector]);
        selector--;
        head->right = treefing(postorder, pivot + 1, end, selector, aux);
        head->left = treefing(postorder, start, pivot - 1, selector, aux);
        return (head);
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, size_t> aux;
        size_t selector;

        selector = postorder.size() - 1;
        for (size_t i = 0; i < inorder.size(); i++)
            aux[inorder[i]] = i;
        TreeNode *head = treefing(postorder, 0, postorder.size() - 1, selector, aux);
        return (head);
    }
};

void Delete_Tree(TreeNode *&head)
{
    if (!head)
        return;

    Delete_Tree(head->left);
    Delete_Tree(head->right);
    delete (head);
    head = nullptr;
}

void printing(TreeNode *&temp, string &result)
{
    if (!temp)
    {
        result += "NULL, ";
        return;
    }
    result += to_string(temp->val) + ", ";
    printing(temp->left, result);
    printing(temp->right, result);
}

string print_tree(TreeNode *&head, bool print)
{
    TreeNode *temp = head;
    string result = "{";
    printing(temp, result);
    if (!result.empty())
    {
        result.pop_back();
        result.pop_back();
    }
    result += "}\n";
    if (print == false)
    {
        cout << "L'albero e composto da " << result << endl;
    }
    return (result);
}

void Testcase(const string &Tree,
              vector<int> &inorder, vector<int> &postorder)
{
    Solution s;
    TreeNode *new_head;

    new_head = s.buildTree(inorder, postorder);
    cout << "excepted = " << Tree;
    if (Tree == print_tree(new_head, true))
        cout << "head e new_head = \"UGUALI\"\n";
    else
    {
        cout << "head e new_head = \"DIVERSI\"\n";
        cout << "new_head =  " << print_tree(new_head, true);
    }
    Delete_Tree(new_head);
    cout << "-------------------------------------------\n";
}

int main()
{
    vector<optional<int>> Tree;
    vector<int> inorder;
    vector<int> postorder;

    Testcase("{3, 9, NULL, NULL, 15, NULL, NULL}\n",
             inorder = {9, 3, 15}, postorder = {9, 15, 3});
    Testcase("{3, 9, NULL, NULL, 20, 15, NULL, NULL, 7, NULL, NULL}\n",
             inorder = {9, 3, 15, 20, 7}, postorder = {9, 15, 7, 20, 3});
    Testcase("{-1, NULL, NULL}\n",
             inorder = {-1}, postorder = {-1});
}
