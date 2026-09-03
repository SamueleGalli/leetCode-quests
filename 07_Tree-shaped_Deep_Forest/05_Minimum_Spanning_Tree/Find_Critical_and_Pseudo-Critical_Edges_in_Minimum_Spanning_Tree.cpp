/*
Given a weighted undirected connected graph with n vertices numbered from 0 to n - 1, and an array edges where edges[i] = [ai, bi, weighti] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total edge weight.

Find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, a pseudo-critical edge is that which can appear in some MSTs but not all.

Note that you can return the indices of the edges in any order.

Example 1:

    Input: n = 5, edges = [[0,1,1],[1,2,1],[2,3,2],[0,3,2],[0,4,3],[3,4,3],[1,4,6]]
    Output: [[0,1],[2,3,4,5]]

        Explanation: The figure above describes the graph.
        The following figure shows all the possible MSTs:
        Notice that the two edges 0 and 1 appear in all MSTs, therefore they are critical edges, so we return them in the first list of the output.
        The edges 2, 3, 4, and 5 are only part of some MSTs, therefore they are considered pseudo-critical edges. We add them to the second list of the output.

Example 2:

    Input: n = 4, edges = [[0,1,1],[1,2,1],[2,3,1],[0,3,1]]
    Output: [[],[0,1,2,3]]
        Explanation: We can observe that since all 4 edges have equal weight, choosing any 3 edges from the given 4 will yield an MST. Therefore all 4 edges are pseudo-critical.

Constraints:

* 2 <= n <= 100
* 1 <= edges.length <= min(200, n * (n - 1) / 2)
* edges[i].length == 3
* 0 <= ai < bi < n
* 1 <= weighti <= 1000
* All pairs (ai, bi) are distinct.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>
class Solution
{
private:
    vector<int> DSU;

    int DSU_find(int node)
    {
        if (DSU[node] != node)
            DSU[node] = DSU_find(DSU[node]);

        return (DSU[node]);
    }

    int set_all_up(int &n, vector<vector<int>> &edges,
                   int count = 0, int num_nodes = 0)
    {
        sort(edges.begin(), edges.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return (a[2] < b[2]);
             });

        DSU.resize(n);

        for (size_t i = 0; i < n; i++)
            DSU[i] = i;

        for (size_t i = 0; i < edges.size() && num_nodes < n - 1; i++)
        {
            int a = DSU_find(edges[i][0]);
            int b = DSU_find(edges[i][1]);
            if (a != b)
            {
                DSU[a] = DSU[b];
                count += edges[i][2];
                num_nodes++;
            }
        }
        return (count);
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> result(2);

        int count = set_all_up(n, edges);

        for (size_t i = 0; i < edges.size(); i++)
        {
            if (Critical(i))
            {
                result[0].push_back(i);
            }
            else if (Pseudo_Critical(i))
            {
                result[1].push_back(i);
            }
        }
    }
};

void testcase(int n, vector<vector<int>> edges)
{
    Solution s;
    vector<vector<int>> result;

    result = s.findCriticalAndPseudoCriticalEdges(n, edges);

    cout << "Critical: ";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "{";
        for (size_t j = 0; j < result[i].size(); j++)
            cout << result[i][j] << "}";
        if (i + 1 < result.size())
            cout << "\nPrseudo-Critical: ";
    }
    cout << "}\n";
}

int main()
{

    testcase(5, {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}});

    testcase(4, {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1}});
}