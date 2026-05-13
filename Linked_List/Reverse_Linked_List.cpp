/*
Given the head of a singly linked list, reverse the list, and return the reversed list.



Example 1:


    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]

Example 2:

    Input: head = [1,2]
    Output: [2,1]

Example 3:

    Input: head = []
    Output: []


Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000


Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *finally;
        ListNode *next;
        if (head && head->next)
        {

            next = head->next;
            finally = reverseList(head->next);
            next->next = head;
            head->next = nullptr;
            return (finally);
        }
        return (head);
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

int main()
{

    Solution s;
    vector<int> nums;
    ListNode *head;

    nums = {1, 2, 3, 4, 5};
    create_list(nums, head);
    cout << "print list\n";
    print_node(head);
    head = s.reverseList(head);
    cout << "head resulted\n";
    print_node(head);
    delete_node(head);

    nums = {1, 2};
    create_list(nums, head);
    cout << "print list\n";
    print_node(head);
    head = s.reverseList(head);
    cout << "head resulted\n";
    print_node(head);
    delete_node(head);

    nums = {};
    create_list(nums, head);
    cout << "print list\n";
    print_node(head);
    head = s.reverseList(head);
    cout << "head resulted\n";
    print_node(head);
    delete_node(head);
}
