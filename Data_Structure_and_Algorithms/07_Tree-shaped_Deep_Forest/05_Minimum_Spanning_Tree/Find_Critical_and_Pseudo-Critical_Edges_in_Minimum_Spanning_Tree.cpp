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
#include <limits>

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

    int Critical_and_Pseudo(const vector<vector<int>> &edges, int &n, int type, int node = -1)
    {
        int count = 0;
        int c_nodes = 0;
        int A;
        int B;

        DSU.resize(n);

        for (int i = 0; i < n; i++)
            DSU[i] = i;

        if (type == 2)
        {
            A = DSU_find(edges[node][0]);
            B = DSU_find(edges[node][1]);
            DSU[A] = DSU[B];
            count += edges[node][2];
            c_nodes++;
        }
        for (size_t i = 0; i < edges.size() && c_nodes < n - 1; i++)
        {
            if (type == 1 && i == static_cast<size_t>(node))
                continue;

            A = DSU_find(edges[i][0]);
            B = DSU_find(edges[i][1]);
            if (A != B)
            {
                DSU[A] = DSU[B];
                count += edges[i][2];
                c_nodes++;
            }
        }
        if (c_nodes < n - 1 && type == 1)
            return (numeric_limits<int>::max());
        return (count);
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> result(2);
        int count;

        for (size_t i = 0; i < edges.size(); i++)
            edges[i].push_back(i);

        sort(edges.begin(), edges.end(),
             [](const vector<int> &a, const vector<int> &b)
             {
                 return (a[2] < b[2]);
             });

        count = Critical_and_Pseudo(edges, n, 0);

        for (size_t i = 0; i < edges.size(); i++)
        {
            if (Critical_and_Pseudo(edges, n, 1, i) > count)
                result[0].push_back(edges[i][3]);
            else if (Critical_and_Pseudo(edges, n, 2, i) == count)
                result[1].push_back(edges[i][3]);
        }
        return (result);
    }
};

void testcase(int n, vector<vector<int>> edges)
{
    Solution s;
    vector<vector<int>> result;

    result = s.findCriticalAndPseudoCriticalEdges(n, edges);

    cout << "Critical: {";
    for (size_t i = 0; i < result[0].size(); i++)
    {
        cout << result[0][i];
        if (i + 1 < result[0].size())
            cout << ", ";
    }
    cout << "}\nPseudo-Critical: {";
    for (size_t i = 0; i < result[1].size(); i++)
    {
        cout << result[1][i];
        if (i + 1 < result[1].size())
            cout << ", ";
    }
    cout << "}\n\n";
}

int main()
{

    testcase(5, {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}});

    testcase(4, {{0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {0, 3, 1}});
    testcase(6, {{0, 1, 1}, {1, 2, 1}, {0, 2, 1}, {2, 3, 4}, {3, 4, 2}, {3, 5, 2}, {4, 5, 2}});
}