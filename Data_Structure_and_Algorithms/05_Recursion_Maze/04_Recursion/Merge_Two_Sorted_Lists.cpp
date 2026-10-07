/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:


    Input: list1 = [1,2,4], list2 = [1,3,4]
    Output: [1,1,2,3,4,4]

Example 2:

    Input: list1 = [], list2 = []
    Output: []

Example 3:

    Input: list1 = [], list2 = [0]
    Output: [0]


Constraints:

* The number of nodes in both lists is in the range [0, 50].
* -100 <= Node.val <= 100
* Both list1 and list2 are sorted in non-decreasing order.
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return (list2);
        else if (!list2)
            return (list1);

        ListNode *temp = nullptr;

        if (list1->val <= list2->val)
        {
            temp = list1;
            temp->next = mergeTwoLists(list1->next, list2);
        }
        else if (list1->val > list2->val)
        {
            temp = list2;
            temp->next = mergeTwoLists(list1, list2->next);
        }
        return (temp);
    }
};

ListNode *create_list(const vector<int> &nodes)
{
    if (nodes.empty())
        return (nullptr);
    ListNode *temp = new ListNode(nodes[0]);
    ListNode *head = temp;

    for (size_t i = 1; i < nodes.size(); i++)
    {
        temp->next = new ListNode(nodes[i]);
        temp = temp->next;
    }
    return (head);
}

void Delete_nodes(ListNode *head)
{
    ListNode *temp = nullptr;

    while (head)
    {
        temp = head;
        head = head->next;
        delete (temp);
        temp = nullptr;
    }
}

void print_nodes(ListNode *node)
{
    if (!node)
    {
        cout << "nullptr\n";
        return;
    }
    while (node)
    {
        cout << node->val;
        if (node->next)
            cout << "->";
        node = node->next;
    }
    cout << "\n";
}

void Testcase(const vector<int> &nodes1, const vector<int> &nodes2)
{
    Solution s;
    ListNode *list1 = nullptr;
    ListNode *list2 = nullptr;
    ListNode *result = nullptr;

    list1 = create_list(nodes1);
    cout << "list1 = ";
    print_nodes(list1);
    list2 = create_list(nodes2);
    cout << "list2 = ";
    print_nodes(list2);
    result = s.mergeTwoLists(list1, list2);
    cout << "result = ";
    print_nodes(result);

    Delete_nodes(result);
    cout << "------------------------------------------------\n";
}

int main()
{
    vector<int> nodes1;
    vector<int> nodes2;

    Testcase(nodes1 = {1, 2, 4}, nodes2 = {1, 3, 4});
    Testcase(nodes1 = {}, nodes2 = {});
    Testcase(nodes1 = {}, nodes2 = {0});
}