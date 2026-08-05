/*
There are n people, each person has a unique id between 0 and n-1. Given the arrays watchedVideos and friends, where watchedVideos[i] and friends[i] contain the list of watched videos and the list of friends respectively for the person with id = i.

Level 1 of videos are all watched videos by your friends, level 2 of videos are all watched videos by the friends of your friends and so on. In general, the level k of videos are all watched videos by people with the shortest path exactly equal to k with you. Given your id and the level of videos, return the list of videos ordered by their frequencies (increasing). For videos with the same frequency order them alphabetically from least to greatest.

Example 1:

    Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 1
    Output: ["B","C"]
    Explanation:
        You have id = 0 (green color in the figure) and your friends are (yellow color in the figure):
        Person with id = 1 -> watchedVideos = ["C"]
        Person with id = 2 -> watchedVideos = ["B","C"]
        The frequencies of watchedVideos by your friends are:
        B -> 1
        C -> 2

Example 2:

    Input: watchedVideos = [["A","B"],["C"],["B","C"],["D"]], friends = [[1,2],[0,3],[0,3],[1,2]], id = 0, level = 2
    Output: ["D"]
        Explanation:
        You have id = 0 (green color in the figure) and the only friend of your friends is the person with id = 3 (yellow color in the figure).


Constraints:

* n == watchedVideos.length == friends.length
* 2 <= n <= 100
* 1 <= watchedVideos[i].length <= 100
* 1 <= watchedVideos[i][j].length <= 8
* 0 <= friends[i].length < n
* 0 <= friends[i][j] < n
* 0 <= id < n
* 1 <= level < n
* if friends[i] contains j, then friends[j] contains i
*/

using namespace std;

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

class Solution
{
private:
    vector<int> visited;
    queue<int> go_to;

    void explore_nodes(const vector<vector<int>> &friends)
    {
        size_t size_queue = go_to.size();
        for (size_t to_pop = 0; to_pop < size_queue; to_pop++)
        {
            int i = go_to.front();
            for (size_t j = 0; j < friends[i].size(); j++)
            {
                if (visited[friends[i][j]] == 0)
                {
                    go_to.push(friends[i][j]);
                    visited[friends[i][j]] = 1;
                }
            }
            go_to.pop();
        }
    }

    vector<int> distance_friends(int &id, const int level, const vector<vector<int>> &friends)
    {
        if (id == level)
        {
            vector<int> friend_found;
            while (!go_to.empty())
            {
                friend_found.push_back(go_to.front());
                go_to.pop();
            }
            return (friend_found);
        }
        explore_nodes(friends);
        id++;
        return (distance_friends(id, level, friends));
    }

    void set_all(int &id, vector<vector<int>> &friends)
    {
        visited.clear();
        visited.resize(friends.size(), 0);
        visited[id] = 1;

        while (!go_to.empty())
            go_to.pop();
        go_to.push(id);
    }

public:
    vector<string> watchedVideosByFriends(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
    {
        vector<string> result;
        unordered_map<string, int> video;
        int start = 0;

        set_all(id, friends);
        vector<int> list_video = distance_friends(start, level, friends);

        for (int i : list_video)
        {
            for (string j : watchedVideos[i])
                video[j]++;
        }

        vector<pair<string, int>> temp(video.begin(), video.end());
        sort(temp.begin(), temp.end(), [](const pair<string, int> &a, const pair<string, int> &b)
             {
            if (a.second != b.second)
                return (a.second < b.second);
            return (a.second < b.second); });

        for (pair<string, int> &to_watch : temp)
            result.push_back(to_watch.first);
        return (result);
    }
};

void testcase(vector<vector<string>> &watchedVideos, vector<vector<int>> &friends, int id, int level)
{
    Solution s;
    vector<string> result;
    result = s.watchedVideosByFriends(watchedVideos, friends, id, level);

    cout << "result = {";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "}\n\n";
}

int main()
{
    vector<vector<string>> watchedVideos;
    vector<vector<int>> friends;
    testcase(watchedVideos = {{"A", "B"}, {"C"}, {"B", "C"}, {"D"}}, friends = {{1, 2}, {0, 3}, {0, 3}, {1, 2}}, 0, 1);
    testcase(watchedVideos = {{"A", "B"}, {"C"}, {"B", "C"}, {"D"}}, friends = {{1, 2}, {0, 3}, {0, 3}, {1, 2}}, 0, 2);
    testcase(watchedVideos = {{"m"}, {"xaqhyop", "lhvh"}}, friends = {{1}, {0}}, 1, 1);
}