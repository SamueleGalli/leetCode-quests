/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.Your code will only be given the head of the original linked list.



Example 1:


Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
Example 2:


Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]
Example 3:



Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]


Constraints:

* 0 <= n <= 1000
* -10^4 <= Node.val <= 10^4
* Node.random is null or is pointing to some node in the linked list.
*/

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

using namespace std;

#include <iostream>
#include <vector>

class Solution
{
private:
    void set_random(Node *temp, Node *clone)
    {
        while (temp)
        {
            if (temp->random)
                clone->random = temp->random->next;
            else
                clone->random = nullptr;
            temp = clone->next;
            if (temp)
                clone = temp->next;
        }
    }
/*
Ce un errore qui i nodi si collegano ma male e si perdono
*/
    void set_new_next(Node *temp, Node *clone)
    {
        Node *next;
        while (temp)
        {
            if (temp->next && temp->next->next)
            {
                next = temp->next->next;
                clone->next = clone->next->next;
                temp->next = next;
                clone = clone->next;
            }
            else
            {
                clone->next = nullptr;
                temp->next = nullptr;
            }
            temp = temp->next;
        }
    }

public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return (head);
        Node *temp = head;
        Node *next;
        while (temp)
        {
            next = temp->next;
            temp->next = new Node(temp->val);
            temp = temp->next;
            temp->next = next;
            temp = temp->next;
        }
        temp = head->next;
        set_random(head, temp);
        set_new_next(head, temp);
        return (temp);
    }
};

void create_list_random(const vector<int> &nums, const vector<int> &random, Node *&head)
{
    if (nums.empty() && random.empty())
    {
        head = nullptr;
        return;
    }

    vector<Node *> all_nodes(nums.size());
    head = new Node(nums[0]);
    all_nodes[0] = head;
    Node *temp = head;
    for (size_t i = 1; i < nums.size(); i++)
    {
        temp->next = new Node(nums[i]);
        all_nodes[i] = temp->next;
        temp = temp->next;
    }

    temp = head;
    for (size_t i = 0; i < nums.size(); i++)
    {
        if (random[i] == -1)
            temp->random = nullptr;
        else
            temp->random = all_nodes[random[i]];
        temp = temp->next;
    }
}

void print_node_random(Node *&head)
{
    if (head)
    {
        Node *temp = head;
        cout << "lista = {\n";
        while (temp != nullptr)
        {
            cout << "value->(" << temp->val << ") random->(";
            if (temp->random)
                cout << temp->random->val << ")";
            else
                cout << "nullptr)";
            if (temp->next)
                cout << endl;
            temp = temp->next;
        }
        cout << "\n}\n\n";
    }
    else
        cout << "head = nullptr\n\n";
}

void delete_node_random(Node *&head)
{
    Node *temp;
    while (head != nullptr)
    {
        temp = head;
        delete (temp);
    }
}

int main()
{
    Solution s;
    vector<int> nums;
    vector<int> random;
    Node *head;
    Node *new_head;

    nums = {7, 13, 11, 10, 1};
    random = {-1, 0, 4, 2, 0};
    create_list_random(nums, random, head);
    print_node_random(head);
    new_head = s.copyRandomList(head);
    print_node_random(new_head);
    delete_node_random(new_head);
    delete_node_random(head);
    cout << "------------------------------------------\n";

    /*   nums = {1, 2};
      random = {1, 1};
      create_list_random(nums, random, head);
      print_node_random(head);
      new_head = s.copyRandomList(head);
      print_node_random(new_head);
      delete_node_random(new_head);
      delete_node_random(head);
      cout << "------------------------------------------\n";

      nums = {};
      random = {};
      create_list_random(nums, random, head);
      print_node_random(head);
      new_head = s.copyRandomList(head);
      print_node_random(new_head);
      delete_node_random(new_head);
      delete_node_random(head);
      cout << "------------------------------------------\n";

      nums = {3, 3, 3};
      random = {-1, 0, -1};
      create_list_random(nums, random, head);
      print_node_random(head);
      new_head = s.copyRandomList(head);
      print_node_random(new_head);
      delete_node_random(new_head);
      delete_node_random(head); */
}