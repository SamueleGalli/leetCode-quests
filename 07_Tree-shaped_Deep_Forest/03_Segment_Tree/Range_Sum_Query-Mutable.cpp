/*
Given an integer array nums, handle multiple queries of the following types:
1) Update the value of an element in nums.
2) Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:
* NumArray(int[] nums) Initializes the object with the integer array nums.
* void update(int index, int val) Updates the value of nums[index] to be val.
* int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

Example 1:

    Input
    ["NumArray", "sumRange", "update", "sumRange"]
    [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
    Output
    [null, 9, null, 8]
        Explanation
        NumArray numArray = new NumArray([1, 3, 5]);
        numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
        numArray.update(1, 2);   // nums = [1, 2, 5]
        numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8

Constraints:

* 1 <= nums.length <= 3 * 10^4
* -100 <= nums[i] <= 100
* 0 <= index < nums.length
* -100 <= val <= 100
* 0 <= left <= right < nums.length
* At most 3 * 10^4 calls will be made to update and sumRange.
*/

using namespace std;

#include <iostream>
#include <vector>

class NumArray
{
private:
    vector<int> SegementTree;
    pair<int, int> range;
    int create_tree(const vector<int> &nums, pair<int, int> range, int index = 1)
    {
        if (range.first == range.second)
        {
            SegementTree[index] = nums[range.first];
            return (SegementTree[index]);
        }

        int mid = (range.first + range.second) / 2;
        int left_index = index * 2;
        int right_index = index * 2 + 1;

        SegementTree[left_index] = create_tree(nums, {range.first, mid}, index * 2);
        SegementTree[right_index] = create_tree(nums, {mid + 1, range.second}, index * 2 + 1);

        SegementTree[index] = SegementTree[left_index] + SegementTree[right_index];

        return (SegementTree[index]);
    }

    void update_node(int &index, int &val, pair<int, int> range, int treeindex = 1)
    {
        if (range.first == range.second)
        {
            SegementTree[treeindex] = val;
            return;
        }

        int mid = (range.first + range.second) / 2;
        int left_node = treeindex * 2;
        int right_node = (treeindex * 2) + 1;
        if (index <= mid)
            update_node(index, val, {range.first, mid}, left_node);
        else
            update_node(index, val, {mid + 1, range.second}, right_node);
        SegementTree[treeindex] = SegementTree[left_node] + SegementTree[right_node];
    }

    int give_total(int &left, int &right, pair<int, int> range, int Treenode = 1)
    {
        int mid = (range.first + range.second) / 2;
        int result = 0;

        if (range.first >= left && range.second <= right)
            result += SegementTree[Treenode];
        else if (range.second < left || range.first > right)
            result += 0;
        else
        {
            result += give_total(left, right, {range.first, mid}, (Treenode * 2));
            result += give_total(left, right, {mid + 1, range.second}, (Treenode * 2) + 1);
        }
        return (result);
    }

public:
    NumArray(vector<int> &nums)
    {
        SegementTree.clear();
        SegementTree.resize(nums.size() * 4, 0);
        range = {0, static_cast<int>(nums.size() - 1)};
        create_tree(nums, range);
    }

    void update(int index, int val)
    {
        update_node(index, val, range);
    }

    int sumRange(int left, int right)
    {
        return (give_total(left, right, range));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main()
{
    vector<int> array = {1, 3, 5};
    NumArray *NM = new NumArray(array);

    cout << "la somma e = " << NM->sumRange(0, 2) << endl;
    NM->update(1, 2);
    cout << "la somma e = " << NM->sumRange(0, 2) << endl;

    delete (NM);
}