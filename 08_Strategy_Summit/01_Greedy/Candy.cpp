/*
There are n children standing in a line.
Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:

    Input: ratings = [1,0,2]
    Output: 5
        Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:

    Input: ratings = [1,2,2]
    Output: 4
        Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
        The third child gets 1 candy because it satisfies the above two conditions.

Constraints:

* 1 <= n == ratings.length <= 5 * 10^4
* 0 <= ratings[i] <= 5 * 10^4
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    int cout_dir(const vector<int> &ratings, size_t i, bool up, int count = 1)
    {
        while (i < ratings.size() && i + 1 < ratings.size())
        {
            if ((up && ratings[i + 1] <= ratings[i]) ||
                (!up && ratings[i + 1] >= ratings[i]))
                break;
            count++;
            i++;
        }
        if (count == 1)
            return (-1);
        return (count);
    }

public:
    int candy(vector<int> &ratings)
    {
        int candy_counter = 0;
        int descend = 0;
        int ascend = 0;
        vector<int> childs;

        childs.resize(ratings.size(), 1);

        for (size_t i = 0; i < ratings.size();)
        {
            ascend = cout_dir(ratings, i, true);
            for (int j = 1; j < ascend && i + 1 < ratings.size(); j++)
            {
                childs[i + 1] = j + 1;
                i++;
            }

            descend = cout_dir(ratings, i, false);

            if (ascend > descend)
            {
                i++;
                continue;
            }

            while (descend > 1)
                childs[i++] = descend--;

            if (descend == -1 && ascend == -1)
                i++;
        }
        for (int child : childs)
            candy_counter += child;

        return (candy_counter);
    }
};

int main()
{
    Solution s;
    int result;
    vector<int> ratings;

    ratings = {1, 0, 2};
    result = s.candy(ratings);
    cout << "result = " << result << endl;

    ratings = {1, 2, 2};
    result = s.candy(ratings);
    cout << "result = " << result << endl;

    ratings = {1, 3, 2, 2, 1};
    result = s.candy(ratings);
    cout << "result = " << result << endl;

    ratings = {1, 2, 3, 2, 1};
    result = s.candy(ratings);
    cout << "result = " << result << endl;

    ratings = {1, 6, 10, 8, 7, 3, 2};
    result = s.candy(ratings);
    cout << "result = " << result << endl;

    ratings = {1, 2, 3};
    result = s.candy(ratings);
    cout << "result = " << result << endl;

    ratings = {3, 2, 1};
    result = s.candy(ratings);
    cout << "result = " << result << endl;

    ratings = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    result = s.candy(ratings);
    cout << "result = " << result << endl;

    ratings = {1, 2, 3, 2, 1, 2, 3};
    result = s.candy(ratings);
    cout << "result = " << result << endl;

    ratings = {1, 3, 4, 5, 2};
    result = s.candy(ratings);
    cout << "result = " << result << endl;
}