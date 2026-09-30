/*
A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.

The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.

The mouse starts at node 1 and goes first, the cat starts at node 2 and goes second, and there is a hole at node 0.

During each player's turn, they must travel along one edge of the graph that meets where they are.  For example, if the Mouse is at node 1, it must travel to any node in graph[1].

Additionally, it is not allowed for the Cat to travel to the Hole (node 0).

Then, the game can end in three ways:

* If ever the Cat occupies the same node as the Mouse, the Cat wins.
* If ever the Mouse reaches the Hole, the Mouse wins.
* If ever a position is repeated (i.e., the players are in the same position as a previous turn, and it is the same player's turn to move), the game is a draw.
Given a graph, and assuming both players play optimally, return

* 1 if the mouse wins the game,
* 2 if the cat wins the game, or
* 0 if the game is a draw.

Example 1:

    Input: graph = [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
    Output: 0

Example 2:

    Input: graph = [[1,3],[0],[3],[0,2]]
    Output: 1

Constraints:

* 3 <= graph.length <= 50
* 1 <= graph[i].length < graph.length
* 0 <= graph[i][j] < graph.length
* graph[i][j] != i
* graph[i] is unique.
* The mouse and the cat can always move.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

enum role
{
    Cat = 0,
    Mouse = 1
};

class Solution
{
private:
    vector<vector<vector<bool>>> seen;
    vector<vector<vector<int>>> memo;

    int help_choose(int lose, int win, int state, int condition)
    {
        if (condition == -1 || condition == lose)
        {
            if (state == win)
                condition = win;
            else if (state == 0)
                condition = 0;
            else
                condition = lose;
        }
        return (condition);
    }

    int cat_vs_mouse(int c, int m, role type, const vector<vector<int>> &graph, int i)
    {
        bool draw = true;
        int condition = -1;

        if (type == Mouse && find(graph[m].begin(), graph[m].end(), 0) != graph[m].end())
            return (1);

        for (const int &path : graph[i])
        {
            if (type == Cat)
            {
                if (path == 0 || seen[path][m][Mouse] == true)
                {
                    if (seen[path][m][Mouse] == true)
                        condition = 0;
                    continue;
                }
                draw = false;
                condition = help_choose(1, 2, win_lose_draw(path, m, graph, Mouse), condition);
            }
            else if (seen[c][path][Cat] == false)
            {
                draw = false;
                condition = help_choose(2, 1, win_lose_draw(c, path, graph, Cat), condition);
            }
            else
                condition = 0;
        }
        if (draw)
            return (0);
        return (condition);
    }

    int win_lose_draw(size_t c, size_t m, const vector<vector<int>> &graph, role type)
    {
        int condition;

        if (memo[c][m][type] != -1)
            return (memo[c][m][type]);

        if (c == m)
            return (2);

        seen[c][m][type] = true;

        if (type == Cat)
            condition = cat_vs_mouse(c, m, type, graph, c);
        else
            condition = cat_vs_mouse(c, m, type, graph, m);

        memo[c][m][type] = condition;
        return (condition);
    }

public:
    int catMouseGame(vector<vector<int>> &graph)
    {
        seen.clear();
        seen.resize(graph.size(), vector<vector<bool>>(graph.size(), vector<bool>(2, false)));
        memo.clear();
        memo.resize(graph.size(), vector<vector<int>>(graph.size(), vector<int>(2, -1)));
        return (win_lose_draw(2, 1, graph, Mouse));
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph;
    int result;

    graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{1, 3}, {0}, {3}, {0, 2}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{2}, {2, 3}, {0, 1}, {1}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{3}, {3}, {3}, {0, 1, 2}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{3}, {3}, {4}, {0, 1, 4}, {2, 3}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{3}, {3, 4}, {4}, {0, 1}, {1, 2}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{2, 3}, {3}, {0, 3}, {0, 1, 2}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{1, 3}, {0}, {3}, {0, 2}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{3}, {3}, {3}, {0, 1, 2}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{2, 3}, {2, 4}, {0, 1, 4}, {0, 4}, {1, 2, 3}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{2, 4}, {2, 3}, {0, 1, 4}, {1, 4}, {0, 2, 3}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{2, 3, 5}, {3, 4}, {0, 4, 5}, {0, 1, 4, 5}, {1, 2, 3, 5}, {0, 2, 3, 4}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{2, 3}, {3, 4}, {0, 4}, {0, 1, 4}, {1, 2, 3}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;

    cout << "deve essere 2\n\n";
    graph = {{4}, {2, 3, 5}, {1, 5, 3}, {1, 2}, {0}, {1, 2}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;
}