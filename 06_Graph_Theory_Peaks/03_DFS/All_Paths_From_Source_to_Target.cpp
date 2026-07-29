/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

Example 1:

    Input: graph = [[1,2],[3],[3],[]]
    Output: [[0,1,3],[0,2,3]]
    Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

Example 2:

    Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
    Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]


Constraints:

* n == graph.length
* 2 <= n <= 15
* 0 <= graph[i][j] < n
* graph[i][j] != i (i.e., there will be no self-loops).
* All the elements of graph[i] are unique.
* The input graph is guaranteed to be a DAG.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    vector<vector<int>> graph;
    size_t target;

    void take_paths(vector<vector<int>> &result, vector<int> &path, size_t i = 0)
    {
        if (target == i)
        {
            result.push_back(path);
            result.back().push_back(i);
        }
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            path.push_back(i);
            take_paths(result, path, graph[i][j]);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        this->graph.clear();
        this->target = graph.size() - 1;
        vector<vector<int>> result;
        vector<int> path;
        this->graph = graph;

        take_paths(result, path);

        return (result);
    }
};

void print_result(const vector<vector<int>> &result)
{
    cout << "result = {";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << "{";
        for (size_t j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if (j + 1 < result[i].size())
                cout << ",";
        }
        cout << "}";
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "};\n\n";
}

int main()
{
    Solution s;
    vector<vector<int>> graph;
    vector<vector<int>> result;

    graph = {{1, 2}, {3}, {3}, {}};
    result = s.allPathsSourceTarget(graph);
    print_result(result);

    graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    result = s.allPathsSourceTarget(graph);
    print_result(result);

    graph = {{4, 3, 1}, {3, 2, 4}, {}, {4}, {}};
    result = s.allPathsSourceTarget(graph);
    print_result(result);

    graph = {{2}, {}, {1}};
    result = s.allPathsSourceTarget(graph);
    print_result(result);
}