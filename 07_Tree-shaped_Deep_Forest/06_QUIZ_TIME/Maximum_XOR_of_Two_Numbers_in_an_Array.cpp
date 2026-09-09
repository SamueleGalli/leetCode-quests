/*
Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

Example 1:

    Input: nums = [3,10,5,25,2,8]
    Output: 28
        Explanation: The maximum result is 5 XOR 25 = 28.

Example 2:

    Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
    Output: 127


Constraints:

* 1 <= nums.length <= 2 * 105
* 0 <= nums[i] <= 231 - 1
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
    void delete_trie(TreeNode *&Head)
    {
        if (!Head)
            return;
        delete_trie(Head->left);
        delete_trie(Head->right);
        delete (Head);
    }

public:
};

int main()
{
    Solution s;
    int result;

    vector<int> nums = {3, 10, 5, 25, 2, 8};
    result = s.findMaximumXOR(nums);
    cout << "result = " << result << endl;

    vector<int> nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    result = s.findMaximumXOR(nums);
    cout << "result = " << result << endl;
}