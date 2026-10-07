/*
You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [a_i, b_i] denotes that there exists an undirected edge connecting vertices a_i and b_i.

Return the number of complete connected components of the graph.

A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be complete if there exists an edge between every pair of its vertices.

Example 1:
    Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
    Output: 3
        Explanation: From the picture above, one can see that all of the components of this graph are complete.

Example 2:
    Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
    Output: 1
        Explanation: The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.


Constraints:

* 1 <= n <= 50
* 0 <= edges.length <= n * (n - 1) / 2
* edges[i].length == 2
* 0 <= a_i, b_i <= n - 1
* a_i != b_i
* There are no repeated edges.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    vector<char> visited;
    vector<vector<int>> graph;
    vector<int> nodes;

    void find_loop(int i)
    {
        if (visited[i] != 1)
        {
            visited[i] = 1;
            for (int value : graph[i])
            {
                if (visited[value] == 0)
                {
                    nodes.push_back(value);
                    find_loop(value);
                }
            }
        }
    }

    void alloc_all(vector<vector<int>> &edges, int n)
    {
        graph.clear();
        nodes.clear();
        visited.clear();
        graph.resize(n);
        visited.resize(n, 0);
        nodes.reserve(n);

        for (size_t i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
    }

    bool check_validity(void)
    {
        for (size_t i = 0; i < nodes.size(); i++)
        {
            if (graph[nodes[i]].size() != nodes.size() - 1)
                return (false);
        }
        return (true);
    }

public:
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        int result = 0;

        alloc_all(edges, n);

        for (size_t i = 0; i < graph.size(); i++)
        {
            if (visited[i] == 0)
            {
                nodes.push_back(i);
                find_loop(i);
                if (check_validity())
                    result++;
                nodes.clear();
            }
        }
        return (result);
    }
};

void testcase(int n, vector<vector<int>> &edges)
{
    Solution s;
    int result;

    result = s.countCompleteComponents(n, edges);
    cout << "result = " << result << endl;
}

int main()
{
    vector<vector<int>> edges;

    edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}};
    testcase(6, edges);

    edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
    testcase(6, edges);

    edges = {{9, 15}, {4, 9}, {0, 4}, {3, 4}, {8, 9}, {6, 4}, {12, 15}, {13, 8}, {3, 13}, {9, 6}, {2, 5}, {2, 10}, {2, 11}, {2, 7}, {2, 14}, {5, 10}, {5, 11}, {5, 7}, {5, 14}, {10, 11}, {10, 7}, {10, 14}, {11, 7}, {11, 14}, {7, 14}};
    testcase(16, edges);
}