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
#include <unordered_map>
#include <unordered_set>
#include <iterator>

// TODO caso grande da un risultato errato solo 2  archi da sistemare controlalre anche 4

class Solution
{
private:
    bool find_next_valid(vector<int> &even_odd,
                         unordered_map<int, unordered_set<int>> &graph, size_t &i, int odd = 1)
    {
        unordered_map<int, unordered_set<int>>::iterator exist;
        for (size_t j = 0; j < even_odd.size(); j++)
        {
            cout << "provo " << j << endl;
            if (even_odd[j] % 2 == 1 && j != i)
            {
                cout << j << " e valido esiste gia?\n";
                exist = graph.find(i);
                cout << (exist != graph.end() ? "giusto" : "sbagliato") << endl;
                if (exist != graph.end() && !exist->second.count(j))
                {
                    cout << (!exist->second.count(j) ? "giusto" : "sbagliato") << endl;
                    graph[static_cast<int>(i)].insert(static_cast<int>(j));
                    graph[j].insert(static_cast<int>(i));
                    even_odd[i]++;
                    even_odd[j]++;
                    odd--;
                    break;
                }
            }
        }
        if (odd > 0)
            return (false);
        return (true);
    }
    bool is_valid(vector<int> &even_odd,
                  unordered_map<int, unordered_set<int>> &graph, int odd)
    {
        for (size_t i = 0; i < even_odd.size(); i++)
        {
            if (even_odd[i] % 2 == 1)
            {
                cout << "provo a cercare una coppia per " << i << endl;
                if (find_next_valid(even_odd, graph, i) == false)
                    return (false);
            }
        }
        return (true);
    }

    int is_invalid(vector<int> &even_odd, int odd = 0)
    {
        for (size_t i = 0; i < even_odd.size(); i++)
        {
            if (even_odd[i] % 2 == 1)
                odd++;
        }
        cout << "quanti sono odd?\n";
        cout << odd << endl;
        if (odd > 4 || odd == 0)
            return (odd);
        else
            return (-1);
    }

public:
    bool isPossible(int n, vector<vector<int>> &edges)
    {
        unordered_map<int, unordered_set<int>> graph;
        vector<int> even_odd(n + 1);
        int odd = 0;

        graph.reserve(n);
        for (size_t i = 0; i < edges.size(); i++)
        {
            even_odd[edges[i][0]]++;
            even_odd[edges[i][1]]++;
            graph[edges[i][0]].insert(edges[i][1]);
            graph[edges[i][1]].insert(edges[i][0]);
        }
        odd = is_invalid(even_odd);
        switch (odd)
        {
        case 0:
            return (true);
            break;

        case -1:
            return (is_valid(even_odd, graph, odd));
            break;

        default:
            return (false);
            break;
        }
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

    /*    testcase(5, edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}, {1, 4}, {2, 5}});
       testcase(4, edges = {{1, 2}, {3, 4}});
       testcase(4, edges = {{1, 2}, {1, 3}, {1, 4}});
       testcase(4, edges = {{4, 1}, {3, 2}, {2, 4}, {1, 3}});
       testcase(4, edges = {{4, 1}, {3, 2}}); */
    testcase(21, edges = {{2, 19}, {16, 17}, {8, 14}, {2, 16}, {12, 20}, {12, 14}, {16, 18}, {15, 16}, {10, 21}, {3, 5}, {13, 18}, {17, 20}, {14, 17}, {9, 12}, {5, 15}, {5, 6}, {3, 7}, {2, 21}, {10, 13}, {8, 16}, {7, 18}, {4, 6}, {9, 1}, {13, 21}, {18, 20}, {7, 14}, {4, 19}, {5, 8}, {3, 11}, {11, 1}, {7, 12}, {4, 7}, {3, 16}, {13, 17}, {17, 19}, {9, 13}, {7, 19}, {10, 16}, {4, 13}, {4, 5}, {2, 15}, {12, 19}, {11, 16}, {2, 9}, {11, 17}, {17, 1}, {16, 21}, {4, 10}, {10, 14}, {14, 16}, {4, 1}, {13, 20}, {5, 20}, {4, 14}, {4, 21}, {10, 20}, {2, 14}, {8, 15}, {4, 8}, {6, 19}, {15, 1}, {19, 1}, {8, 19}, {15, 21}, {3, 12}, {11, 18}, {9, 17}, {18, 19}, {7, 21}, {3, 21}, {16, 19}, {11, 15}, {5, 1}, {8, 17}, {3, 15}, {8, 1}, {10, 19}, {3, 8}, {6, 16}, {2, 8}, {5, 18}, {11, 13}, {11, 20}, {14, 21}, {6, 20}, {4, 20}, {12, 13}, {5, 12}, {10, 11}, {9, 15}, {3, 19}, {9, 20}, {14, 18}, {21, 1}, {13, 19}, {8, 21}, {2, 13}, {3, 10}, {9, 18}, {19, 21}, {6, 7}, {3, 18}, {2, 18}, {6, 14}, {3, 17}, {5, 21}, {14, 20}, {8, 9}, {16, 1}, {3, 4}, {13, 1}, {5, 9}, {4, 15}, {17, 21}, {20, 21}, {2, 17}, {13, 14}, {11, 14}, {9, 16}, {10, 18}, {6, 15}, {6, 12}, {3, 13}, {5, 11}, {6, 1}, {12, 17}, {8, 10}, {5, 10}, {8, 18}, {4, 12}, {10, 1}, {6, 13}, {4, 18}, {7, 20}, {7, 16}, {2, 6}, {12, 21}, {4, 17}, {15, 18}, {13, 16}, {15, 20}, {7, 10}, {6, 10}, {2, 20}, {7, 15}, {18, 1}, {12, 1}, {3, 20}, {7, 1}, {14, 15}, {4, 9}, {11, 19}, {7, 9}, {5, 17}, {18, 21}, {6, 21}, {8, 11}, {6, 17}, {3, 14}, {7, 11}, {5, 7}, {7, 13}, {6, 8}, {6, 9}, {10, 12}, {5, 16}, {2, 4}, {17, 18}, {9, 11}, {12, 16}, {3, 6}, {12, 18}, {3, 9}, {11, 12}, {14, 19}, {10, 15}, {5, 13}, {8, 13}, {15, 17}, {2, 10}, {11, 21}, {20, 1}, {6, 18}, {2, 12}, {19, 20}, {6, 11}, {8, 12}, {2, 3}, {12, 15}, {2, 11}, {9, 10}, {7, 17}, {9, 19}, {13, 15}, {7, 8}, {4, 11}, {2, 5}, {5, 19}, {16, 20}, {15, 19}, {9, 14}, {14, 1}, {10, 17}, {9, 21}, {2, 7}, {8, 20}, {5, 14}, {4, 16}});
}