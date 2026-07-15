/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.



Example 1:

    Input: head = [1,2,3,4]
    Output: [1,4,2,3]

Example 2:

    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]


Constraints:

* The number of nodes in the list is in the range [1, 5 * 104].
* 1 <= Node.val <= 1000
*/

using namespace std;

#include <iostream>
#include <vector>

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
private:
    ListNode *med_point(ListNode *temp)
    {
        ListNode *fast = temp;
        ListNode *slow = temp;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return (slow->next);
    }

    ListNode *invert(ListNode *temp)
    {
        ListNode *next = nullptr;
        ListNode *prev = nullptr;

        while (temp)
        {
            next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return (prev);
    }

public:
    void reorderList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *mid = invert(med_point(temp));
        ListNode *next_temp = nullptr;
        ListNode *next_mid = nullptr;

        while (mid && temp)
        {
            next_mid = mid->next;
            next_temp = temp->next;
            temp->next = mid;
            mid->next = next_temp;
            temp = next_temp;
            mid = next_mid;
        }
        temp->next = nullptr;
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
    vector<int> nodes;
    ListNode *head;

    create_list(nodes = {1, 2, 3, 4}, head);
    cout << "INPUT\n";
    print_node(head);
    s.reorderList(head);
    cout << "RESULT\n";
    print_node(head);
    delete_node(head);

    create_list(nodes = {1, 2, 3, 4, 5}, head);
    cout << "INPUT\n";
    print_node(head);
    s.reorderList(head);
    cout << "RESULT\n";
    print_node(head);
    delete_node(head);
}