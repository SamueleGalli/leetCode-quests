/*
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

Example 1:

    Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
    Output: 2
        Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

Example 2:

    Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
    Output: -1

Constraints:

* 1 <= routes.length <= 500.
* 1 <= routes[i].length <= 105
* All the values of routes[i] are unique.
* sum(routes[i].length) <= 105
* 0 <= routes[i][j] < 106
* 0 <= source, target < 106
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

class Solution
{
private:
    unordered_map<int, vector<size_t>> graph;
    queue<size_t> bus_queue;
    vector<char> visited;

    bool helper_route(vector<vector<int>> &routes, const int &target)
    {
        for (const int &stop : routes[bus_queue.front()])
        {
            if (target == stop)
                return (true);
            const vector<size_t> &autobus = graph[stop];
            if (autobus.size() > 1)
            {
                for (const size_t &value : autobus)
                    if (visited[value] == 0)
                    {
                        visited[value] = 1;
                        bus_queue.push(value);
                    }
            }
        }
        return (false);
    }

    int BFS_bus(vector<vector<int>> &routes, const int &target, int level = 1)
    {
        size_t bus_size = bus_queue.size();
        for (size_t i = 0; i < bus_size; i++)
        {
            if (helper_route(routes, target))
                return (level);
            bus_queue.pop();
        }
        if (!bus_queue.empty())
            level = BFS_bus(routes, target, level + 1);
        else
            level = -1;
        return (level);
    }

    void set_variable(const vector<vector<int>> &routes, const int &source)
    {
        while (!bus_queue.empty())
            bus_queue.pop();
        graph.clear();
        visited.clear();

        for (size_t i = 0; i < routes.size(); i++)
        {
            for (const int &stop : routes[i])
                graph[stop].push_back(i);
        }
        visited.resize(routes.size(), 0);
        for (const size_t &index : graph[source])
            bus_queue.push(index);
    }

public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return (0);
        set_variable(routes, source);
        return (BFS_bus(routes, target));
    }
};

void testcase(vector<vector<int>> &routes, int source, int target)
{
    Solution s;
    int result;

    result = s.numBusesToDestination(routes, source, target);
    cout << "result = " << result << endl;
}

int main()
{
    vector<vector<int>> routes;

    testcase(routes = {{1, 2, 7}, {3, 6, 7}}, 1, 6);
    testcase(routes = {{7, 12}, {4, 5, 15}, {6}, {15, 19}, {9, 12, 13}}, 15, 12);
    testcase(routes = {{1, 7}, {3, 5}}, 5, 5);
    testcase(routes = {{2}, {2, 8}}, 8, 2);
}