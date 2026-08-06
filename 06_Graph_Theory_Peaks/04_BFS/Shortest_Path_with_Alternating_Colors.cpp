/*
You are given an integer n, the number of nodes in a directed graph where the nodes are labeled from 0 to n - 1. Each edge is red or blue in this graph, and there could be self-edges and parallel edges.

You are given two arrays redEdges and blueEdges where:

redEdges[i] = [a_i, b_i] indicates that there is a directed red edge from node a_i to node b_i in the graph, and
blueEdges[j] = [u_j, v_j] indicates that there is a directed blue edge from node u_j to node v_j in the graph.
Return an array answer of length n, where each answer[x] is the length of the shortest path from node 0 to node x such that the edge colors alternate along the path, or -1 if such a path does not exist.

Example 1:

    Input: n = 3, redEdges = [[0,1],[1,2]], blueEdges = []
    Output: [0,1,-1]

Example 2:

    Input: n = 3, redEdges = [[0,1]], blueEdges = [[2,1]]
    Output: [0,1,-1]

Constraints:

* 1 <= n <= 100
* 0 <= redEdges.length, blueEdges.length <= 400
* redEdges[i].length == blueEdges[j].length == 2
* 0 <= a_i, b_i, u_j, v_j < n
*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>

class Solution
{
private:
    enum Color
    {
        NONE,
        RED,
        BLUE
    };

    vector<vector<int>> visited;
    vector<vector<pair<int, Color>>> graph;
    queue<pair<int, Color>> list;
    size_t size_nodes;

    void set_variable(const vector<vector<int>> &redEdges, const vector<vector<int>> &blueEdges)
    {
        graph.clear();
        graph.resize(size_nodes);
        visited.clear();
        visited.resize(size_nodes, vector<int>(3));
        visited[0][NONE] = 1;
        list.push({0, NONE});

        for (size_t i = 0; i < redEdges.size(); i++)
            graph[redEdges[i][0]].push_back({redEdges[i][1], RED});

        for (size_t i = 0; i < blueEdges.size(); i++)
            graph[blueEdges[i][0]].push_back({blueEdges[i][1], BLUE});
    }

    void short_path_possibile(vector<int> &result, size_t lenght = 1)
    {
        size_t size_queue = list.size();
        for (size_t i = 0; i < size_queue; i++)
        {
            for (pair<int, Color> &node : graph[list.front().first])
            {
                if (list.front().second != node.second && visited[node.first][node.second] == 0)
                {
                    visited[node.first][node.second] = 1;
                    if (result[node.first] == -1)
                        result[node.first] = lenght;
                    list.push({node.first, node.second});
                }
            }
            list.pop();
        }
        if (list.size() == 0)
            return;
        short_path_possibile(result, lenght + 1);
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<int> result(n, -1);

        size_nodes = static_cast<size_t>(n);
        result[0] = 0;
        set_variable(redEdges, blueEdges);
        short_path_possibile(result);
        return (result);
    }
};

void testcase(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
{
    Solution s;
    vector<int> result;

    result = s.shortestAlternatingPaths(n, redEdges, blueEdges);
    cout << "result = {";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "};\n\n";
}

int main()
{
    vector<vector<int>> redEdges;
    vector<vector<int>> blueEdges;

    testcase(3, redEdges = {{0, 1}, {1, 2}}, blueEdges = {});
    testcase(3, redEdges = {{0, 1}}, blueEdges = {{2, 1}});
    testcase(3, redEdges = {{0, 1}, {0, 2}}, blueEdges = {{1, 0}});
}
