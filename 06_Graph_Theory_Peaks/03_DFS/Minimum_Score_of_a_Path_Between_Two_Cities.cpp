/*
You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [a_i, b_i, distance_i] indicates that there is a bidirectional road between cities a_i and b_i with a distance equal to distance_i. The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

    A path is a sequence of roads between two cities.
    It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
    The test cases are generated such that there is at least one path between 1 and n.

Example 1:
    Input: n = 4, roads = [[1,2,9],[2,3,6],[2,4,5],[1,4,7]]
    Output: 5
        Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 4. The score of this path is min(9,5) = 5.
        It can be shown that no other path has less score.

Example 2:

    Input: n = 4, roads = [[1,2,2],[1,3,4],[3,4,7]]
    Output: 2
        Explanation: The path from city 1 to 4 with the minimum score is: 1 -> 2 -> 1 -> 3 -> 4. The score of this path is min(2,2,4,7) = 2.

Constraints:

* 2 <= n <= 10^5
* 1 <= roads.length <= 10^5
* roads[i].length == 3
* 1 <= a_i, b_i <= n
* a_i != b_i
* 1 <= distance_i <= 10^4
* There are no repeated edges.
* There is at least one path between 1 and n.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <limits>

class Solution
{
private:
    vector<vector<pair<int, int>>> graph;
    int n;
    void set_graph(const vector<vector<int>> &roads, int n)
    {
        this->n = n;
        this->graph.clear();
        graph.resize(n + 1);
        for (size_t i = 0; i < roads.size(); i++)
        {
            graph[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            graph[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
    }

    void min_path_score(int &result, vector<char> &seen, int i = 1)
    {
        if (seen[i] == 1)
            return;

        seen[i] = 1;
        for (size_t j = 0; j < graph[i].size(); j++)
        {
            result = min(result, graph[i][j].second);
            min_path_score(result, seen, graph[i][j].first);
        }
    }

public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        int result = numeric_limits<int>::max();
        vector<char> seen(n + 1, 0);
        set_graph(roads, n);
        min_path_score(result, seen);

        return (result);
    }
};

void testcase(int n, vector<vector<int>> &roads)
{
    Solution s;
    int result;

    result = s.minScore(n, roads);
    cout << "result = " << result << endl;
}

int main()
{
    vector<vector<int>> roads;

    testcase(4, roads = {{1, 2, 9}, {2, 3, 6}, {2, 4, 5}, {1, 4, 7}});
    testcase(4, roads = {{1, 2, 2}, {1, 3, 4}, {3, 4, 7}});
}