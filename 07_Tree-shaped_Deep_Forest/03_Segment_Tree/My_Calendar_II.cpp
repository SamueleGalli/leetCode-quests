/*
You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a triple booking.
A triple booking happens when three events have some non-empty intersection (i.e., some moment is common to all the three events.).
The event can be represented as a pair of integers startTime and endTime that represents a booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.
Implement the MyCalendarTwo class:

    * MyCalendarTwo() Initializes the calendar object.
    * boolean book(int startTime, int endTime) Returns true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.


Example 1:

    Input
    ["MyCalendarTwo", "book", "book", "book", "book", "book", "book"]
    [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]]
    Output
    [null, true, true, true, false, true, true]

        Explanation
        MyCalendarTwo myCalendarTwo = new MyCalendarTwo();
        myCalendarTwo.book(10, 20); // return True, The event can be booked.
        myCalendarTwo.book(50, 60); // return True, The event can be booked.
        myCalendarTwo.book(10, 40); // return True, The event can be double booked.
        myCalendarTwo.book(5, 15);  // return False, The event cannot be booked, because it would result in a triple booking.
        myCalendarTwo.book(5, 10); // return True, The event can be booked, as it does not use time 10 which is already double booked.
        myCalendarTwo.book(25, 55); // return True, The event can be booked, as the time in [25, 40) will be double booked with the third event, the time [40, 50) will be single booked, and the time [50, 55) will be double booked with the second event.


Constraints:

* 0 <= start < end <= 10^9
* At most 1000 calls will be made to book.
*/

using namespace std;

#include <iostream>
#include <vector>

class Node
{
    friend class MyCalendarTwo;

private:
    pair<long, long> range;
    int count;
    Node *L;
    Node *R;

public:
    Node() : range({0, 1000000000}), count(0), L(nullptr), R(nullptr)
    {
    }
    Node(pair<long, long> range, int count) : range(range), count(count), L(nullptr), R(nullptr)
    {
    }
};

class MyCalendarTwo
{
private:
    Node *root;
    vector<Node *> reset;

    void delete_tree(Node *&root)
    {
        if (!root)
            return;
        delete_tree(root->L);
        delete_tree(root->R);
        delete (root);
        root = nullptr;
    }

    bool clean_and_exit(void)
    {
        for (Node *&node : reset)
            node->count--;

        reset.clear();

        return (false);
    }

    int help_check(const pair<long, long> &range, const pair<int, int> &time, const long &mid)
    {
        if (range.first >= time.first && range.second <= time.second)
            return (0);
        else if (range.first == range.second)
            return (1);
        else if (mid > time.second)
            return (2);
        else if (mid < time.first)
            return (3);
        else
            return (4);
    }

    bool create_tree(const pair<int, int> &time, Node *&node)
    {
        long mid = (node->range.first + node->range.second) / 2;
        switch (help_check(node->range, time, mid))
        {
        case 0:
            if (node->count <= 1)
            {

                reset.push_back(node);
                if (node->L)
                {
                    if (!create_tree(time, node->L))
                        return (clean_and_exit());
                }
                if (node->R)
                {
                    if (!create_tree(time, node->R))
                        return (clean_and_exit());
                }
                node->count++;
                return (true);
            }
            return (false);
        case 1:
            return (true);
        case 2:
            if (!node->L)
                node->L = new Node({node->range.first, mid}, node->count);
            return (create_tree(time, node->L));
        case 3:
            if (!node->R)
                node->R = new Node({mid + 1, node->range.second}, node->count);
            return (create_tree(time, node->R));
        default:
            if (!node->L)
                node->L = new Node({node->range.first, mid}, node->count);
            if (!create_tree(time, node->L))
                return (clean_and_exit());

            if (!node->R)
                node->R = new Node({mid + 1, node->range.second}, node->count);
            if (!create_tree(time, node->R))
                return (clean_and_exit());
            return (true);
        }
    }

public:
    MyCalendarTwo()
    {
        reset.clear();
        root = new Node();
    }

    bool book(int startTime, int endTime)
    {
        return (create_tree({startTime, endTime - 1}, root));
    }

    ~MyCalendarTwo()
    {
        delete_tree(root);
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

int main()
{
    MyCalendarTwo *calendar;
    vector<pair<int, int>> tests;
    {
        calendar = new MyCalendarTwo();
        tests = {{10, 20}, {50, 60}, {5, 15}, {5, 10}, {25, 55}};
        for (pair<int, int> &test : tests)
            cout << boolalpha << calendar->book(test.first, test.second) << "\n\n";
        delete (calendar);
        cout << "--------------------------------------------------------\n";
    }

    {
        calendar = new MyCalendarTwo();
        tests = {{10, 20}, {10, 20}, {10, 20}};
        for (pair<int, int> &test : tests)
            cout << boolalpha << calendar->book(test.first, test.second) << "\n\n";
        delete (calendar);
        cout << "--------------------------------------------------------\n";
    }
    {
        calendar = new MyCalendarTwo();
        tests = {{10, 20}, {50, 60}, {10, 40}, {5, 15}, {5, 10}, {25, 55}};
        for (pair<int, int> &test : tests)
            cout << boolalpha << calendar->book(test.first, test.second) << "\n\n";
        delete (calendar);
        cout << "--------------------------------------------------------\n";
    }
}