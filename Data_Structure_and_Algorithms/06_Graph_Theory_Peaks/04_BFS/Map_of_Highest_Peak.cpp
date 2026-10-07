/*
You are given an integer matrix isWater of size m x n that represents a map of land and water cells.

If isWater[i][j] == 0, cell (i, j) is a land cell.
If isWater[i][j] == 1, cell (i, j) is a water cell.
You must assign each cell a height in a way that follows these rules:

The height of each cell must be non-negative.
If the cell is a water cell, its height must be 0.
Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
Find an assignment of heights such that the maximum height in the matrix is maximized.

Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

Example 1:

    Input: isWater = [[0,1],[0,0]]
    Output: [[1,0],[2,1]]
        Explanation: The image shows the assigned heights of each cell.
        The blue cell is the water cell, and the green cells are the land cells.

Example 2:

    Input: isWater = [[0,0,1],[1,0,0],[0,0,0]]
    Output: [[1,1,0],[0,1,1],[1,2,2]]
        Explanation: A height of 2 is the maximum possible height of any assignment.
        Any height assignment that has a maximum height of 2 while still meeting the rules will also be accepted.

Constraints:

* m == isWater.length
* n == isWater[i].length
* 1 <= m, n <= 1000
* isWater[i][j] is 0 or 1.
* There is at least one water cell.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

class Solution
{
private:
    queue<pair<size_t, size_t>> list;
    vector<vector<int>> visited;

    void add_to_list(vector<vector<int>> &isWater, pair<size_t, size_t> land)
    {
        if (land.first + 1 < isWater.size() && visited[land.first + 1][land.second] == 0)
        {
            isWater[land.first + 1][land.second] = isWater[land.first][land.second] + 1;
            list.push({land.first + 1, land.second});
            visited[land.first + 1][land.second] = 1;
        }
        if (land.first != 0 && visited[land.first - 1][land.second] == 0)
        {
            isWater[land.first - 1][land.second] = isWater[land.first][land.second] + 1;
            list.push({land.first - 1, land.second});
            visited[land.first - 1][land.second] = 1;
        }
        if (land.second + 1 < isWater[land.first].size() && visited[land.first][land.second + 1] == 0)
        {
            isWater[land.first][land.second + 1] = isWater[land.first][land.second] + 1;
            list.push({land.first, land.second + 1});
            visited[land.first][land.second + 1] = 1;
        }
        if (land.second != 0 && visited[land.first][land.second - 1] == 0)
        {
            isWater[land.first][land.second - 1] = isWater[land.first][land.second] + 1;
            list.push({land.first, land.second - 1});
            visited[land.first][land.second - 1] = 1;
        }
    }
    void water_height(vector<vector<int>> &isWater)
    {
        while (!list.empty())
        {
            add_to_list(isWater, list.front());
            list.pop();
        }
    }

public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        visited.clear();
        visited.resize(isWater.size(), vector<int>(isWater[0].size(), 0));
        for (size_t i = 0; i < isWater.size(); i++)
        {
            for (size_t j = 0; j < isWater[i].size(); j++)
            {
                if (isWater[i][j] == 1)
                {
                    list.push({i, j});
                    isWater[i][j] = 0;
                    visited[i][j] = 1;
                }
            }
        }
        water_height(isWater);
        return (isWater);
    }
};

void print_result(const vector<vector<int>> &result)
{
    cout << "result = {";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "{";
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j + 1 < result[i].size())
                cout << ", ";
        }
        cout << "}";
        if (i + 1 < result.size())
            cout << ", ";
        cout << "\n";
    }
    cout << "};\n\n";
}

int main()
{
    Solution s;
    vector<vector<int>> result;
    vector<vector<int>> isWater;

    isWater = {{0, 1}, {0, 0}};
    result = s.highestPeak(isWater);
    print_result(result);

    isWater = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    result = s.highestPeak(isWater);
    print_result(result);
}