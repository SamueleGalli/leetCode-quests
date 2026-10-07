/*
Given a date string in the form Day Month Year, where:

* Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
* Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
* Year is in the range [1900, 2100].

Convert the date string to the format YYYY-MM-DD, where:

* YYYY denotes the 4 digit year.
* MM denotes the 2 digit month.
* DD denotes the 2 digit day.


Example 1:

    Input: date = "20th Oct 2052"
    Output: "2052-10-20"

Example 2:

    Input: date = "6th Jun 1933"
    Output: "1933-06-06"

Example 3:

    Input: date = "26th May 1960"
    Output: "1960-05-26"


Constraints:

* The given dates are guaranteed to be valid, so no error handling is necessary.
*/

using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
private:
    size_t formatter(string &date, size_t i, string &format, int option = 0)
    {
        string temp;
        for (; i < date.size() && date[i] != ' '; i++)
        {
            if (date[i] >= '0' && date[i] <= '9')
                temp += date[i];
        }

        if (option == 0)
        {
            if (temp.size() == 1)
                format = '0' + temp;
            else
                format = temp;
            format = '-' + format;
            i++;
        }
        else
            format = temp + '-' + format;

        return (i);
    }

    void format_month(string month, string &format)
    {
        vector<string> months = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        string temp;

        for (size_t i = 0; i < months.size(); i++)
        {
            if (months[i] == month)
            {
                temp = to_string(i + 1);
                if (i + 1 < 10)
                {
                    format = '0' + temp + format;
                }
                else
                    format = temp + format;
                break;
            }
        }
    }

public:
    string reformatDate(string date)
    {
        string format;
        size_t i = 0;

        i = formatter(date, i, format);
        format_month(date.substr(i, 3), format);
        i += 4;
        i = formatter(date, i, format, 1);
        return (format);
    }
};

int main()
{
    Solution s;
    string date;
    string formatted;

    date = "20th Oct 2052";
    formatted = s.reformatDate(date);
    cout << "reformatted data = " << formatted << "\n\n";

    date = "6th Jun 1933";
    formatted = s.reformatDate(date);
    cout << "reformatted data = " << formatted << "\n\n";

    date = "26th May 1960";
    formatted = s.reformatDate(date);
    cout << "reformatted data = " << formatted << "\n\n";
}