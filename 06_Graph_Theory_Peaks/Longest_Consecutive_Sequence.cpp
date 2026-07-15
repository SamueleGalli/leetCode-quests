/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

    Input: nums = [100,4,200,1,3,2]
    Output: 4
        Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

    Input: nums = [0,3,7,2,5,8,4,6,0,1]
    Output: 9

Example 3:

    Input: nums = [1,0,1,2]
    Output: 3

Constraints:

* 0 <= nums.length <= 105
* -10^9 <= nums[i] <= 10^9
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
private:
    void union_groups(vector<int> &union_find, int group, int index)
    {
        cout << union_find[index] << " = " << union_find[group] << endl;
        union_find[index] = union_find[group];
    }
    int find_element(vector<int> &union_find, int index)
    {
        cout << union_find[index] << " != " << index << endl;
        while (union_find[index] != index)
        {
            index = union_find[index];
            cout << "loop -> " << union_find[index] << " != " << index << endl;
        }
        return (union_find[index]);
    }

public:
    int longestConsecutive(vector<int> &nums)
    {
        vector<int> union_find(nums.size());
        vector<int> count(nums.size(), 1);
        unordered_map<int, size_t> finder;
        int max_count = 0;

        for (size_t i = 0; i < union_find.size(); i++)
        {
            union_find[i] = i;
            finder[nums[i]] = i;
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            cout << "esiste " << nums[i] + 1 << "? \n" << (finder.count(nums[i] + 1) == 0? "no" : "si")<< endl;
            if (finder.count(nums[i] + 1))
            {
                cout << "cont[" << i << "] = " << count[i] << " + " << count[finder[nums[i] + 1]] << endl;
                count[i] = count[i] + count[finder[nums[i] + 1]];
                max_count = max(max_count, count[i]);
                cout << "max_count attuale = " << max_count << endl;
                union_groups(union_find, find_element(union_find, i), finder[nums[i] + 1]);
            }
            cout << "\n--------------------------------------------------------------\n";
        }
        for (size_t i = 0; i < nums.size();i++)
        {
            cout << "union_find = " << union_find[i] << endl;
            cout << "size = " << count[i] << endl;
        }
        return (max_count);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int result;

    nums = {100, 4, 200, 1, 3, 2};
    result = s.longestConsecutive(nums);
    cout << "result = " << result << endl;

    /* nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    result = s.longestConsecutive(nums);
    cout << "result = " << result << endl;

    nums = {1, 0, 1, 2};
    result = s.longestConsecutive(nums);
    cout << "result = " << result << endl; */
}
