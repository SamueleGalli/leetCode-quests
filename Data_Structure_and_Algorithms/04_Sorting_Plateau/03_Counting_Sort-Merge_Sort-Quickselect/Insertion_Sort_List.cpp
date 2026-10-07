/*
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

*1. Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
*2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
*3. It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.




Example 1:

    Input: head = [4,2,1,3]
    Output: [1,2,3,4]

Example 2:

    Input: head = [-1,5,3,4,0]
    Output: [-1,0,3,4,5]


Constraints:

* The number of nodes in the list is in the range [1, 5000].
* -5000 <= Node.val <= 5000
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
public:
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode dummy(0);
        ListNode *start = &dummy;
        ListNode *temp = head;
        ListNode *next = nullptr;
        while (temp)
        {
            start = &dummy;
            next = temp->next;
            while (start->next && temp->val > start->next->val)
                start = start->next;
            temp->next = start->next;
            start->next = temp;
            temp = next;
        }
        return (dummy.next);
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
    vector<int> list;
    ListNode *head;

    list = {4, 2, 1, 3};
    create_list(list, head);
    print_node(head);
    head = s.insertionSortList(head);
    print_node(head);
    delete_node(head);

    list = {-1, 5, 3, 4, 0};
    create_list(list, head);
    print_node(head);
    head = s.insertionSortList(head);
    print_node(head);
    delete_node(head);
}