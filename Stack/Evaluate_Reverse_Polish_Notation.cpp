/*
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

    *The valid operators are '+', '-', '*', and '/'.
    *Each operand may be an integer or another expression.
    *The division between two integers always truncates toward zero.
    *There will not be any division by zero.
    *The input represents a valid arithmetic expression in a reverse polish notation.
    *The answer and all the intermediate calculations can be represented in a 32-bit integer.



Example 1:

    Input: tokens = ["2","1","+","3","*"]
    Output: 9
        Explanation: ((2 + 1) * 3) = 9

Example 2:

    Input: tokens = ["4","13","5","/","+"]
    Output: 6
        Explanation: (4 + (13 / 5)) = 6

Example 3:

    Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
    Output: 22
        Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
        = ((10 * (6 / (12 * -11))) + 17) + 5
        = ((10 * (6 / -132)) + 17) + 5
        = ((10 * 0) + 17) + 5
        = (0 + 17) + 5
        = 17 + 5
        = 22



Constraints:

    * 1 <= tokens.length <= 104
    * tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

*/

using namespace std;

#include <iostream>
#include <vector>
#include <stack>

class Solution
{
private:
    void do_expression(size_t i, vector<string> &tokens, int num1, int num2, stack<int> &aux)
    {
        if (tokens[i] == "/")
            aux.push(num1 / num2);
        if (tokens[i] == "*")
            aux.push(num1 * num2);
        if (tokens[i] == "+")
            aux.push(num1 + num2);
        if (tokens[i] == "-")
            aux.push(num1 - num2);
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> aux;
        int x, y;
        for (size_t i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "/" || tokens[i] == "*")
            {
                y = aux.top();
                aux.pop();
                x = aux.top();
                aux.pop();
                do_expression(i, tokens, x, y, aux);
            }
            else
                aux.push(stoi(tokens[i]));
        }
        return (aux.top());
    }
};

int main()
{
    Solution s;
    int result;
    vector<string> tokens;

    tokens = {"2", "1", "+", "3", "*"};
    result = s.evalRPN(tokens);
    cout << "result = " << result << endl;

    tokens = {"4", "13", "5", "/", "+"};
    result = s.evalRPN(tokens);
    cout << "result = " << result << endl;

    tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    result = s.evalRPN(tokens);
    cout << "result = " << result << endl;
}