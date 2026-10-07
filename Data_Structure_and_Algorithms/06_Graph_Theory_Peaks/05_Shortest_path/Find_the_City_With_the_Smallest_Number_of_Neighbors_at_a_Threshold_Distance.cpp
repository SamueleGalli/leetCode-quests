/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [from_i, to_i, weighti] represents a bidirectional and weighted edge between cities from_i and to_i, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Example 1:

    Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
    Output: 3
        Explanation: The figure above describes the graph.
        The neighboring cities at a distanceThreshold = 4 for each city are:
        City 0 -> [City 1, City 2]
        City 1 -> [City 0, City 2, City 3]
        City 2 -> [City 0, City 1, City 3]
        City 3 -> [City 1, City 2]
        Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

Example 2:

    Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
    Output: 0
        Explanation: The figure above describes the graph.
        The neighboring cities at a distanceThreshold = 2 for each city are:
        City 0 -> [City 1]
        City 1 -> [City 0, City 4]
        City 2 -> [City 3, City 4]
        City 3 -> [City 2, City 4]
        City 4 -> [City 1, City 2, City 3]
        The city 0 has 1 neighboring city at a distanceThreshold = 2.

Constraints:

* 2 <= n <= 100
* 1 <= edges.length <= n * (n - 1) / 2
* edges[i].length == 3
* 0 <= from_i < to_i < n
* 1 <= weighti, distanceThreshold <= 10^4
* All pairs (from_i, to_i) are distinct.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

class Solution
{
private:
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> list_node;
    vector<vector<pair<int, int>>> graph;
    vector<int> dimension;
    int max_int = numeric_limits<int>::max();

    int short_path(const int &distanceThreshold)
    {
        while (!list_node.empty())
        {
            const pair<int, int> top_node = list_node.top();
            list_node.pop();
            if (top_node.first > distanceThreshold)
                continue;
            for (const pair<int, int> &current : graph[top_node.second])
            {
                int sum = current.first + top_node.first;
                if (sum <= distanceThreshold && sum <= dimension[current.second])
                {
                    dimension[current.second] = sum;
                    list_node.push({sum, current.second});
                }
            }
        }

        int min_city = 0;
        for (size_t i = 0; i < dimension.size(); i++)
        {
            if (dimension[i] != max_int)
                min_city++;
        }
        return (min_city);
    }

    void set_up_all(const vector<vector<int>> &edges, const int &n)
    {
        graph.clear();
        dimension.resize(n, max_int);
        graph.resize(n);
        while (!list_node.empty())
            list_node.pop();

        for (size_t i = 0; i < edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][2], edges[i][1]});
            graph[edges[i][1]].push_back({edges[i][2], edges[i][0]});
        }
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        int result = max_int;
        int max_index = 0;
        vector<int> city_distance(n);

        set_up_all(edges, n);

        for (int i = 0; i < n; i++)
        {
            list_node.push({0, i});
            dimension[i] = 0;
            city_distance[i] = short_path(distanceThreshold);
            fill(dimension.begin(), dimension.end(), max_int);
        }
        for (size_t i = 0; i < city_distance.size(); i++)
        {
            if (city_distance[i] <= result)
            {
                result = city_distance[i];
                max_index = i;
            }
        }
        return (max_index);
    }
};

void testacase(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    Solution s;
    int result;

    result = s.findTheCity(n, edges, distanceThreshold);
    cout << "result = " << result << endl;
}

int main()
{
    vector<vector<int>> edges;

    testacase(4, edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}}, 4);
    testacase(5, edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}}, 4);
}