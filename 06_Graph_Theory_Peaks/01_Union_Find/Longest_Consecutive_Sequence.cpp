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

/*TODO Little tiny big bug that ad + 1 (I will crush you)*/
using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

class Solution
{
private:
    int find_element(vector<int> &union_find, int index)
    {
        if (union_find[index] != index)
            union_find[index] = find_element(union_find, union_find[index]);
        return (union_find[index]);
    }

public:
    int longestConsecutive(vector<int> &nums)
    {
        vector<int> union_find(nums.size());
        vector<int> count;
        unordered_map<int, size_t> finder(nums.size());
        int max_count = 0;
        int r_current = 0;
        int r_next = 0;

        count.resize(nums.size(), 1);

        iota(union_find.begin(), union_find.end(), 0);
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (!finder.count(nums[i]))
                finder[nums[i]] = i;
        }

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (finder.count(nums[i] + 1))
            {
                r_current = find_element(union_find, i);
                r_next = find_element(union_find, finder[nums[i] + 1]);
                max_count = max(max_count, count[r_next] + count[r_current]);

                if (count[r_current] >= count[r_next])
                {
                    union_find[r_next] = union_find[r_current];
                    count[r_current] += count[r_next];
                }
                else
                {
                    union_find[r_current] = union_find[r_next];
                    count[r_next] += count[r_current];
                }
            }
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

    nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    result = s.longestConsecutive(nums);
    cout << "result = " << result << endl;

    nums = {1, 0, 1, 2};
    result = s.longestConsecutive(nums);
    cout << "result = " << result << endl;
}
