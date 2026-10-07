/*
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

You want to determine if there is a valid path that exists from vertex source to vertex destination.

Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

Example 1:

    Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
    Output: true
        Explanation: There are two paths from vertex 0 to vertex 2:
        - 0 → 1 → 2
        - 0 → 2

Example 2:

    Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
    Output: false
        Explanation: There is no path from vertex 0 to vertex 5.

Constraints:

* 1 <= n <= 2 * 10^5
* 0 <= edges.length <= 2 * 10^5
* edges[i].length == 2
* 0 <= ui, vi <= n - 1
* ui != vi
* 0 <= source, destination <= n - 1
* There are no duplicate edges.
* There are no self edges.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    vector<vector<int>> graph;

    void set_value(const vector<vector<int>> &edges)
    {
        for (const vector<int> &node : edges)
        {
            graph[node[0]].push_back(node[1]);
            graph[node[1]].push_back(node[0]);
        }
    }

    bool valid(vector<char> &seen, int i, int dest)
    {
        if (i == dest)
            return (true);
        for (int to_go : graph[i])
        {
            if (seen[to_go] == 1)
                continue;
            seen[to_go] = 1;
            if (valid(seen, to_go, dest) == true)
                return true;
        }
        return (false);
    }

public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        graph.clear();
        graph.resize(n);
        vector<char> seen(n, 0);

        set_value(edges);

        return (valid(seen, source, destination));
    }
};

void testcase(vector<vector<int>> &edges, int n, int source, int destination)
{
    Solution s;
    bool result;

    result = s.validPath(n, edges, source, destination);
    cout << boolalpha << "result = " << result << endl;
}

int main()
{
    vector<vector<int>> edges;

    testcase(edges = {{0, 1}, {1, 2}, {2, 0}}, 3, 0, 2);
    testcase(edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}}, 6, 0, 5);
}
