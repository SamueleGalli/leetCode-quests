/*
You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.

Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.



Example 1:

    Input: arr = [0,1,0]

    Output: 1

Example 2:

    Input: arr = [0,2,1,0]

    Output: 1

Example 3:

    Input: arr = [0,10,5,2]

    Output: 1

Constraints:

* 3 <= arr.length <= 10^5
* 0 <= arr[i] <= 10^6
* arr is guaranteed to be a mountain array.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int low = 0;
        int high = static_cast<int>(arr.size());
        int med;
        while (low <= high)
        {
            med = (low + high) / 2;
            if (arr[med] > arr[med + 1] && arr[med] > arr[med - 1])
                return (med);
            else if (arr[med] < arr[med + 1])
                low = med + 1;
            else if (arr[med] > arr[med + 1])
                high = med - 1;
        }
        return (-1);
    }
};

int main()
{
    Solution s;
    vector<int> arr;
    int result;

    arr = {0, 1, 0};
    result = s.peakIndexInMountainArray(arr);
    cout << "result = " << result << endl;

    arr = {0, 2, 1, 0};
    result = s.peakIndexInMountainArray(arr);
    cout << "result = " << result << endl;

    arr = {0, 10, 5, 2};
    result = s.peakIndexInMountainArray(arr);
    cout << "result = " << result << endl;

    arr = {1, 2, 3, 4, 111, 5, 4, 3, 2, 1};
    result = s.peakIndexInMountainArray(arr);
    cout << "result = " << result << endl;
}