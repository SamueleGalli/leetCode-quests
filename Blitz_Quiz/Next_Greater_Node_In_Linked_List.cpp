/*
You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.



Example 1:


    Input: head = [2,1,5]
    Output: [5,5,0]

Example 2:

    Input: head = [2,7,4,3,5]
    Output: [7,0,5,5,0]


Constraints:

    * The number of nodes in the list is n.
    * 1 <= n <= 104
    * 1 <= Node.val <= 109
*/

using namespace std;

#include <iostream>
#include <vector>
#include <stack>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        ListNode *temp = head;
        vector<int> array;
        vector<int> result;
        stack<int> great;

        while (temp)
        {
            array.push_back(temp->val);
            temp = temp->next;
        }
        result.resize(array.size());
        for (size_t i = 0; i < array.size(); i++)
        {
            while (!great.empty() && array[i] > array[great.top()])
            {
                result[great.top()] = array[i];
                great.pop();
            }
            great.push(i);
        }
        return (result);
    }
};

void create_list(vector<int> &nums, ListNode *&head)
{
    if (nums.empty())
        return;
    head = new ListNode(nums[0]);
    ListNode *temp = head;
    for (size_t i = 1; i < nums.size(); i++)
    {
        temp->next = new ListNode(nums[i]);
        temp = temp->next;
    }
}

void print_node(ListNode *&head)
{
    ListNode *temp = head;
    cout << "lista = {";
    while (temp != nullptr)
    {
        if (temp->next != nullptr)
            cout << temp->val << "->";
        else
            cout << temp->val;
        temp = temp->next;
    }
    cout << "}\n\n";
}

void delete_node(ListNode *&head)
{
    ListNode *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete (temp);
    }
}

void print_vector(const vector<int> &result)
{
    cout << "array = {";
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i + 1 < result.size())
            cout << ", ";
    }
    cout << "}\n\n";
}

int main()
{
    Solution s;
    ListNode *head;
    vector<int> nodes;
    vector<int> result;

    nodes = {2, 1, 5};
    create_list(nodes, head);
    print_vector(nodes);
    result = s.nextLargerNodes(head);
    print_vector(result);
    delete_node(head);

    nodes = {2, 7, 4, 3, 5};
    create_list(nodes, head);
    print_vector(nodes);
    result = s.nextLargerNodes(head);
    print_vector(result);
    delete_node(head);

    nodes = {1, 7, 5, 1, 9, 2, 5, 1};
    create_list(nodes, head);
    print_vector(nodes);
    result = s.nextLargerNodes(head);
    print_vector(result);
    delete_node(head);

    nodes = {9, 7, 6, 7, 6, 9};
    create_list(nodes, head);
    print_vector(nodes);
    result = s.nextLargerNodes(head);
    print_vector(result);
    delete_node(head);

    nodes = {7, 2, 6, 6, 9, 4, 3};
    create_list(nodes, head);
    print_vector(nodes);
    result = s.nextLargerNodes(head);
    print_vector(result);
    delete_node(head);
}