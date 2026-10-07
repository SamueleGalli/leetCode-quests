/*
An array nums of length n is beautiful if:

nums is a permutation of the integers in the range [1, n].
For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.



Example 1:

    Input: n = 4
    Output: [2,1,4,3]

Example 2:

    Input: n = 5
    Output: [3,1,2,5,4]


Constraints:

*   1 <= n <= 1000
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    void make_beautifull(int n, vector<int> &temp)
    {
        if (n == 1)
        {
            temp.push_back(1);
            return;
        }

        size_t i = 0;
        vector<int> total;
        make_beautifull((n + 1) / 2, temp);

        while (i < temp.size())
        {
            total.push_back(temp[i] * 2);
            i++;
        }
        i = 0;
        while (i < temp.size())
        {
            total.push_back((temp[i] * 2) - 1);
            i++;
        }
        temp = total;
    }

public:
    vector<int> beautifulArray(int n)
    {
        vector<int> temp;
        make_beautifull(n, temp);

        temp.erase(remove_if(temp.begin(), temp.end(), [n](int x)
        {
            return (x > n);
        }), temp.end());
        return (temp);
    }
};

void print_array(const vector<int> &result)
{
    cout << "{";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "}\n\n";
}

int main()
{
    Solution s;
    int n;
    vector<int> result;

    n = 4;
    result = s.beautifulArray(n);
    print_array(result);

    n = 5;
    result = s.beautifulArray(n);
    print_array(result);
}