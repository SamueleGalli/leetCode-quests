/*
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.



Example 1:

    Input: n = 4, k = 2
    Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
        Explanation: There are 4 choose 2 = 6 total combinations.
        Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

    Input: n = 1, k = 1
    Output: [[1]]
        Explanation: There is 1 choose 1 = 1 total combination.


Constraints:

* 1 <= n <= 20
* 1 <= k <= n
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
    }
};

void print_mat(const vector<vector<int>> &result)
{
    cout << "result = {";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << ", " << result[i][1] << "}";
        if (i + 1 < result.size())
            cout << ", {";
    }
    cout << "};\n\n";
}

int main()
{
    Solution s;
    int n;
    int k;
    vector<vector<int>> result;

    n = 4;
    k = 2;
    result = s.combine(n, k);
    print_mat(result);

    n = 1;
    k = 1;
    result = s.combine(n, k);
    print_mat(result);
}