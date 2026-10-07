/*
You are given an integer array of unique positive integers nums. Consider the following graph:

There are nums.length nodes, labeled nums[0] to nums[nums.length - 1],
There is an undirected edge between nums[i] and nums[j] if nums[i] and nums[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

Example 1:

    Input: nums = [4,6,15,35]
    Output: 4

Example 2:


    Input: nums = [20,50,9,63]
    Output: 2

Example 3:

    Input: nums = [2,3,6,7,4,12,21,39]
    Output: 8


Constraints:

* 1 <= nums.length <= 2 * 10^4
* 1 <= nums[i] <= 10^5
* All the values of nums are unique.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution
{
private:
    size_t find_root(vector<size_t> &union_find, size_t index)
    {

        if (union_find[index] != index)
            union_find[index] = find_root(union_find, union_find[index]);

        return (union_find[index]);
    }

    int union_maybe(unordered_map<int, size_t> &find_me, vector<size_t> &union_find, vector<int> &all_size,
                    const int &factor, size_t &index)
    {
        size_t root_current = 0;
        size_t root_seen = 0;
        int total = 0;

        if (find_me.count(factor))
        {
            root_current = find_root(union_find, index);
            root_seen = find_root(union_find, find_me[factor]);
            if (root_current != root_seen)
            {
                total = all_size[root_current] + all_size[root_seen];
                if (all_size[root_current] >= all_size[root_seen])
                {
                    all_size[root_current] += all_size[root_seen];
                    union_find[root_seen] = union_find[root_current];
                }
                else
                {
                    all_size[root_seen] += all_size[root_current];
                    union_find[root_current] = union_find[root_seen];
                }
            }
        }
        find_me[factor] = index;
        return (total);
    }

    void prime_factors_of_value(unordered_map<int, size_t> &find_me, vector<size_t> &union_find,
                                vector<int> &all_size, const vector<int> &nums, int &max_size)
    {
        int value = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            value = nums[i];
            for (int factor = 2; factor * factor <= value;)
            {
                if (value % factor == 0)
                {
                    value /= factor;
                    max_size = max(max_size, union_maybe(find_me, union_find, all_size, factor, i));
                }
                else
                    factor++;
            }
            if (value > 1)
                max_size = max(max_size, union_maybe(find_me, union_find, all_size, value, i));
        }
    }

public:
    int largestComponentSize(vector<int> &nums)
    {
        vector<size_t> union_find(nums.size());
        unordered_map<int, size_t> find_me;
        vector<int> all_size(nums.size(), 1);
        int max_size = 1;

        for (size_t i = 0; i < nums.size(); i++)
            union_find[i] = i;
            
        prime_factors_of_value(find_me, union_find, all_size, nums, max_size);

        return (max_size);
    }
};

int main()
{
    Solution s;
    vector<int> nums;
    int result;

    nums = {4, 6, 15, 35};
    result = s.largestComponentSize(nums);
    cout << "result = " << result << endl;

    nums = {20, 50, 9, 63};
    result = s.largestComponentSize(nums);
    cout << "result = " << result << endl;

    nums = {2, 3, 6, 7, 4, 12, 21, 39};
    result = s.largestComponentSize(nums);
    cout << "result = " << result << endl;

    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    result = s.largestComponentSize(nums);
    cout << "result = " << result << endl;

    nums = {2, 4, 8};
    result = s.largestComponentSize(nums);
    cout << "result = " << result << endl;
}