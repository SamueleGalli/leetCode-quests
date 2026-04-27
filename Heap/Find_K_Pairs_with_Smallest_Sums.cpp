/*
You are given two integer arrays nums1 and nums2 sorted in non-decreasing order and an integer k.

Define a pair (u, v) which consists of one element from the first array and one element from the second array.

Return the k pairs (u1, v1), (u2, v2), ..., (uk, vk) with the smallest sums.



Example 1:

    Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
    Output: [[1,2],[1,4],[1,6]]
        Explanation: The first 3 pairs are returned from the sequence: [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:

    Input: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
    Output: [[1,1],[1,1]]
        Explanation: The first 2 pairs are returned from the sequence: [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]



Constraints:

    * 1 <= nums1.length, nums2.length <= 105
    * -109 <= nums1[i], nums2[i] <= 109
    * nums1 and nums2 both are sorted in non-decreasing order.
    * 1 <= k <= 104
    * k <= nums1.length * nums2.length

*/

using namespace std;

#include <iostream>
#include <queue>
#include <vector>

struct Smallest
{
    size_t i, j;
    int sum;

    Smallest(size_t i, size_t j, int sum) : i(i), j(j), sum(sum)
    {
    }
    bool operator>(const Smallest &small) const
    {
        return sum > small.sum;
    }
};

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> result;
        priority_queue<Smallest, vector<Smallest>, greater<Smallest>> find_min;

        size_t j, i = 0;
        while (i < nums1.size() && i < static_cast<size_t>(k))
        {
            find_min.push({i, 0, nums1[i] + nums2[0]});
            i++;
        }

        while (k > 0)
        {
            i = find_min.top().i;
            j = find_min.top().j;

            result.push_back({nums1[i], nums2[j]});
            find_min.pop();
            if (j + 1 < nums2.size())
                find_min.push({i, j + 1, nums1[i] + nums2[j + 1]});
            k--;
        }
        return (result);
    }
};

void stamp_vec(const vector<vector<int>> &result)
{
    cout << "result = {";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "{";
        cout << result[i][0] << ", " << result[i][1];
        if (i + 1 < result.size())
            cout << "}, ";
    }
    cout << "};\n------------------------------------------------------------\n";
}

int main()
{
    Solution s;
    vector<int> nums1;
    vector<int> nums2;
    int k;
    vector<vector<int>> result;

    nums1 = {1, 7, 11};
    nums2 = {2, 4, 6};
    k = 3;
    result = s.kSmallestPairs(nums1, nums2, k);
    stamp_vec(result);

    nums1 = {1, 1, 2};
    nums2 = {1, 2, 3};
    k = 2;
    result = s.kSmallestPairs(nums1, nums2, k);
    stamp_vec(result);
}
