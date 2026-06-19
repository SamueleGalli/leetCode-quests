/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.



Example 1:


    Input: head = [3,2,0,-4], pos = 1
    Output: true
        Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:


    Input: head = [1,2], pos = 0
    Output: true
        Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:


    Input: head = [1], pos = -1
    Output: false
        Explanation: There is no cycle in the linked list.


Constraints:

* The number of the nodes in the list is in the range [0, 104].
* -10^5 <= Node.val <= 10^5
* pos is -1 or a valid index in the linked-list.


Follow up: Can you solve it using O(1) (i.e. constant) memory?
*/

using namespace std;

#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
    }
};

ListNode *create_list(vector<int> &nums, ListNode *&head)
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
    return (temp);
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

ListNode *cycle(ListNode *&head, int pos)
{
    if (pos == -1)
        return (nullptr);

    int i = 0;
    ListNode *temp = head;
    while (temp)
    {
        if (pos == i)
            break;
        temp = temp->next;
        i++;
    }
    return (temp);
}

int main()
{
    Solution s;
    vector<int> list;
    ListNode *head = nullptr;
    ListNode *end = nullptr;
    bool result;

    list = {3, 2, 0, -4};
    end = create_list(list, head);
    end->next = cycle(head, 1);
    result = s.hasCycle(head);
    end->next = nullptr;
    delete_node(head);

    list = {1, 2};
    end = create_list(list, head);
    end->next = cycle(head, -1);
    result = s.hasCycle(head);
    end->next = nullptr;
    delete_node(head);

    list = {1};
    end = create_list(list, head);
    end->next = cycle(head, 0);
    result = s.hasCycle(head);
    end->next = nullptr;
    delete_node(head);
}