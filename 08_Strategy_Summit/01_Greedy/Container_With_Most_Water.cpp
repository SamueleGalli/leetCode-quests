/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.
Notice that you may not slant the container.

Example 1:

    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
        Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

    Input: height = [1,1]
    Output: 1

Constraints:

* n == height.length
* 2 <= n <= 10^5
* 0 <= height[i] <= 10^4
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max_area = 0;
        int edges = 0;
        int i_left = 0;
        int i_right = static_cast<int>(height.size() - 1);

        while (i_left != i_right)
        {
            edges = min(height[i_left], height[i_right]);

            max_area = max(max_area, (edges * (i_right - i_left)));

            if (height[i_left] <= height[i_right])
                i_left++;
            else
                i_right--;
        }
        return (max_area);
    }
};

int main()
{
    Solution s;
    int result;
    vector<int> height;

    height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    result = s.maxArea(height);
    cout << "result = " << result << endl;

    height = {1, 1};
    result = s.maxArea(height);
    cout << "result = " << result << endl;

    height = {1, 2, 1};
    result = s.maxArea(height);
    cout << "result = " << result << endl;
}