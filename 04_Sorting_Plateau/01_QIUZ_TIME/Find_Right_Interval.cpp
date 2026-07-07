/*

You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.



Example 1:

    Input: intervals = [[1,2]]
    Output: [-1]
        Explanation: There is only one interval in the collection, so it outputs -1.

Example 2:
    Input: intervals = [[3,4],[2,3],[1,2]]
    Output: [-1,0,1]
        Explanation: There is no right interval for [3,4].
        The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
        The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.

Example 3:
    Input: intervals = [[1,4],[2,3],[3,4]]
    Output: [-1,2,-1]
        Explanation: There is no right interval for [1,4] and [3,4].
        The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.


Constraints:

* 1 <= intervals.length <= 2 * 104
* intervals[i].length == 2
* -106 <= starti <= endi <= 106
* The start point of each interval is unique.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

void print_vector(const vector<int> &result)
{
    cout << "{";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "};\n";
}

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        vector<pair<int, size_t>> index;
        vector<int> result(intervals.size());
        vector<pair<int, size_t>>::iterator value;

        for (size_t i = 0; i < intervals.size(); i++)
            index.push_back({intervals[i][0], i});

        sort(index.begin(), index.end(), [](pair<int, size_t> &a, pair<int, size_t> &b)
             { return (a.first < b.first); });

        for (size_t i = 0; i < intervals.size(); i++)
        {
            value = lower_bound(index.begin(), index.end(), intervals[i][1], [](pair<int, size_t> &a, int b)
                                { return (a.first < b); });
            if (value != index.end())
                result[i] = static_cast<int>(value->second);
            else
                result[i] = -1;
        }

        return (result);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> intervals;
    vector<int> result;

    intervals = {{1, 2}};
    result = s.findRightInterval(intervals);
    print_vector(result);

    intervals = {{3, 4}, {2, 3}, {1, 2}};
    result = s.findRightInterval(intervals);
    print_vector(result);

    intervals = {{1, 4}, {2, 3}, {3, 4}};
    result = s.findRightInterval(intervals);
    print_vector(result);
}