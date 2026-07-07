/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.



Example 1:

    Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
    Output: 3
        Explanation: Let us see what happened in the first three days. x means flower bloomed and _ means flower did not bloom in the garden.
        We need 3 bouquets each should contain 1 flower.
        After day 1: [x, _, _, _, _]   // we can only make one bouquet.
        After day 2: [x, _, _, _, x]   // we can only make two bouquets.
        After day 3: [x, _, x, _, x]   // we can make 3 bouquets. The answer is 3.

Example 2:

    Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
    Output: -1
        Explanation: We need 3 bouquets each has 2 flowers, that means we need 6 flowers. We only have 5 flowers so it is impossible to get the needed bouquets and we return -1.

Example 3:

    Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
    Output: 12
        Explanation: We need 2 bouquets each should have 3 flowers.
        Here is the garden after the 7 and 12 days:
        After day 7: [x, x, x, x, _, x, x]
        We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
        After day 12: [x, x, x, x, x, x, x]
        It is obvious that we can make two bouquets in different ways.


Constraints:

* bloomDay.length == n
* 1 <= n <= 105
* 1 <= bloomDay[i] <= 10^9
* 1 <= m <= 106
* 1 <= k <= n

*/

/*
TODO trova il min e il max giorno
TODO usa ricerca binaria(ovvero vai nel mezzo e dimezza il tempo di ricerca)
TODO vai a destra o sinistra per verificare il giorno valido
*/
using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>

class Solution
{
public:
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        if (static_cast<long int>(m) * static_cast<long int>(k) > static_cast<long int>(bloomDay.size()))
            return (-1);
        int min_day = *min_element(bloomDay.begin(), bloomDay.end());
        int max_day = *max_element(bloomDay.begin(), bloomDay.end());
        int flower, boque, mid;
        while (min_day < max_day)
        {
            mid = (min_day + max_day) / 2;
            boque = 0;
            flower = 0;
            for (size_t i = 0; i < bloomDay.size(); i++)
            {
                if (bloomDay[i] <= mid)
                {
                    if (flower < k)
                        flower++;
                    if (flower == k)
                    {
                        boque++;
                        flower = 0;
                    }
                }
                else
                    flower = 0;
            }
            if (boque >= m)
                max_day = mid;
            else
                min_day = mid + 1;
        }
        return (min_day);
    }
};

void testcase(vector<int> &bloomDay, int m, int k, int excepted)
{
    Solution s;
    int result;

    result = s.minDays(bloomDay, m, k);
    if (result == excepted)
        cout << "Correct result (" << result << " == " << excepted << ")\n";
    else
        cout << "Incorrect result (" << result << " != " << excepted << ")\n";
}

int main()
{
    vector<int> bloomDay;
    testcase(bloomDay = {1, 10, 3, 10, 2}, 3, 1, 3);
    testcase(bloomDay = {1, 10, 3, 10, 2}, 3, 2, -1);
    testcase(bloomDay = {7, 7, 7, 7, 12, 7, 7}, 2, 3, 12);
}