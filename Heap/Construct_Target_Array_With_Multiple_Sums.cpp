/*
You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

    * let x be the sum of all elements currently in your array.
    * choose index i, such that 0 <= i < n and set the value of arr at index i to x.
    * You may repeat this procedure as many times as needed.

Return true if it is possible to construct the target array from arr, otherwise, return false.



Example 1:

    Input: target = [9,3,5]
    Output: true
        Explanation: Start with arr = [1, 1, 1]
        [1, 1, 1], sum = 3 choose index 1
        [1, 3, 1], sum = 5 choose index 2
        [1, 3, 5], sum = 9 choose index 0
        [9, 3, 5] Done

Example 2:

    Input: target = [1,1,1,2]
    Output: false
    Explanatio  n: Impossible to create target array from [1,1,1,1].

Example 3:

    Input: target = [8,5]
    Output: true



Constraints:

    * n == target.length
    * 1 <= n <= 5 * 104
    * 1 <= target[i] <= 109
*/

/*
TODO Funziona solo molto lento da ottimizzare con '%' forse o '/' credo?*/
using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Solution
{

public:
    bool isPossible(vector<int> &target)
    {
        priority_queue<int> aux;
        int total_sum = 0;
        int new_push = 0;
        int maximum = 0;
        for (size_t i = 0; i < target.size(); i++)
        {
            total_sum += target[i];
            aux.push(target[i]);
        }
        while (!aux.empty() && aux.top() > 1)
        {
            maximum = aux.top();
            total_sum -= maximum;
            new_push = maximum - total_sum;
            aux.pop();
            aux.push(new_push);
            total_sum += new_push;
            if (new_push <= 0)
                return (false);
        }
        return (true);
    }
};

int main()
{
    Solution s;
    bool result;
    vector<int> target;

    target = {9, 3, 5};
    result = s.isPossible(target);
    cout << boolalpha << "result = " << result << "\n-------------------------------------------------------\n";

    target = {1, 1, 1, 2};
    result = s.isPossible(target);
    cout << boolalpha << "result = " << result << "\n-------------------------------------------------------\n";

    target = {8, 5};
    result = s.isPossible(target);
    cout << boolalpha << "result = " << result << "\n-------------------------------------------------------\n";

    target = {3, 3, 6};
    result = s.isPossible(target);
    cout << boolalpha << "result = " << result << "\n-------------------------------------------------------\n";

    target = {1, 1, 2};
    result = s.isPossible(target);
    cout << boolalpha << "result = " << result << "\n-------------------------------------------------------\n";

    target = {1, 1000000000};
    result = s.isPossible(target);
    cout << boolalpha << "result = " << result << "\n-------------------------------------------------------\n";
}