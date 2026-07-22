/*
You are given an integer n indicating the number of people in a network. Each person is labeled from 0 to n - 1.

You are also given a 0-indexed 2D integer array restrictions, where restrictions[i] = [x_i, y_i] means that person x_i and person y_i cannot become friends, either directly or indirectly through other people.

Initially, no one is friends with each other. You are given a list of friend requests as a 0-indexed 2D integer array requests, where requests[j] = [u_j, v_j] is a friend request between person u_j and person v_j.

A friend request is successful if u_j and v_j can be friends. Each friend request is processed in the given order (i.e., requests[j] occurs before requests[j + 1]), and upon a successful request, u_j and v_j become direct friends for all future friend requests.

Return a boolean array result, where each result[j] is true if the jth friend request is successful or false if it is not.

    Note: If u_j and v_j are already direct friends, the request is still successful.

Example 1:

    Input: n = 3, restrictions = [[0,1]], requests = [[0,2],[2,1]]
    Output: [true,false]
        Explanation:
        Request 0: Person 0 and person 2 can be friends, so they become direct friends.
        Request 1: Person 2 and person 1 cannot be friends since person 0 and person 1 would be indirect friends (1--2--0).

Example 2:

    Input: n = 3, restrictions = [[0,1]], requests = [[1,2],[0,2]]
    Output: [true,false]
        Explanation:
        Request 0: Person 1 and person 2 can be friends, so they become direct friends.
        Request 1: Person 0 and person 2 cannot be friends since person 0 and person 1 would be indirect friends (0--2--1).

Example 3:

    Input: n = 5, restrictions = [[0,1],[1,2],[2,3]], requests = [[0,4],[1,2],[3,1],[3,4]]
    Output: [true,false,true,false]
        Explanation:
        Request 0: Person 0 and person 4 can be friends, so they become direct friends.
        Request 1: Person 1 and person 2 cannot be friends since they are directly restricted.
        Request 2: Person 3 and person 1 can be friends, so they become direct friends.
        Request 3: Person 3 and person 4 cannot be friends since person 0 and person 1 would be indirect friends (0--4--3--1).


Constraints:

* 2 <= n <= 1000
* 0 <= restrictions.length <= 1000
* restrictions[i].length == 2
* 0 <= x_i, y_i <= n - 1
* x_i != y_i
* 1 <= requests.length <= 1000
* requests[j].length == 2
* 0 <= u_j, v_j <= n - 1
* u_j != v_j
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    int find_root(vector<int> &union_find, int index)
    {
        if (union_find[index] != index)
            union_find[index] = find_root(union_find, union_find[index]);
        return (union_find[index]);
    }

public:
    vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
    {
        vector<int> union_find(n);
        vector<bool> result(n - 1);
        int friend_x = 0;
        int friend_y = 0;
        int restrict_x = 0;
        int restrict_y = 0;
        bool state = true;

        for (int i = 0; i < n; i++)
            union_find[i] = i;

        for (size_t i = 0; i < requests.size(); i++)
        {
            state = true;
            friend_x = find_root(union_find, requests[i][0]);
            friend_y = find_root(union_find, requests[i][1]);
            for (size_t j = 0; j < restrictions.size(); j++)
            {
                restrict_x = find_root(union_find, restrictions[j][0]);
                restrict_y = find_root(union_find, restrictions[j][1]);
                if ((restrict_x == friend_x || restrict_x == friend_y) &&
                    (restrict_y == friend_x || restrict_y == friend_y))
                {
                    state = false;
                    break;
                }
            }
            if (state)
            {
                if (friend_x > friend_y)
                    union_find[friend_y] = friend_x;
                else
                    union_find[friend_x] = friend_y;
            }
            result[i] = state;
        }
        return (result);
    }
};

void testacase(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
{
    Solution s;
    vector<bool> result;

    result = s.friendRequests(n, restrictions, requests);

    cout << "result ={";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << boolalpha << result[i];
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "}\n\n";
}

int main()
{
    vector<vector<int>> restrictions;
    vector<vector<int>> requests;

    testacase(3, restrictions = {{0, 1}}, requests = {{0, 2}, {2, 1}});
    testacase(3, restrictions = {{0, 1}}, requests = {{1, 2}, {0, 1}});
    testacase(5, restrictions = {{0, 1}, {1, 2}, {2, 3}}, requests = {{0, 4}, {1, 2}, {3, 1}, {3, 4}});
}
