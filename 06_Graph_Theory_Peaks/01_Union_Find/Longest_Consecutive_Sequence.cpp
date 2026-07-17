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

    void allocator(const vector<int> &nums, unordered_map<int, size_t> &finder,
                   vector<int> &count, vector<int> &union_find)
    {
        finder.reserve(nums.size());
        count.reserve(nums.size());
        union_find.reserve(nums.size());

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (!finder.count(nums[i]))
            {
                count.push_back(1);
                finder[nums[i]] = union_find.size();
                union_find.push_back(union_find.size());
            }
        }
    }

    void union_find_function(vector<int> &count, vector<int> &union_find,
        int &max_count, const size_t &current, const size_t &it_next)
    {
        size_t r_current = find_element(union_find, current);
        size_t r_next = find_element(union_find, it_next);
        max_count = max(max_count, count[r_next] + count[r_current]);
        if (count[r_current] >= count[r_next])
        {
            union_find[r_next] = r_current;
            count[r_current] += count[r_next];
        }
        else
        {
            union_find[r_current] = r_next;
            count[r_next] += count[r_current];
        }
    }

public:
    int longestConsecutive(vector<int> &nums)
    {
        vector<int> union_find;
        vector<int> count;
        unordered_map<int, size_t> finder;
        unordered_map<int, size_t>::iterator it_next;
        int max_count = 0;

        allocator(nums, finder, count, union_find);

        for (pair<const int, size_t> &value : finder)
        {
            it_next = finder.find(value.first + 1);
            if (it_next != finder.end())
                union_find_function(count, union_find, max_count, value.second, it_next->second);
            else
                max_count = max(max_count, 1);
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

    nums = {1};
    result = s.longestConsecutive(nums);
    cout << "result = " << result << endl;

    nums = {};
    result = s.longestConsecutive(nums);
    cout << "result = " << result << endl;
}
