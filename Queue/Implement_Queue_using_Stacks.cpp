/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.



Example 1:

Input
    ["MyQueue", "push", "push", "peek", "pop", "empty"]
    [[], [1], [2], [], [], []]
    Output
    [null, null, null, 1, 1, false]

    Explanation
        MyQueue myQueue = new MyQueue();
        myQueue.push(1); // queue is: [1]
        myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
        myQueue.peek(); // return 1
        myQueue.pop(); // return 1, queue is [2]
        myQueue.empty(); // return false



Constraints:

    * 1 <= x <= 9
    * At most 100 calls will be made to push, pop, peek, and empty.
    * All the calls to pop and peek are valid.



Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
*/

/*

 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();

*/

using namespace std;

#include <deque>
#include <iostream>
#include <vector>

class MyQueue
{
private:
    deque<int> fifo;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        fifo.push_back(x);
    }

    int pop()
    {
        int take = fifo.front();
        fifo.pop_front();
        return (take);
    }

    int peek()
    {
        int take = fifo.front();
        return (take);
    }

    bool empty()
    {
        if (fifo.empty())
            return (true);
        else
            return (false);
    }
};

int main()
{
    {
        MyQueue *obj = new MyQueue();
        cout << boolalpha << "is empty?\n"
             << obj->empty() << "\n";
        obj->push(5);
        obj->push(8);
        obj->push(2);
        obj->push(1);
        cout << "peeking = " << obj->peek() << "\n";
        cout << "popping = " << obj->pop() << "\n";
        cout << "peeking = " << obj->peek() << "\n";
        cout << "popping = " << obj->pop() << "\n";
        cout << boolalpha << "is empty?\n"
             << obj->empty() << "\n";
        delete obj;
    }
    {
        cout << "------------------------------------------------\n";
        MyQueue *myQueue = new MyQueue();
        myQueue->push(1);                                // queue is: [1]
        myQueue->push(2);                                // queue is: [1, 2] (leftmost is front of the queue)
        cout << "peeking = " << myQueue->peek() << "\n"; // return 1
        cout << "popping = " << myQueue->pop() << "\n";  // return 1, queue is [2]
        cout << boolalpha << "is empty?\n"
             << myQueue->empty() << "\n"; // return false
        delete myQueue;
    }
}