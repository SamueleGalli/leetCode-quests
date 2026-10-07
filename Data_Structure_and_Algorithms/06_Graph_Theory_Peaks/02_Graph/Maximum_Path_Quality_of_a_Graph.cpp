/*
There is an undirected graph with n nodes numbered from 0 to n - 1 (inclusive). You are given a 0-indexed integer array values where values[i] is the value of the ith node. You are also given a 0-indexed 2D integer array edges, where each edges[j] = [uj, vj, timej] indicates that there is an undirected edge between the nodes uj and vj, and it takes timej seconds to travel between the two nodes. Finally, you are given an integer maxTime.

A valid path in the graph is any path that starts at node 0, ends at node 0, and takes at most maxTime seconds to complete. You may visit the same node multiple times. The quality of a valid path is the sum of the values of the unique nodes visited in the path (each node's value is added at most once to the sum).

Return the maximum quality of a valid path.

Note: There are at most four edges connected to each node.

Example 1:

    Input: values = [0,32,10,43], edges = [[0,1,10],[1,2,15],[0,3,10]], maxTime = 49
    Output: 75
        Explanation:
        One possible path is 0 -> 1 -> 0 -> 3 -> 0. The total time taken is 10 + 10 + 10 + 10 = 40 <= 49.
        The nodes visited are 0, 1, and 3, giving a maximal path quality of 0 + 32 + 43 = 75.

Example 2:

    Input: values = [5,10,15,20], edges = [[0,1,10],[1,2,10],[0,3,10]], maxTime = 30
    Output: 25
        Explanation:
        One possible path is 0 -> 3 -> 0. The total time taken is 10 + 10 = 20 <= 30.
        The nodes visited are 0 and 3, giving a maximal path quality of 5 + 20 = 25.

Example 3:

    Input: values = [1,2,3,4], edges = [[0,1,10],[1,2,11],[2,3,12],[1,3,13]], maxTime = 50
    Output: 7
        Explanation:
        One possible path is 0 -> 1 -> 3 -> 1 -> 0. The total time taken is 10 + 13 + 13 + 10 = 46 <= 50.
        The nodes visited are 0, 1, and 3, giving a maximal path quality of 1 + 2 + 4 = 7.

Constraints:

* n == values.length
* 1 <= n <= 1000
* 0 <= values[i] <= 108
* 0 <= edges.length <= 2000
* edges[j].length == 3
* 0 <= uj < vj <= n - 1
* 10 <= timej, maxTime <= 100
* All the pairs [uj, vj] are unique.
* There are at most four edges connected to each node.
* The graph may not be connected.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

class Solution
{

private:
    unordered_map<int, vector<pair<int, int>>> graph;
    vector<int> path_time;
    int tot_sum = 0;
    int max_time = 0;
    void take_paths(vector<int> &values, int time = 0, int sum = 0, int i = 0)
    {
        if (time + path_time[i] > max_time)
            return;
        if (i == 0)
            tot_sum = max(tot_sum, sum + values[i]);
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            pair<int, int> node_time = graph[i][j];
            if (time + node_time.first > max_time)
                continue;
            int curr_sum = values[i];
            values[i] = 0;
            take_paths(values, time + node_time.first, sum + curr_sum, node_time.second);
            values[i] = curr_sum;
        }
    }

    void set_value(vector<vector<int>> &edges, const size_t &dim)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> list;
        int time;
        pair<int, int> node;

        path_time.resize(dim, 101);
        list.push({0, 0});
        path_time[0] = 0;

        for (size_t i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][2], edges[i][1]});
            graph[edges[i][1]].push_back({edges[i][2], edges[i][0]});
        }
        while (!list.empty())
        {
            node = list.top();
            list.pop();
            for (pair<const int, int> to_push : graph[node.second])
            {
                time = path_time[node.second] + to_push.first;
                if (time < path_time[to_push.second])
                {
                    path_time[to_push.second] = time;
                    list.push(to_push);
                }
            }
        }
    }

public:
    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime)
    {
        graph.clear();
        path_time.clear();
        tot_sum = 0;
        max_time = maxTime;

        set_value(edges, values.size());

        take_paths(values);
        return (tot_sum);
    }
};

void testcase(vector<int> &values, vector<vector<int>> &edges, int maxTime)
{
    Solution s;
    int result;
    result = s.maximalPathQuality(values, edges, maxTime);
    cout << "result = " << result << endl;
}

int main()
{
    vector<int> values;
    vector<vector<int>> edges;

    testcase(values = {0, 32, 10, 43}, edges = {{0, 1, 10}, {1, 2, 15}, {0, 3, 10}}, 49);
    testcase(values = {5, 10, 15, 20}, edges = {{0, 1, 10}, {1, 2, 10}, {0, 3, 10}}, 30);
    testcase(values = {1, 2, 3, 4}, edges = {{0, 1, 10}, {1, 2, 11}, {2, 3, 12}, {1, 3, 13}}, 50);
    testcase(values = {39, 73, 63, 17}, edges = {{0, 1, 61}, {1, 2, 13}, {2, 3, 44}, {0, 3, 11}}, 10);
}
