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

enum role
{
    Cat = 0,
    Mouse = 1
};

class Solution
{
private:
    vector<vector<vector<int>>> possible;
    queue<tuple<int, int, role>> q;

    void set_cat_mouse(vector<vector<int>> &graph)
    {
        for (size_t i = 1; i < graph.size(); i++)
        {
            possible[i][i][Cat] = 2;
            possible[i][i][Mouse] = 2;

            q.push({i, i, Cat});
            q.push({i, i, Mouse});
        }

        for (size_t i = 1; i < graph.size(); i++)
        {
            possible[0][i][Cat] = 1;
            possible[0][i][Mouse] = 1;

            q.push({0, i, Cat});
            q.push({0, i, Mouse});
        }
    }

public:
    int catMouseGame(vector<vector<int>> &graph)
    {
        role type;
        int m;
        int c;

        possible.clear();
        possible.resize(graph.size(), vector<vector<int>>(graph.size(), vector<int>(2, 0)));

        set_cat_mouse(graph);

        while (!q.empty())
        {
            tuple<int, int, role> state = q.front();
            q.pop();

            type = get<2>(state);
            m = get<0>(state);
            c = get<1>(state);

            if (type == Cat)
            {
                for (int path : graph[m])
                {
                }
            }
            else
            {
                for (int path : graph[c])
                {
                }
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> graph;
    int result;

    /*  graph = {{2, 5}, {3}, {0, 4, 5}, {1, 4, 5}, {2, 3}, {0, 2, 3}};
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

     graph = {{4}, {2, 3, 5}, {1, 5, 3}, {1, 2}, {0}, {1, 2}};
     result = s.catMouseGame(graph);
     cout << "result = " << result << endl;

     graph = {{2, 6}, {2, 4, 5, 6}, {0, 1, 3, 5, 6}, {2}, {1, 5, 6}, {1, 2, 4}, {0, 1, 2, 4}};
     result = s.catMouseGame(graph);
     cout << "result = " << result << endl;

     graph = {{2, 3}, {3, 4}, {0, 4}, {0, 1}, {1, 2}};
     result = s.catMouseGame(graph);
     cout << "result = " << result << endl;*/

    graph = {{5, 6}, {3, 4}, {6}, {1, 4, 5}, {1, 3, 5}, {0, 3, 4, 6}, {0, 2, 5}};
    result = s.catMouseGame(graph);
    cout << "result = " << result << endl;
}