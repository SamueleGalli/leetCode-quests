/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.
Note that you do not have any change in hand at first.
Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

Example 1:

    Input: bills = [5,5,5,10,20]
    Output: true
        Explanation:
        From the first 3 customers, we collect three $5 bills in order.
        From the fourth customer, we collect a $10 bill and give back a $5.
        From the fifth customer, we give a $10 bill and a $5 bill.
        Since all customers got correct change, we output true.

Example 2:

    Input: bills = [5,5,10,10,20]
    Output: false
        Explanation:
        From the first two customers in order, we collect two $5 bills.
        For the next two customers in order, we collect a $10 bill and give back a $5 bill.
        For the last customer, we can not give the change of $15 back because we only have two $10 bills.
        Since not every customer received the correct change, the answer is false.

Constraints:

* 1 <= bills.length <= 10^5
* bills[i] is either 5, 10, or 20.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    int fives;
    int tens;

    bool valid_reminder(const int &bill)
    {
        switch (bill)
        {
        case 5:
            fives++;
            break;
        case 10:
            if (fives > 0)
            {
                tens++;
                fives--;
            }
            else
                return (false);
            break;
        case 20:
            if (fives > 0 && tens > 0)
            {
                tens--;
                fives--;
            }
            else if (fives >= 3)
            {
                fives -= 3;
            }
            else
                return (false);
            break;
        }
        return (true);
    }

public:
    bool lemonadeChange(vector<int> &bills)
    {
        fives = 0;
        tens = 0;
        for (const int &bill : bills)
        {
            if (!valid_reminder(bill))
                return (false);
        }
        return (true);
    }
};

int main()
{
    Solution s;
    vector<int> bills;
    bool result;

    bills = {5, 5, 5, 10, 20};
    result = s.lemonadeChange(bills);
    cout << boolalpha << "result = " << result << endl;

    bills = {5, 5, 10, 10, 20};
    result = s.lemonadeChange(bills);
    cout << boolalpha << "result = " << result << endl;
}