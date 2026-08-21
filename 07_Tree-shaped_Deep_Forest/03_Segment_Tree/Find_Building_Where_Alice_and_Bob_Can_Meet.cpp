/*
You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.
If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].
You are also given another array queries where queries[i] = [a_i, b_i]. On the ith query, Alice is in building a_i while Bob is in building b_i.
Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.

Example 1:

    Input: heights = [6,4,8,5,2,7], queries = [[0,1],[0,3],[2,4],[3,4],[2,2]]
    Output: [2,5,-1,5,2]
        Explanation: In the first query, Alice and Bob can move to building 2 since heights[0] < heights[2] and heights[1] < heights[2].
        In the second query, Alice and Bob can move to building 5 since heights[0] < heights[5] and heights[3] < heights[5].
        In the third query, Alice cannot meet Bob since Alice cannot move to any other building.
        In the fourth query, Alice and Bob can move to building 5 since heights[3] < heights[5] and heights[4] < heights[5].
        In the fifth query, Alice and Bob are already in the same building.
        For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
        For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

Example 2:
    Input: heights = [5,3,8,2,6,1,4,6], queries = [[0,7],[3,5],[5,2],[3,0],[1,6]]
    Output: [7,6,-1,4,6]
        Explanation: In the first query, Alice can directly move to Bob's building since heights[0] < heights[7].
        In the second query, Alice and Bob can move to building 6 since heights[3] < heights[6] and heights[5] < heights[6].
        In the third query, Alice cannot meet Bob since Bob cannot move to any other building.
        In the fourth query, Alice and Bob can move to building 4 since heights[3] < heights[4] and heights[0] < heights[4].
        In the fifth query, Alice can directly move to Bob's building since heights[1] < heights[6].
        For ans[i] != -1, It can be shown that ans[i] is the leftmost building where Alice and Bob can meet.
        For ans[i] == -1, It can be shown that there is no building where Alice and Bob can meet.

Constraints:

* 1 <= heights.length <= 5 * 10^4
* 1 <= heights[i] <= 109
* 1 <= queries.length <= 5 * 10^4
* queries[i] = [a_i, b_i]
* 0 <= a_i, b_i <= heights.length - 1
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
    vector<int> Segment_Tree;

    int check_union(const int &max_heights, const int &index, pair<int, int> range, int Treenode = 1)
    {
        if (range.first == range.second)
            return (max_heights < Segment_Tree[Treenode] ? range.first : -1);

        int mid = (range.first + range.second) / 2;
        int left = Treenode * 2;

        if (mid <= index)
            return (check_union(max_heights, index, {mid + 1, range.second}, left + 1));
        else if (max_heights < Segment_Tree[left])
        {
            int result = check_union(max_heights, index, {range.first, mid}, left);
            if (result != -1)
                return (result);
            return (check_union(max_heights, index, {mid + 1, range.second}, left + 1));
        }
        else
            return (check_union(max_heights, index, {mid + 1, range.second}, left + 1));
    }

    int set_seg_tree(const vector<int> &heights, pair<int, int> range, int Treenode = 1)
    {
        if (range.first == range.second)
            return (Segment_Tree[Treenode] = heights[range.first]);

        int mid = (range.first + range.second) / 2;
        int left = Treenode * 2;
        Segment_Tree[left] = set_seg_tree(heights, {range.first, mid}, left);
        Segment_Tree[left + 1] = set_seg_tree(heights, {mid + 1, range.second}, left + 1);
        return (Segment_Tree[Treenode] = max(Segment_Tree[left], Segment_Tree[left + 1]));
    }

    vector<int> &get_result(vector<int> &ans, const vector<int> &heights,
                            const vector<vector<int>> &queries, pair<int, int> index = {})
    {
        for (size_t i = 0; i < queries.size(); i++)
        {
            index.second = max(queries[i][0], queries[i][1]);
            index.first = min(queries[i][0], queries[i][1]);
            int max_heights = max(heights[queries[i][0]], heights[queries[i][1]]);

            if ((heights[index.first] < heights[index.second]) ||
                (index.second == index.first))
                ans[i] = index.second;
            else
                ans[i] = check_union(max_heights, index.second, {0, static_cast<int>(heights.size() - 1)});
        }
        return (ans);
    }

public:
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        vector<int> ans(queries.size());

        Segment_Tree.clear();
        Segment_Tree.resize((heights.size()) * 4, 0);
        set_seg_tree(heights, {0, static_cast<int>(heights.size() - 1)});

        return (get_result(ans, heights, queries));
    }
};

void print_result(const vector<int> &result)
{
    cout << "result = {";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < result.size())
            cout << ",";
    }
    cout << "};\n\n";
}

int main()
{
    Solution s;
    vector<int> heights;
    vector<vector<int>> queries;
    vector<int> result;

    heights = {6, 4, 8, 5, 2, 7};
    queries = {{0, 1}, {0, 3}, {2, 4}, {3, 4}, {2, 2}};
    result = s.leftmostBuildingQueries(heights, queries);
    print_result(result);

    heights = {5, 3, 8, 2, 6, 1, 4, 6};
    queries = {{0, 7}, {3, 5}, {5, 2}, {3, 0}, {1, 6}};
    result = s.leftmostBuildingQueries(heights, queries);
    print_result(result);

    heights = {1};
    queries = {{0, 0}};
    result = s.leftmostBuildingQueries(heights, queries);
    print_result(result);
}