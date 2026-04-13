
/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.



Example 1:

    Input: nums = [8,1,2,2,3]
    Output: [4,0,1,1,3]
    Explanation:
        For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
        For nums[1]=1 does not exist any smaller number than it.
        For nums[2]=2 there exist one smaller number than it (1).
        For nums[3]=2 there exist one smaller number than it (1).
        For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

Example 2:

    Input: nums = [6,5,4,8]
    Output: [2,1,0,3]

Example 3:

    Input: nums = [7,7,7,7]
    Output: [0,0,0,0]



Constraints:

    * 2 <= nums.length <= 500
    * 0 <= nums[i] <= 100

*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    int check_min(size_t i, const vector<int> &nums)
    {
        int count = 0;
        for (size_t j = 0; j < nums.size(); j++)
        {
            if (nums[i] != nums[j] && nums[j] < nums[i])
                count++;
        }
        return (count);
    }

public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> result;

        for (size_t i = 0; i < nums.size(); i++)
        {
            result.push_back(check_min(i, nums));
        }
        return (result);
    }
};

void print_array(vector<int> &result)
{
    cout << "\n--------------------------\nresult{";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "}\n-----------------------------------\n";
}

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> result;

    nums = {8, 1, 2, 2, 3};
    result = s.smallerNumbersThanCurrent(nums);
    print_array(result);

    nums = {6, 5, 4, 8};
    result = s.smallerNumbersThanCurrent(nums);
    print_array(result);

    nums = {7, 7, 7, 7};
    result = s.smallerNumbersThanCurrent(nums);
    print_array(result);
}