/*
Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.



Example 1:

    Input: temperatures = [73,74,75,71,69,72,76,73]
    Output: [1,1,4,2,1,1,0,0]

Example 2:

    Input: temperatures = [30,40,50,60]
    Output: [1,1,1,0]

Example 3:

    Input: temperatures = [30,60,90]
    Output: [1,1,0]



Constraints:

    * 1 <= temperatures.length <= 105
    * 30 <= temperatures[i] <= 100

*/

using namespace std;

#include <iostream>
#include <vector>
#include <stack>

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        vector<int> answer(temperatures.size(), 0);
        stack<size_t> index;
        for (size_t i = 0; i < temperatures.size(); i++)
        {
            while (!index.empty() && temperatures[i] > temperatures[index.top()])
            {
                answer[index.top()] = static_cast<int>(i - index.top());
                index.pop();
            }
            index.push(i);
        }
        return (answer);
    }
};

void print_result(const vector<int> &result)
{
    cout << "\n-------------------------------------------------------\nresult = {";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "}\n-----------------------------------------------------------\n";
}

int main()
{
    Solution s;
    vector<int> temperatures;
    vector<int> result;

    temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    result = s.dailyTemperatures(temperatures);
    print_result(result);

    temperatures = {30, 40, 50, 60};
    result = s.dailyTemperatures(temperatures);
    print_result(result);

    temperatures = {30, 60, 90};
    result = s.dailyTemperatures(temperatures);
    print_result(result);
}