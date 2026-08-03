/*
You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

Example 1:
    Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
    Output: 16
        Explanation: The perimeter is the 16 yellow stripes in the image above.

Example 2:
    Input: grid = [[1]]
    Output: 4

Example 3:
    Input: grid = [[1,0]]
    Output: 4


Constraints:
* row == grid.length
* col == grid[i].length
* 1 <= row, col <= 100
* grid[i][j] is 0 or 1.
* There is exactly one island in grid.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    int give_size(vector<vector<int>> &grid, size_t i, size_t j)
    {
        int sum = 0;
        grid[i][j] = -1;
        if (i + 1 < grid.size() && grid[i + 1][j] == 1)
            sum += give_size(grid, i + 1, j);
        else if ((i + 1 < grid.size() && grid[i + 1][j] == 0) || i == grid.size() - 1)
            sum++;
        if (i != 0 && grid[i - 1][j] == 1)
            sum += give_size(grid, i - 1, j);
        else if ((i != 0 && grid[i - 1][j] == 0) || i == 0)
            sum++;
        if (j + 1 < grid[i].size() && grid[i][j + 1] == 1)
            sum += give_size(grid, i, j + 1);
        else if ((j + 1 < grid[i].size() && grid[i][j + 1] == 0) || j == grid[i].size() - 1)
            sum++;
        if (j != 0 && grid[i][j - 1] == 1)
            sum += give_size(grid, i, j - 1);
        else if ((j != 0 && grid[i][j - 1] == 0) || j == 0)
            sum++;
        return (sum);
    }

public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        for (size_t i = 0; i < grid.size(); i++)
        {
            for (size_t j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 1)
                    return (give_size(grid, i, j));
            }
        }
        return (0);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid;
    int result;

    grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}};
    result = s.islandPerimeter(grid);
    cout << "result = " << result << "\n\n";

    grid = {{1}};
    result = s.islandPerimeter(grid);
    cout << "result = " << result << "\n\n";

    grid = {{1, 0}};
    result = s.islandPerimeter(grid);
    cout << "result = " << result << "\n\n";

    grid = {{0}, {1}};
    result = s.islandPerimeter(grid);
    cout << "result = " << result << "\n\n";
}