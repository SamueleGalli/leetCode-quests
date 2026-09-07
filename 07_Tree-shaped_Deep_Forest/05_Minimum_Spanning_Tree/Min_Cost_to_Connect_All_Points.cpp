/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Example 1:

    Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
    Output: 20
        Explanation:
        We can connect the points as shown above to get the minimum cost of 20.
        Notice that there is a unique path between every pair of points.

Example 2:

    Input: points = [[3,12],[-2,5],[-4,1]]
    Output: 18


Constraints:

* 1 <= points.length <= 1000
* -106 <= xi, yi <= 106
* All pairs (xi, yi) are distinct.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class costs
{
    size_t A;
    size_t B;
    int weights;

    friend class Solution;

public:
    costs(const size_t &A, const size_t &B, const int &weights) : A(A), B(B), weights(weights)
    {
    }
};

class Solution
{
private:
    vector<costs> node_weights;
    vector<int> DSU;

    int DSU_find(int node)
    {
        if (DSU[node] != node)
            DSU[node] = DSU_find(DSU[node]);
        return (DSU[node]);
    }

    void set_all(vector<vector<int>> &points)
    {
        DSU.clear();
        node_weights.clear();
        DSU.resize(points.size());

        for (size_t i = 0; i < points.size(); i++)
        {
            for (size_t j = i + 1; j < points.size(); j++)
            {
                int cost_A = abs(points[i][0] - points[j][0]);
                int cost_B = abs(points[i][1] - points[j][1]);
                node_weights.push_back(costs(i, j, cost_A + cost_B));
            }
            DSU[i] = i;
        }

        sort(node_weights.begin(), node_weights.end(),
             [](const costs &A, const costs &B)
             {
                 return (A.weights < B.weights);
             });
    }

public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        size_t num_node = 0;
        int result = 0;

        set_all(points);

        for (const costs &this_node : node_weights)
        {
            if (num_node == points.size() - 1)
                break;
            int node_A = DSU_find(this_node.A);
            int node_B = DSU_find(this_node.B);
            if (node_A != node_B)
            {
                result += this_node.weights;
                num_node++;
                DSU[node_A] = DSU[node_B];
            }
        }
        return (result);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> points;
    int result;

    points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    result = s.minCostConnectPoints(points);
    cout << "result = " << result << endl;

    points = {{3, 12}, {-2, 5}, {-4, 1}};
    result = s.minCostConnectPoints(points);
    cout << "result = " << result << endl;
}