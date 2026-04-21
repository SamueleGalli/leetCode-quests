/*
Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

    * arr.length >= 3
    * There exists some i with 0 < i < arr.length - 1 such that:
        * arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
        * arr[i] > arr[i + 1] > ... > arr[arr.length - 1]



Example 1:

    Input: arr = [2,1]
    Output: false

Example 2:

    Input: arr = [3,5,5]
    Output: false

Example 3:

    Input: arr = [0,3,2,1]
    Output: true



Constraints:

    * 1 <= arr.length <= 104
    * 0 <= arr[i] <= 104
*/

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        size_t i = 0;
        int increasing = 0;
        int decrising = 0;
        while (i + 1 < arr.size() && arr[i] < arr[i + 1])
        {
            i++;
            increasing = 1;
        }
        while (i + 1 < arr.size() && arr[i] > arr[i + 1])
        {
            decrising = 1;
            i++;
        }
        if (decrising == 1 && increasing == 1 && i == arr.size() - 1)
            return (true);
        else
            return (false);
    }
};

int main()
{
    Solution s;
    vector<int> arr;
    bool result;

    arr = {2, 1};
    result = s.validMountainArray(arr);
    cout << boolalpha << "result = " << result << endl;

    arr = {3, 5, 5};
    result = s.validMountainArray(arr);
    cout << boolalpha << "result = " << result << endl;

    arr = {0, 3, 2, 1};
    result = s.validMountainArray(arr);
    cout << boolalpha << "result = " << result << endl;
}