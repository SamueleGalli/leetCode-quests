/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

* k == lists.length
* 0 <= k <= 10^4
* 0 <= lists[i].length <= 500
* -10^4 <= lists[i][j] <= 10^4
* lists[i] is sorted in ascending order.
* The sum of lists[i].length will not exceed 10^4.
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
private:
	ListNode *merge(ListNode *&node1, ListNode *&node2)
	{
		ListNode dummy = ListNode(0);
		ListNode *head = &dummy;
		while (node1 && node2)
		{
			if (node1->val < node2->val)
			{
				head->next = node1;
				node1 = node1->next;
			}
			else
			{
				head->next = node2;
				node2 = node2->next;
			}
			head = head->next;
		}
		if (node1)
			head->next = node1;
		else
			head->next = node2;
		return (dummy.next);
	}
	ListNode *merged_nodes(vector<ListNode *> &lists, int start, int end)
	{
		if (start == end)
			return (lists[start]);
		else if (start > end)
			return (nullptr);
		ListNode *first;
		ListNode *second;
		ListNode *merged;
		int mid = (start + end) / 2;

		first = merged_nodes(lists, start, mid);
		second = merged_nodes(lists, mid + 1, end);
		merged = merge(first, second);
		return (merged);
	}

public:
	ListNode *mergeKLists(vector<ListNode *> &lists)
	{
		return (merged_nodes(lists, 0, static_cast<int>(lists.size()) - 1));
	}
};

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

void create_list(const vector<int> &nums, ListNode *&head)
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

void initialize_node(vector<ListNode *> &lists, initializer_list<vector<int>> nodes)
{
	ListNode *head;
	size_t i = 0;

	lists.resize(nodes.size());
	cout << "liste in input\n";
	for (const vector<int> &node : nodes)
	{
		head = nullptr;
		create_list(node, head);
		cout << "----------------------------------------------------------\n";
		print_node(head);
		cout << "---------------------------------------------------------------------------\n";
		lists[i++] = head;
	}
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
	ListNode *result = nullptr;
	vector<int> nodes;
	vector<ListNode *> lists;

	initialize_node(lists, {{1, 4, 5}, {1, 3, 4}, {2, 6}});
	result = s.mergeKLists(lists);
	cout << "Lista risultante\n";
	print_node(result);
	delete_node(result);

	initialize_node(lists, {});
	result = s.mergeKLists(lists);
	cout << "Lista risultante\n";
	print_node(result);
	delete_node(result);

	initialize_node(lists, {{}});
	result = s.mergeKLists(lists);
	cout << "Lista risultante\n";
	print_node(result);
	delete_node(result);
}