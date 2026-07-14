/*
A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.



Example 1:

    Input: s = "25525511135"
    Output: ["255.255.11.135","255.255.111.35"]
Example 2:

    Input: s = "0000"
    Output: ["0.0.0.0"]
Example 3:

    Input: s = "101023"
    Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]


Constraints:

* 1 <= s.length <= 20
* s consists of digits only.
*/

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    void get_adresses(vector<string> &result, string adress, string &ip, const string &s, size_t i = 0, size_t seg = 0)
    {
        size_t take_out;
        if (i >= s.size())
        {
            if (i == s.size() && seg == 4)
                result.push_back(ip);
            return;
        }
        for (size_t k = i; k < i + 3 && k < s.size(); k++)
        {
            adress.push_back(s[k]);
            if (stoi(adress) <= 255)
            {
                take_out = ip.size();
                ip += adress;
                if (seg + 1 < 4)
                    ip += '.';
                get_adresses(result, "", ip, s, k + 1, seg + 1);
                ip.resize(take_out);
            }
            if (stoi(adress) == 0)
                return;
        }
    }

public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        string ip;
        result.reserve(17);
        ip.reserve(17);
        get_adresses(result, "", ip, s);
        return (result);
    }
};

void print_vec(const vector<string> &result)
{
    cout << "result = {";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "};\n\n";
}

int main()
{
    Solution s;
    vector<string> result;
    string word;

    word = "25525511135";
    result = s.restoreIpAddresses(word);
    print_vec(result);

    word = "0000";
    result = s.restoreIpAddresses(word);
    print_vec(result);

    word = "101023";
    result = s.restoreIpAddresses(word);
    print_vec(result);

    word = "999999999999";
    result = s.restoreIpAddresses(word);
    print_vec(result);
}