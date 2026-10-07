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
#include <algorithm>

class Solution
{
private:
    void create_comb(vector<vector<int>> &result,
                     const int &n, const int &k,
                     vector<int> &array, int i = 1)
    {
        if (array.size() == static_cast<size_t>(k))
        {
            result.push_back(array);
            return;
        }
        for (; i <= n; i++)
        {
            array.push_back(i);
            create_comb(result, n, k, array, i + 1);
            array.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> result;
        vector<int> array;
        create_comb(result, n, k, array);
        return (result);
    }
};

void print_mat(const vector<vector<int>> &result, int k)
{
    if (result.size() == 0)
    {
        cout << "result = {{}};\n";
        return;
    }
    cout << "result = {{";
    for (size_t i = 0; i < result.size(); i++)
    {
        for (size_t j = 0; j < static_cast<size_t>(k); j++)
        {
            cout << result[i][j];
            if (j + 1 < static_cast<size_t>(k))
                cout << ", ";
        }
        cout << "}";
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
    print_mat(result, k);

    n = 1;
    k = 1;
    result = s.combine(n, k);
    print_mat(result, k);

    n = 5;
    k = 1;
    result = s.combine(n, k);
    print_mat(result, k);

    n = 5;
    k = 3;
    result = s.combine(n, k);
    print_mat(result, k);
}