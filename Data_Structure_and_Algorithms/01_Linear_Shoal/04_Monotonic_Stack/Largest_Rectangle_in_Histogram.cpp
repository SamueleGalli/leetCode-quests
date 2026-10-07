/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.



Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4



Constraints:

    * 1 <= heights.length <= 10^5
    * 0 <= heights[i] <= 10^4
*/

using namespace std;

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Solution
{
private:
    int get_higher(stack<int> &higher, const vector<int> &heights, int result, size_t end, int base = 0,
                   int start = 0, int index = 0)
    {
        while (!higher.empty() && (end == heights.size() || heights[end] <= heights[higher.top()]))
        {
            index = higher.top();
            higher.pop();
            if (higher.empty())
                start = -1;
            else
                start = higher.top();
            base = end - start - 1;
            result = max(result, base * heights[index]);
        }
        return (result);
    }

public:
    int
    largestRectangleArea(vector<int> &heights)
    {
        stack<int> higher;
        int result = 0;
        for (size_t i = 0; i <= heights.size(); i++)
        {
            result = get_higher(higher, heights, result, i);
            higher.push(i);
        }
        higher.pop();
        return (result);
    }
};

int main()
{
    Solution s;
    int result;
    vector<int> height;

    height = {2};
    result = s.largestRectangleArea(height);
    cout << "result = " << result << "\n---------------------------------------------------\n";

    height = {4, 2};
    result = s.largestRectangleArea(height);
    cout << "result = " << result << "\n---------------------------------------------------\n";

    height = {2, 1, 2};
    result = s.largestRectangleArea(height);
    cout << "result = " << result << "\n---------------------------------------------------\n";

    height = {2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2};
    result = s.largestRectangleArea(height);
    cout << "result = " << result << "\n---------------------------------------------------\n";

    height = {0, 9};
    result = s.largestRectangleArea(height);
    cout << "result = " << result << "\n---------------------------------------------------\n";

    height = {9, 0};
    result = s.largestRectangleArea(height);
    cout << "result = " << result << "\n---------------------------------------------------\n";

    height = {2, 1, 5, 6, 2, 3};
    result = s.largestRectangleArea(height);
    cout << "result = " << result << "\n---------------------------------------------------\n";

    height = {2, 4};
    result = s.largestRectangleArea(height);
    cout << "result = " << result << "\n---------------------------------------------------\n";
}
