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

* 0 <= start < end <= 109
* At most 1000 calls will be made to book.
*/

// TODO ottimizzare struttura o con nodi o altri e capire come fare.(Codice funziona in teoria ma lento e inefficiente)

using namespace std;

#include <iostream>
#include <vector>

class MyCalendarTwo
{
private:
    class node
    {
        int count;
        node *left;
        node *right;
    };

    vector<node> Segment_Tree;
    vector<int> reset;

    bool clean_and_exit(void)
    {
        for (int node : reset)
            Segment_Tree[node]--;
        return (false);
    }

    bool range_found(int Treenode)
    {
        if (Segment_Tree[Treenode] <= 1)
        {
            reset.push_back(Treenode);
            Segment_Tree[Treenode]++;
        }
        else
            return (false);
        return (true);
    }

    bool create_tree(pair<int, int> range, const pair<int, int> &time, int Treenode = 1)
    {
        int mid = (range.first + range.second) / 2;
        int left = Treenode * 2;

        if (range.first >= time.first && range.second <= time.second)
            return (range_found(Treenode));
        else if (mid < time.first)
            return (create_tree({mid + 1, range.second}, time, left + 1));
        else if (mid > time.second)
            return (create_tree({range.first, mid}, time, left));
        else
        {
            if (!create_tree({range.first, mid}, time, left))
                return (false);
            if (!create_tree({mid + 1, range.second}, time, left + 1))
                return (clean_and_exit());

            return (true);
        }
    }

public:
    MyCalendarTwo()
    {
        Segment_Tree.clear();
        Segment_Tree.resize(1000 * 2, 0);
    }

    bool book(int startTime, int endTime)
    {
        reset.clear();
        return (create_tree({0, 1000000000}, {startTime, endTime}));
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */

int main()
{
    MyCalendarTwo *calendar = new MyCalendarTwo();

    cout << boolalpha << calendar->book(10, 20) << endl;
    /*  cout << boolalpha << calendar->book(50, 60) << endl;
     cout << boolalpha << calendar->book(5, 15) << endl;
     cout << boolalpha << calendar->book(5, 10) << endl;
     cout << boolalpha << calendar->book(25, 55) << endl; */
    delete (calendar);
}