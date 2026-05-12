/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.



Example 1:

    Input: head = [1,1,2]
    Output: [1,2]

Example 2:


    Input: head = [1,1,2,3,3]
    Output: [1,2,3]


Constraints:

* The number of nodes in the list is in the range [0, 300].
* -100 <= Node.val <= 100
* The list is guaranteed to be sorted in ascending order.
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *temp;
        ListNode *orign = head;
        while (head != nullptr && head->next != nullptr)
        {
            temp = head;
            if (head->val == head->next->val)
            {
                temp = temp->next;
                head->next = head->next->next;
                delete (temp);
            }
            else
                head = head->next;
        }
        return (orign);
    }
};

void create_list(vector<int> &nums, ListNode *&head)
{
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
    {
        Solution s;
        vector<int> nums;
        ListNode *head;

        nums = {1, 1, 2};
        create_list(nums, head);
        cout << "list created\n";
        print_node(head);
        head = s.deleteDuplicates(head);
        print_node(head);
        delete_node(head);

        nums = {1, 1, 2, 3, 3};
        create_list(nums, head);
        cout << "list created\n";
        print_node(head);
        head = s.deleteDuplicates(head);
        print_node(head);
        delete_node(head);

        nums = {1, 1, 1};
        create_list(nums, head);
        cout << "list created\n";
        print_node(head);
        head = s.deleteDuplicates(head);
        print_node(head);
        delete_node(head);
    }
}
