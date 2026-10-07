/*
Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:

    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 4

Example 2:

    Input: matrix = [["0","1"],["1","0"]]
    Output: 1

Example 3:

    Input: matrix = [["0"]]
    Output: 0


Constraints:

* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 300
* matrix[i][j] is '0' or '1'.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        int dim = 0;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[i].size(); j++)
            {
                if ((i == 0 || j == 0) && matrix[i][j] == '1')
                {
                    dp[i][j] = 1;
                    dim = max(1,dim);
                    continue;
                }

                if (matrix[i][j] == '1')
                {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    dim = max(dim, dp[i][j]);
                }
            }
        }
        return (dim * dim);
    }
};

int main()
{
    Solution s;
    vector<vector<char>> matrix;
    int result;

    matrix = {{'1', '0', '1', '0', '0'},
              {'1', '0', '1', '1', '1'},
              {'1', '1', '1', '1', '1'},
              {'1', '0', '0', '1', '0'}};
    result = s.maximalSquare(matrix);
    cout << "result = " << result << endl;

    matrix = {{'0', '1'},
              {'1', '0'}};
    result = s.maximalSquare(matrix);
    cout << "result = " << result << endl;

    matrix = {{'0'}};
    result = s.maximalSquare(matrix);
    cout << "result = " << result << endl;

    matrix = {{'0', '0', '1'},
              {'0', '1', '1'},
              {'1', '1', '1'}};
    result = s.maximalSquare(matrix);
    cout << "result = " << result << endl;

    matrix = {{'1', '1', '1', '1', '0'},
              {'1', '1', '1', '1', '0'},
              {'1', '1', '1', '1', '1'},
              {'1', '1', '1', '1', '1'},
              {'0', '0', '1', '1', '1'}};
    result = s.maximalSquare(matrix);
    cout << "result = " << result << endl;
}