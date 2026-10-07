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
#include <queue>
#include <algorithm>

enum role
{
    Cat = 0,
    Mouse = 1
};

struct pet
{
    int m;
    int c;
    role type;

    pet(int m, int c, role type) : m(m), c(c), type(type)
    {
    }
};

class Solution
{
private:
    vector<vector<vector<int>>> possible;
    vector<vector<vector<size_t>>> lose;
    queue<pet> q;

    void set_game(vector<vector<int>> &graph)
    {
        possible.assign(graph.size(), vector<vector<int>>(graph.size(), vector<int>(2, 0)));
        lose.assign(graph.size(), vector<vector<size_t>>(graph.size(), vector<size_t>(2, 0)));

        for (size_t i = 0; i < graph.size(); i++)
        {
            for (size_t j = 0; j < graph.size(); j++)
            {
                lose[i][j][Mouse] = graph[i].size();
                lose[i][j][Cat] = graph[j].size();
                if (find(graph[j].begin(), graph[j].end(), 0) != graph[j].end())
                    lose[i][j][Cat]--;
            }
        }

        for (size_t i = 1; i < graph.size(); i++)
        {
            possible[i][i][Mouse] = 2;
            possible[i][i][Cat] = 2;
            possible[0][i][Mouse] = 1;
            possible[0][i][Cat] = 1;

            q.push(pet(i, i, Mouse));
            q.push(pet(i, i, Cat));
            q.push(pet(0, i, Mouse));
            q.push(pet(0, i, Cat));
        }
    }

    void set_win_lose(int m, int c, role other, int win, int lost)
    {
        if (other == Cat)
            possible[m][c][other] = win;
        else
            possible[m][c][other] = lost;

        q.push({m, c, other});
    }

    void cat_mouse(int m, int c, role other, int origin)
    {
        bool win = false;
        if (possible[m][c][other] != 0)
            return;

        int end_state = (other == Mouse ? 1 : 2);
        if (origin == end_state)
            win = true;
        else if (origin != 0)
            lose[m][c][other]--;

        if (win)
            set_win_lose(m, c, other, 2, 1);
        else if (lose[m][c][other] == 0)
            set_win_lose(m, c, other, 1, 2);
    }

public:
    int catMouseGame(vector<vector<int>> &graph)
    {
        set_game(graph);
        while (!q.empty())
        {
            pet curr = q.front();
            role other = (curr.type == Cat ? Mouse : Cat);
            int origin = possible[curr.m][curr.c][curr.type];

            q.pop();

            if (curr.type == Cat)
            {
                for (int path : graph[curr.m])
                    cat_mouse(path, curr.c, other, origin);
            }
            else
            {
                for (int path : graph[curr.c])
                {
                    if (path != 0)
                        cat_mouse(curr.m, path, other, origin);
                }
            }
        }
        return (possible[1][2][Mouse]);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph;
    int result;

    graph = {{2}, {2}, {0, 1}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << "\n\n\n";

    graph = {{1}, {0, 2}, {1}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << "\n\n\n";

    graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << "\n\n\n";

    graph = {{3}, {3}, {3}, {0, 1, 2}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << "\n\n\n";

    graph = {{3}, {3, 4}, {4}, {0, 1}, {1, 2}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << "\n\n\n";
}