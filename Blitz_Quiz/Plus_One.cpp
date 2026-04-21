/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.



Example 1:

    Input: digits = [1,2,3]
    Output: [1,2,4]
        Explanation: The array represents the integer 123.
        Incrementing by one gives 123 + 1 = 124.
        Thus, the result should be [1,2,4].

Example 2:

    Input: digits = [4,3,2,1]
    Output: [4,3,2,2]
        Explanation: The array represents the integer 4321.
        Incrementing by one gives 4321 + 1 = 4322.
        Thus, the result should be [4,3,2,2].

Example 3:

    Input: digits = [9]
    Output: [1,0]
        Explanation: The array represents the integer 9.
        Incrementing by one gives 9 + 1 = 10.
        Thus, the result should be [1,0].



Constraints:

    * 1 <= digits.length <= 100
    * 0 <= digits[i] <= 9
    * digits does not contain any leading 0's.

*/

#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        size_t dim = digits.size() - 1;
        if (digits[dim] != 9)
            digits[dim] = digits[dim] + 1;
        else
        {
            do
            {
                digits[dim] = 0;
                if (dim == 0)
                    break;
                dim--;
            } while (digits[dim] == 9);
            if (dim == 0 && digits[dim] == 0)
                digits.insert(digits.begin(), 1);
            else
                digits[dim] = digits[dim] + 1;
        }
        return (digits);
    }
};

void stamp_result(const vector<int> &result)
{
    cout << "\n-------------------------------------------\nresult = {";
    for (size_t i = 0; i + 1 < result.size(); i++)
    {
        cout << result[i] << ", ";
    }
    cout << result[result.size() - 1] << "}\n--------------------------------------------------------\n";
}

int main()
{
    Solution s;
    vector<int> digit;
    vector<int> result;

    digit = {2, 1};
    result = s.plusOne(digit);
    stamp_result(result);

    digit = {3, 5, 5};
    result = s.plusOne(digit);
    stamp_result(result);

    digit = {0, 3, 2, 1};
    result = s.plusOne(digit);
    stamp_result(result);
}