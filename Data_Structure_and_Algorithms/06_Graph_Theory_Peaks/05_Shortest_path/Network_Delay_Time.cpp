/*

You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (u_i, v_i, wi), where u_i is the source node, v_i is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:

    Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
    Output: 2

Example 2:

    Input: times = [[1,2,1]], n = 2, k = 1
    Output: 1

Example 3:

    Input: times = [[1,2,1]], n = 2, k = 2
    Output: -1

Constraints:

* 1 <= k <= n <= 100
* 1 <= times.length <= 6000
* times[i].length == 3
* 1 <= u_i, v_i <= n
* u_i != v_i
* 0 <= wi <= 100
* All the pairs (u_i, v_i) are unique. (i.e., no multiple edges.)
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>

class Solution
{
private:
    int max_int = numeric_limits<int>::max();
    unordered_map<int, vector<pair<int, int>>> graph;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> node_to_see;
    vector<int> dimension;

    void short_time(void)
    {
        while (!node_to_see.empty())
        {
            const pair<int, int> current = node_to_see.top();
            node_to_see.pop();
            for (const pair<int, int> &node : graph[current.second])
            {
                int sum = node.first + current.first;
                if (sum < dimension[node.second])
                {
                    dimension[node.second] = sum;
                    cout << "tempo minore = " << sum << endl;
                    node_to_see.push({sum, node.second});
                }
            }
        }
    }

    void setup_variable(vector<vector<int>> &times, int n, int k)
    {
        graph.clear();
        dimension.clear();

        for (const vector<int> &node : times)
            graph[node[0]].push_back({node[2], node[1]});
        dimension.resize(n + 1, max_int);
        dimension[k] = 0;
        node_to_see.push({0, k});
    }

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        int result = 0;
        setup_variable(times, n, k);
        short_time();

        for (size_t i = 1; i < dimension.size(); i++)
        {
            if (dimension[i] == max_int)
                return (-1);
            result = max(result, dimension[i]);
        }

        return (result);
    }
};

void testcase(vector<vector<int>> &times, int n, int k)
{
    Solution s;
    int result;

    result = s.networkDelayTime(times, n, k);
    cout << "result = " << result << endl;
}

int main()
{
    vector<vector<int>> times;

    testcase(times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}}, 4, 2);
    testcase(times = {{1, 2, 1}}, 2, 1);
    testcase(times = {{1, 2, 1}}, 2, 2);
}