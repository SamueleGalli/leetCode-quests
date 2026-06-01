/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.



Example 1:

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]
        Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

    Input: intervals = [[1,4],[4,5]]
    Output: [[1,5]]
        Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Example 3:

    Input: intervals = [[4,7],[1,4]]
    Output: [[1,7]]
        Explanation: Intervals [1,4] and [4,7] are considered overlapping.

Constraints:

* 1 <= intervals.length <= 104
* intervals[i].length == 2
* 0 <= starti <= endi <= 104
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {

        vector<vector<int>> result;
        pair<int, int> limit;

        sort(intervals.begin(), intervals.end(), [](const vector<int> &first, const vector<int> &second)
             { return (first[0] < second[0]); });
        limit.first = intervals[0][0];
        limit.second = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i - 1][1] >= intervals[i][0])
            {
                limit.first = min(intervals[i - 1][0], limit.first);
                limit.second = max(intervals[i][1], limit.second);
            }
            else
            {
                result.push_back({limit.first, limit.second});
                limit.first = intervals[i][0];
                limit.second = intervals[i][1];
            }
        }
        result.push_back({limit.first, limit.second});
        return (result);
    }
};

void print_result(vector<vector<int>> result)
{
    if (result.empty())
    {
        cout << "result = {{}}\n\n";
        return;
    }
    cout << "result {{";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " , " << result[i][1];
        if (i + 1 == result.size())
            cout << "}};\n\n";
        else
            cout << "}, {";
    }
}

int main()
{
    Solution s;
    vector<vector<int>> intervals;
    vector<vector<int>> result;

    intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    result = s.merge(intervals);
    print_result(result);

    intervals = {{1, 4}, {4, 5}};
    result = s.merge(intervals);
    print_result(result);

    intervals = {{4, 7}, {1, 4}};
    result = s.merge(intervals);
    print_result(result);

    intervals = {{1, 3}};
    result = s.merge(intervals);
    print_result(result);

    intervals = {{1, 4}, {5, 6}};
    result = s.merge(intervals);
    print_result(result);

    intervals = {{1, 4}, {0, 5}};
    result = s.merge(intervals);
    print_result(result);

    intervals = {{0, 2}, {1, 4}, {2, 6}};
    result = s.merge(intervals);
    print_result(result);
}