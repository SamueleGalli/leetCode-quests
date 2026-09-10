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

* 1 <= nums.length <= 2 * 10^5
* 0 <= nums[i] <= 2^31 - 1
*/

using namespace std;

#include <iostream>
#include <vector>

/*
brief bit explanation:
    * val >> i shift to the i bit and " & 1" give me only the last bit

    *  val ^ val do the xor:
        * 1 == 1 : 0
        * 0 == 0 : 0
        * 0 == 1 : 1
        * 1 == 0 : 1

    * this biggest_XOR search and existing path that bring a bit 1001
    * that with the actual value (for exemple 0110)
    * if exist i can obtain 1111 otherwise the most big one i cna find

    * this other_result |= (1 << i) place the 1 in i position and the xor do this:
        * with some result = 0 and 8 bit
        * 00000000
        * 01000000
        * --------
        * 01000000
        * simply put the 1 on the new position not touching the others bit
*/

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

    void Create_Trie(TreeNode *&Head, const int &val, int i = 30)
    {
        if (i == -1)
            return;
        int bit = (val >> i) & 1;
        if (bit == 0)
        {
            if (!Head->left)
                Head->left = new TreeNode(0);
            Create_Trie(Head->left, val, i - 1);
        }
        else
        {
            if (!Head->right)
                Head->right = new TreeNode(1);
            Create_Trie(Head->right, val, i - 1);
        }
    }

    int biggest_XOR(TreeNode *&Head, const int &val, int other_result = 0, int i = 30)
    {
        if (i == -1)
            return (other_result);

        int bit = (val >> i) & 1;

        if (bit == 1)
        {
            if (Head->left)
                return (biggest_XOR(Head->left, val, other_result, i - 1));
            else
            {
                other_result |= (1 << i);
                return (biggest_XOR(Head->right, val, other_result, i - 1));
            }
        }
        else if (bit == 0)
        {
            if (Head->right)
            {
                other_result |= (1 << i);
                return (biggest_XOR(Head->right, val, other_result, i - 1));
            }
            else
                return (biggest_XOR(Head->left, val, other_result, i - 1));
        }
        return (other_result);
    }

public:
    int findMaximumXOR(vector<int> &nums)
    {
        TreeNode *Head = new TreeNode(-1);
        int other_result = 0;
        int result = 0;

        for (size_t i = 0; i < nums.size(); i++)
            Create_Trie(Head, nums[i]);

        for (size_t i = 0; i < nums.size(); i++)
        {
            other_result = biggest_XOR(Head, nums[i]);
            other_result ^= nums[i];
            result = max(other_result, result);
        }

        delete_trie(Head);
        Head = nullptr;

        return (result);
    }
};

int main()
{
    Solution s;
    int result;

    vector<int> nums = {3, 10, 5, 25, 2, 8};
    result = s.findMaximumXOR(nums);
    cout << "result = " << result << endl;

    nums = {14, 70, 53, 83, 49, 91, 36, 80, 92, 51, 66, 70};
    result = s.findMaximumXOR(nums);
    cout << "result = " << result << endl;
}