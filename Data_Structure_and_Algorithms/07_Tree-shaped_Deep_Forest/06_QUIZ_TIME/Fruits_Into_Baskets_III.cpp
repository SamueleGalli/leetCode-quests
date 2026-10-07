/*
You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.
From left to right, place the fruits according to these rules:
    * Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
    * Each basket can hold only one type of fruit.
    * If a fruit type cannot be placed in any basket, it remains unplaced.
Return the number of fruit types that remain unplaced after all possible allocations are made.

Example 1:

    Input: fruits = [4,2,5], baskets = [3,5,4]

    Output: 1

        Explanation:
            * fruits[0] = 4 is placed in baskets[1] = 5.
            * fruits[1] = 2 is placed in baskets[0] = 3.
            * fruits[2] = 5 cannot be placed in baskets[2] = 4.
        Since one fruit type remains unplaced, we return 1.

Example 2:

    Input: fruits = [3,6,1], baskets = [6,4,7]

    Output: 0

        Explanation:
            * fruits[0] = 3 is placed in baskets[0] = 6.
            * fruits[1] = 6 cannot be placed in baskets[1] = 4 (insufficient capacity) but can be placed in the next available basket, baskets[2] = 7.
            * fruits[2] = 1 is placed in baskets[1] = 4.
        Since all fruits are successfully placed, we return 0.



Constraints:

* n == fruits.length == baskets.length
* 1 <= n <= 10^5
* 1 <= fruits[i], baskets[i] <= 10^9
*/

using namespace std;

#include <iostream>
#include <vector>

class TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    friend class Solution;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr)
    {
    }
};

class Solution
{
private:
    void delete_tree(TreeNode *Head)
    {
        if (!Head)
            return;
        delete_tree(Head->left);
        delete_tree(Head->right);
        delete (Head);
    }

    TreeNode *Create_Tree(int start, int end, const vector<int> &baskets)
    {
        if (start == end)
            return (new TreeNode(baskets[start]));

        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(0);

        node->left = Create_Tree(start, mid, baskets);
        node->right = Create_Tree(mid + 1, end, baskets);

        node->val = max(node->left->val, node->right->val);

        return (node);
    }

    bool search_fruit(TreeNode *&node, const int &fruit)
    {
        if (node)
        {
            if (!node->left && !node->right)
            {
                if (node->val >= fruit)
                {
                    node->val = 0;
                    return (true);
                }
                else
                    return (false);
            }

            if (node->val >= fruit)
            {
                if (search_fruit(node->left, fruit))
                {
                    node->val = max(node->left->val, node->right->val);
                    return (true);
                }
                else if (search_fruit(node->right, fruit))
                {
                    node->val = max(node->left->val, node->right->val);
                    return (true);
                }
            }
        }
        return (false);
    }

public:
    int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
    {
        TreeNode *Head = Create_Tree(0, static_cast<int>(baskets.size() - 1), baskets);
        int count = static_cast<int>(baskets.size());

        for (size_t i = 0; i < fruits.size(); i++)
        {
            if (search_fruit(Head, fruits[i]))
                count--;
        }

        delete_tree(Head);
        Head = nullptr;

        return (count);
    }
};

int main()
{
    Solution s;
    int result;
    vector<int> fruits;
    vector<int> basket;

    fruits = {4, 2, 5};
    basket = {3, 5, 4};

    result = s.numOfUnplacedFruits(fruits, basket);
    cout << "result = " << result << endl;

    fruits = {3, 6, 1};
    basket = {6, 4, 7};

    result = s.numOfUnplacedFruits(fruits, basket);
    cout << "result = " << result << endl;
}