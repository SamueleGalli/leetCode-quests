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
        long int sum = 0;
        int result = 0;
        for (size_t i = 0; i < target.size(); i++)
        {
            sum += target[i];
            aux.push(target[i]);
        }
        while (aux.top() > 1)
        {
            sum -= aux.top();

            if (sum == 1)
                break;
            else if (sum == 0 || aux.top() % sum <= 0 || sum >= aux.top())
                return (false);

            result = aux.top() % sum;
            aux.pop();
            sum += result;
            aux.push(result);
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

    target = {1, 1000000000};
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

    target = {1, 234, 298, 344};
    result = s.isPossible(target);
    cout << boolalpha << "result = " << result << "\n-------------------------------------------------------\n";

    target = {2, 900000002};
    result = s.isPossible(target);
    cout << boolalpha << "result = " << result << "\n-------------------------------------------------------\n";

    target = {2, 900000001};
    result = s.isPossible(target);
    cout << boolalpha << "result = " << result << "\n-------------------------------------------------------\n";

    target = {5, 50};
    result = s.isPossible(target);
    cout << boolalpha << "result = " << result << "\n-------------------------------------------------------\n";
}