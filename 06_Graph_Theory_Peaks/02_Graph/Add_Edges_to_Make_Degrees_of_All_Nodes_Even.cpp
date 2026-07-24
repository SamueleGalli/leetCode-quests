/*
There is an undirected graph consisting of n nodes numbered from 1 to n. You are given the integer n and a 2D array edges where edges[i] = [a_i, b_i] indicates that there is an edge between nodes a_i and b_i. The graph can be disconnected.

You can add at most two additional edges (possibly none) to this graph so that there are no repeated edges and no self-loops.

Return true if it is possible to make the degree of each node in the graph even, otherwise return false.

The degree of a node is the number of edges connected to it.

Example 1:

    Input: n = 5, edges = [[1,2],[2,3],[3,4],[4,2],[1,4],[2,5]]
    Output: true
        Explanation: The above diagram shows a valid way of adding an edge.
        Every node in the resulting graph is connected to an even number of edges.

Example 2:

    Input: n = 4, edges = [[1,2],[3,4]]
    Output: true
        Explanation: The above diagram shows a valid way of adding two edges.

Example 3:

    Input: n = 4, edges = [[1,2],[1,3],[1,4]]
    Output: false
        Explanation: It is not possible to obtain a valid graph with adding at most 2 edges.

Constraints:

* 3 <= n <= 10^5
* 2 <= edges.length <= 10^5
* edges[i].length == 2
* 1 <= a_i, b_i <= n
* a_i != b_i
* There are no repeated edges.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_set>

class Solution
{
private:
    bool do_four(const vector<unordered_set<int>> &graph, const vector<int> &only_odd)
    {
        if (!graph[only_odd[0]].count(only_odd[1]) && !graph[only_odd[2]].count(only_odd[3]))
            return (true);
        else if (!graph[only_odd[0]].count(only_odd[2]) && !graph[only_odd[1]].count(only_odd[3]))
            return (true);
        else if (!graph[only_odd[0]].count(only_odd[3]) && !graph[only_odd[1]].count(only_odd[2]))
            return (true);
        return (false);
    }

    bool find_k(const vector<unordered_set<int>> &graph, const vector<int> &only_odd, int dim)
    {
        for (int i = 1; i < dim; i++)
        {
            if (i != only_odd[0] && i != only_odd[1] &&
                !graph[i].count(only_odd[0]) && !graph[i].count(only_odd[1]))
                return (true);
        }
        return (false);
    }

    bool is_valid(const vector<unordered_set<int>> &graph, const vector<int> &only_odd, const int dim)
    {
        if (only_odd.size() == 4)
            return (do_four(graph, only_odd));
        else if (only_odd.size() == 2)
        {
            if (!graph[only_odd[0]].count(only_odd[1]))
                return (true);
            else
                return (find_k(graph, only_odd, dim));
        }
        return (false);
    }

    void alloc_all(vector<unordered_set<int>> &graph, vector<int> &even_odd,
                   vector<int> &only_odd, const vector<vector<int>> &edges)
    {
        for (size_t i = 0; i < edges.size(); i++)
        {
            even_odd[edges[i][0]]++;
            even_odd[edges[i][1]]++;
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }

        for (size_t i = 0; i < even_odd.size(); i++)
        {
            if (even_odd[i] % 2 == 1)
                only_odd.push_back(static_cast<int>(i));
        }
    }

public:
    bool isPossible(int n, vector<vector<int>> &edges)
    {
        vector<unordered_set<int>> graph(n + 1);
        vector<int> even_odd(n + 1);
        vector<int> only_odd;

        only_odd.reserve(4);
        for (unordered_set<int> &node : graph)
            node.reserve(4);

        alloc_all(graph, even_odd, only_odd, edges);

        if (only_odd.size() == 0)
            return (true);
        else
            return (is_valid(graph, only_odd, n));
    }
};

void testcase(int n, vector<vector<int>> &edges)
{
    Solution s;
    bool result;

    result = s.isPossible(n, edges);
    cout << boolalpha << "result = " << result << "\n\n";
}

int main()
{
    vector<vector<int>> edges;

    /*testcase(5, edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 4}, {2, 5}});
    testcase(4, edges = {{1, 2}, {3, 4}});
    testcase(4, edges = {{1, 2}, {1, 3}, {1, 4}});
    testcase(4, edges = {{4, 1}, {3, 2}, {2, 4}, {1, 3}});
    testcase(4, edges = {{4, 1}, {3, 2}});*/
    testcase(4, edges = {{1, 2}, {2, 3}, {2, 4}, {3, 4}});
}