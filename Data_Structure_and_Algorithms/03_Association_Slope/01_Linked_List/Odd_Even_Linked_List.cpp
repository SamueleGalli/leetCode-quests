/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.



Example 1:


Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:


Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]


Constraints:

* The number of nodes in the linked list is in the range [0, 10^4].
* -10^6 <= Node.val <= 10^6
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

#include <vector>
#include <iostream>

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *new_head = head;
        ListNode *Even = nullptr;
        ListNode *temp_even;

        while (head && head->next && head->next->next)
        {
            if (!Even)
            {
                Even = head->next;
                temp_even = Even;
            }
            else
            {
                Even->next = head->next;
                Even = Even->next;
            }
            head->next = head->next->next;
            head = head->next;
        }
        if (Even)
        {
            Even->next = nullptr;
            if (head && head->next)
            {
                Even->next = head->next;
                Even = Even->next;
            }
            head->next = temp_even;
        }
        return (new_head);
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
    cout << "list created\n";
    print_node(head);
    head = s.oddEvenList(head);
    print_node(head);
    delete_node(head);

    nums = {2, 1, 3, 5, 6, 4, 7};
    create_list(nums, head);
    cout << "list created\n";
    print_node(head);
    head = s.oddEvenList(head);
    print_node(head);
    delete_node(head);

    nums = {2, 1, 3, 5};
    create_list(nums, head);
    cout << "list created\n";
    print_node(head);
    head = s.oddEvenList(head);
    print_node(head);
    delete_node(head);

    nums = {1};
    create_list(nums, head);
    cout << "list created\n";
    print_node(head);
    head = s.oddEvenList(head);
    print_node(head);
    delete_node(head);

    nums = {1, 1};
    create_list(nums, head);
    cout << "list created\n";
    print_node(head);
    head = s.oddEvenList(head);
    print_node(head);
    delete_node(head);
}
